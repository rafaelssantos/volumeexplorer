#include "tfdesignuicontroller.h"

#include <cmath>
#include <QMessageBox>
#include <QColorDialog>
#include "log_utils/logger.h"
#include "graphics_utils/rainbowscalegenerator.h"
#include "ui/common/screenshotfiledialog.h"
#include "ui/common/directoryfiledialog.h"
#include "ui/common/observerfiledialog.h"
#include "ui/common/tfdesignfiledialog.h"
#include "ui/rendering/renderinguicontroller.h"
#include "settings/tfsettingsuicontroller.h"
#include "attribute/attributeuicontroller.h"
#include "clustering/clusteringuicontroller.h"
#include "settings/tfsettings.h"

#include "tfdesignvieweruicontroller.h"
#include "volumeexplorer.h"


using namespace std;
using namespace settings;
using namespace graphics_utils;
using namespace log_utils;
using namespace transfer_function;




TFDesignUIController& TFDesignUIController::instance() {
    static TFDesignUIController instance;
	return instance;
}





void TFDesignUIController::updatePivots() {
    if(m_window.view()->items().count() > 0) {
        for(auto r = VolumeExplorer::instance().tfDesigner().pivots()->begin(); r != VolumeExplorer::instance().tfDesigner().pivots()->end(); r++){
            (*r)->ui()->setBorderWidth(TFSettings::instance().borderWidth());
        }
    }
	slotResize(m_window.view()->width(), m_window.view()->height());
}



void TFDesignUIController::setProgressBarVisible(bool visible) {
	m_window.progressBar()->setVisible(visible);
}



void TFDesignUIController::setProgressBarValue(int value) {
	m_window.progressBar()->setValue(value);
}



void TFDesignUIController::connecToRenderingUiController() {
	connect(&m_window, SIGNAL(signalShowRenderingWindow()), &RenderingUiController::instance(), SLOT(slotSetWindowVisible()));

}





TFDesignUIController::TFDesignUIController() {
	m_selectionMode = SelectionMode::PIVOT;
	m_curCluster = -1;
	m_curGroup = -1;
    m_curPivot = -1;

	init();
}





TFDesignUIController::~TFDesignUIController() {
}





void TFDesignUIController::init() {
	connect(&m_window, SIGNAL(signalClustering()), &ClusteringUiController::instance(), SLOT(slotExecDialog()));
    connect(&m_window, SIGNAL(signalAttributeExtraction()), &AttributeUiController::instance(), SLOT(slotExecDialog()));
	connect(&m_window, SIGNAL(signalSettingsDialog()), &TFSettingsUiController::instance(), SLOT(slotExecDialog()));

	connect(&m_window, SIGNAL(signalScreenshot()), this, SLOT(slotExecScreenshotDialog()));
	connect(&m_window, SIGNAL(signalScreenshotForCluster()), this, SLOT(slotExecScreenshotDialogForCluster()));
	connect(&m_window, SIGNAL(signalScreenshotForGroup()), this, SLOT(slotExecScreenshotDialogForGroup()));

	connect(&m_window, SIGNAL(signalUpdate()), this, SLOT(slotUpdate()));
	connect(&m_window, SIGNAL(signalGroup()), this, SLOT(slotGroup()));
	connect(&m_window, SIGNAL(signalUngroup()), this, SLOT(slotUngroup()));
	connect(&m_window, SIGNAL(signalRestoreColor()), this, SLOT(slotResetColor()));
	connect(&m_window, SIGNAL(signalRestorePos()), this, SLOT(slotResetObserver()));
	connect(&m_window, SIGNAL(signalUnselectAll()), this, SLOT(slotUnselectAll()));
    connect(&m_window, SIGNAL(signalSelectionModeChanged(transfer_function::SelectionMode)), this, SLOT(slotSelectionMode(transfer_function::SelectionMode)));

	connect(&m_window, SIGNAL(signalLeft()), this, SLOT(slotPrevious()));
	connect(&m_window, SIGNAL(signalRight()), this, SLOT(slotNext()));

	connect(&m_window, SIGNAL(signalSaveViewerPos()), this, SLOT(slotSaveObserverPos()));
	connect(&m_window, SIGNAL(signalLoadViewerPos()), this, SLOT(slotLoadObserver()));

	connect(&m_window, SIGNAL(signalSaveTFDesign()), this, SLOT(slotSaveTFDesign()));
	connect(&m_window, SIGNAL(signalLoadTFDesign()), this, SLOT(slotLoadTFDesign()));

	connect(&m_window, SIGNAL(signalBenchmarkEnabled(bool)), this, SLOT(slotBenchmarkEnabled(bool)));
	connect(&m_window, SIGNAL(signalShowLogWindow()), this, SLOT(slotSetBenchmarkWindowVisible()));

    connect(&m_window, SIGNAL(signalZoom(graphics_utils::Zoom)), this, SLOT(slotZoom(graphics_utils::Zoom)));
	connect(&m_window, SIGNAL(signalColorChoose()), this, SLOT(slotSelectColor()));
	connect(m_window.view(), SIGNAL(signalSizeChanged(int, int)), this, SLOT(slotResize(int, int)));
	connect(&ClusteringUiController::instance(), SIGNAL(signalClustered()), this, SLOT(slotPlot()));
}



void TFDesignUIController::drawSelectRegion() {
	QVector<QPointF> points;

	for (auto i = 0; i < m_window.view()->scene()->selectedItems().size(); i++){
		points << QPointF(m_window.view()->scene()->selectedItems().at(i)->boundingRect().x() + m_window.view()->scene()->selectedItems().at(i)->boundingRect().width() / 2, m_window.view()->scene()->selectedItems().at(i)->boundingRect().y() + m_window.view()->scene()->selectedItems().at(i)->boundingRect().width() / 2);
	}

	QPolygonF polygon(points);
	m_selectionRegion.setPolygon(polygon);
    m_selectionRegion.pen().setColor(QColor(200, 200, 200, TFSettings::instance().baseOpacity()));

	m_selectionRegion.setZValue(-1);
}






void TFDesignUIController::slotSetWindowVisible(bool visible) {
	m_window.setVisible(visible);
}





void TFDesignUIController::slotUpdate() {
	m_window.view()->update();
}




void TFDesignUIController::slotExecScreenshotDialog() {
	ScreenshotFileDialog dialog;

	connect(&dialog, SIGNAL(signalAccepted(QString)), this, SLOT(slotExportScreenshot(QString)));

	dialog.exec();
}





void TFDesignUIController::slotExecScreenshotDialogForCluster() {
	DirectotyFileDialog dialog;

	connect(&dialog, SIGNAL(signalAccepted(QString)), this, SLOT(slotExportScreenshots(QString)));

	m_isScreenshotOfClusters = true;
	dialog.exec();
}



void TFDesignUIController::slotExecScreenshotDialogForGroup() {
	DirectotyFileDialog dialog;

	connect(&dialog, SIGNAL(signalAccepted(QString)), this, SLOT(slotExportScreenshots(QString)));

	m_isScreenshotOfClusters = false;
	dialog.exec();
}



void TFDesignUIController::slotUnselectAll() {
	if(m_window.view()->items().count() > 0) {
		m_window.view()->scene()->removeItem(&m_selectionRegion);

		VolumeExplorer::instance().tfDesigner().unselectAll();
		RenderingUiController::instance().slotUpdate();
	}

	m_curCluster = -1;
	m_curGroup = -1;
}



void TFDesignUIController::slotErasePlot() {
	m_zoomFactor = 1.0;
	m_window.view()->update();
	m_window.view()->scene()->clear();


	m_window.labelClusterCount()->setText(QString::fromStdString(""));

	m_curCluster = -1;
	m_curGroup = -1;

	slotUpdate();

}





void TFDesignUIController::slotPlot() {
	slotErasePlot();

	for(auto r = VolumeExplorer::instance().tfDesigner().pivots()->begin(); r != VolumeExplorer::instance().tfDesigner().pivots()->end(); r++){
		m_window.view()->scene()->addItem((*r)->ui());
		connect((*r)->ui(), SIGNAL(signalSelect(bool, int)), this, SLOT(slotSelect(bool, int)));
	}

	string clusterCount = "Cluster Count: " + to_string(VolumeExplorer::instance().tfDesigner().clusterCount());
	m_window.labelClusterCount()->setText(QString::fromStdString(clusterCount));

	slotResize(m_window.view()->width(), m_window.view()->height());
	slotResetColor();
}




void TFDesignUIController::slotExportScreenshot(QString path) {
	m_window.view()->grab().save(path);
}




void TFDesignUIController::slotExportScreenshots(QString path) {
	if(m_isScreenshotOfClusters){
		for(auto i  = 0u; i < VolumeExplorer::instance().tfDesigner().clusterCount(); i++){
			VolumeExplorer::instance().tfDesigner().unselectAll();
			VolumeExplorer::instance().tfDesigner().setSelectedCluster(i);

			slotExportScreenshot(path + "/transfer_func_cluster_" + QString::number(i) + ".png");

			RenderingUiController::instance().slotUpdate();
			RenderingUiController::instance().slotExportScreenshot(path + "/rendering_cluster_" + QString::number(i) + ".png");

			VolumeExplorer::instance().tfDesigner().unselectAll();
			RenderingUiController::instance().slotUpdate();
		}
	}
	else{
		for(auto i  = 0u; i < VolumeExplorer::instance().tfDesigner().groupCount(); i++){
			VolumeExplorer::instance().tfDesigner().unselectAll();
			VolumeExplorer::instance().tfDesigner().setSelectedGroup(i);

			slotExportScreenshot(path + "/transfer_func_group_" + QString::number(i) + ".png");

			RenderingUiController::instance().slotUpdate();
			RenderingUiController::instance().slotExportScreenshot(path + "/rendering_group_" + QString::number(i) + ".png");
		}

		VolumeExplorer::instance().tfDesigner().unselectAll();
		RenderingUiController::instance().slotUpdate();
	}
}





void TFDesignUIController::slotResize(int width, int height) {
	if(m_window.view()->items().count() > 0) {
        float minVoxelCountPerPivot = numeric_limits<float>::max();
        float maxVoxelCountPerPivot = -1;
		float2 min = VolumeExplorer::instance().tfDesigner().pivots()->front()->ui()->basePos();
		float2 max = VolumeExplorer::instance().tfDesigner().pivots()->front()->ui()->basePos();

		for(auto r = VolumeExplorer::instance().tfDesigner().pivots()->begin(); r != VolumeExplorer::instance().tfDesigner().pivots()->end(); r++){
			if ((*r)->ui()->basePos().x > max.x) {
				max.x = (*r)->ui()->basePos().x;
			}
			if ((*r)->ui()->basePos().x < min.x) {
				min.x = (*r)->ui()->basePos().x;
			}
			if ((*r)->ui()->basePos().y > max.y) {
				max.y = (*r)->ui()->basePos().y;
			}
			if ((*r)->ui()->basePos().y < min.y) {
				min.y = (*r)->ui()->basePos().y;
			}
            if((*r)->voxelIndices()->size() < minVoxelCountPerPivot){
                minVoxelCountPerPivot = (*r)->voxelIndices()->size();
            }
            if((*r)->voxelIndices()->size() > maxVoxelCountPerPivot){
                maxVoxelCountPerPivot = (*r)->voxelIndices()->size();
            }
		}

        float maxDiameter = (sqrt(maxVoxelCountPerPivot /  minVoxelCountPerPivot)) * (TFSettings::instance().scaleDiameter() / 2) + TFSettings::instance().minDiameter();
        float viewMinSize = fminf((width - maxDiameter - 2.0f * TFSettings::instance().borderWidth()) * m_zoomFactor, (height - maxDiameter - 2.0f * TFSettings::instance().borderWidth()) * m_zoomFactor);
		float maxDistance = fmaxf(max.x - min.x, max.y - min.y);
		float scaleFactor = maxDistance != 0.0f ? (viewMinSize / maxDistance) : (viewMinSize);


		for(auto r = VolumeExplorer::instance().tfDesigner().pivots()->begin(); r != VolumeExplorer::instance().tfDesigner().pivots()->end(); r++){
			float2 pos;
			pos.x = ((*r)->ui()->basePos().x - min.x) * scaleFactor;
			pos.y = ((*r)->ui()->basePos().y - min.y) * scaleFactor;

            float diameter = (sqrt((*r)->voxelIndices()->size() /  minVoxelCountPerPivot)) * (TFSettings::instance().scaleDiameter() / 2) + TFSettings::instance().minDiameter();

            (*r)->ui()->setRect(pos.x, pos.y, diameter, diameter);
        }

		m_window.view()->setSceneRect(m_window.view()->scene()->itemsBoundingRect());

		slotUpdate();
	}
}




void TFDesignUIController::slotZoom(Zoom zoom) {
	if(zoom == Zoom::IN) {
        m_zoomFactor += TFSettings::instance().zoomIncrement();
	}
	else{
        m_zoomFactor -= TFSettings::instance().zoomIncrement();
		if(m_zoomFactor < 0){
			m_zoomFactor = 0;
		}
	}

	slotResize(m_window.view()->width(), m_window.view()->height());
}




void TFDesignUIController::slotSelect(bool selected, int index) {
	VolumeExplorer::instance().tfDesigner().setSelected(m_selectionMode, selected, index);

//	m_window.view()->scene()->removeItem(&m_selectionRegion);
//	drawSelectRegion();
//	m_window.view()->scene()->addItem(&m_selectionRegion);


	RenderingUiController::instance().slotUpdate();
}




void TFDesignUIController::slotSelectionMode(SelectionMode selectionMode) {
	m_selectionMode = selectionMode;
	m_curCluster = -1;
	m_curGroup = -1;
}




void TFDesignUIController::slotGroup() {
	VolumeExplorer::instance().tfDesigner().group();
}




void TFDesignUIController::slotUngroup() {
	VolumeExplorer::instance().tfDesigner().ungroup();
}





void TFDesignUIController::slotNext() {
	if(m_window.view()->items().count() > 0) {
		VolumeExplorer::instance().tfDesigner().unselectAll();

        if(m_selectionMode == SelectionMode::PIVOT){
            m_curPivot++;
            if(m_curPivot >= static_cast<int>(VolumeExplorer::instance().tfDesigner().pivotCount())){
                m_curPivot = 0;
            }
            if(VolumeExplorer::instance().tfDesigner().pivotCount() > 0) {
                VolumeExplorer::instance().tfDesigner().pivots()->at(m_curPivot)->ui()->setSelected(true, false);               RenderingUiController::instance().slotUpdate();
            }
        }
        else if(m_selectionMode == SelectionMode::CLUSTER){
			m_curCluster++;
			if(m_curCluster >= static_cast<int>(VolumeExplorer::instance().tfDesigner().clusterCount())){
				m_curCluster = 0;
			}
			if(VolumeExplorer::instance().tfDesigner().clusterCount() > 0) {
				VolumeExplorer::instance().tfDesigner().setSelectedCluster(m_curCluster);
				RenderingUiController::instance().slotUpdate();
			}
		}
		else if(m_selectionMode == SelectionMode::GROUP){
			m_curGroup++;
			if(m_curGroup >= static_cast<int>(VolumeExplorer::instance().tfDesigner().groupCount())){
				m_curGroup = 0;
			}
			if(VolumeExplorer::instance().tfDesigner().groupCount() > 0) {
				VolumeExplorer::instance().tfDesigner().setSelectedGroup(m_curGroup);
				RenderingUiController::instance().slotUpdate();
			}
		}
	}
}



void TFDesignUIController::slotPrevious() {
	if(m_window.view()->items().count() > 0) {
		VolumeExplorer::instance().tfDesigner().unselectAll();

        if(m_selectionMode == SelectionMode::PIVOT){
            m_curPivot--;
            if(m_curPivot < 0){
                m_curPivot = 0;
            }
            if(VolumeExplorer::instance().tfDesigner().pivotCount() > 0) {
                VolumeExplorer::instance().tfDesigner().pivots()->at(m_curPivot)->ui()->setSelected(true, false);               RenderingUiController::instance().slotUpdate();
            }
        }
        else if(m_selectionMode == SelectionMode::CLUSTER){
			m_curCluster--;
			if(m_curCluster < 0){
				m_curCluster = static_cast<int>(VolumeExplorer::instance().tfDesigner().clusterCount()) -1;
			}
			if(VolumeExplorer::instance().tfDesigner().clusterCount() > 0) {
				VolumeExplorer::instance().tfDesigner().setSelectedCluster(m_curCluster);
				RenderingUiController::instance().slotUpdate();
			}
		}
		else if(m_selectionMode == SelectionMode::GROUP) {
			m_curGroup--;
			if(m_curGroup < 0){
				m_curGroup = static_cast<int>(VolumeExplorer::instance().tfDesigner().groupCount()) -1;
			}
			if(VolumeExplorer::instance().tfDesigner().groupCount() > 0) {
				VolumeExplorer::instance().tfDesigner().setSelectedGroup(m_curGroup);
				RenderingUiController::instance().slotUpdate();
			}
		}
	}
}



void TFDesignUIController::slotLoadTFDesignAccepted(string path) {
	VolumeExplorer::instance().tfDesigner().loadTFDesign(path);
	slotUpdate();
}




void TFDesignUIController::slotLoadTFDesign() {
	TFDesignFileDialog dialog;

	connect(&dialog, SIGNAL(signalAccepted(std::string)), this, SLOT(slotLoadTFDesignAccepted(std::string)));
	dialog.setAcceptMode(TFDesignFileDialog::AcceptOpen);
	dialog.exec();
}




void TFDesignUIController::slotSaveTFDesignAccepted(string path) {
	VolumeExplorer::instance().tfDesigner().saveTFDesign(path);
}



void TFDesignUIController::slotSaveTFDesign() {
	TFDesignFileDialog dialog;

	connect(&dialog, SIGNAL(signalAccepted(std::string)), this, SLOT(slotSaveTFDesignAccepted(std::string)));
	dialog.setAcceptMode(TFDesignFileDialog::AcceptSave);
	dialog.exec();
}




void TFDesignUIController::slotLoadObserverAccepted(string path) {
    m_zoomFactor =  TFDesignViewerUIController::instance().load(path);
	slotResize(m_window.view()->width(), m_window.view()->height());
}



void TFDesignUIController::slotLoadObserver() {
	ObserverFileDialog dialog;

	connect(&dialog, SIGNAL(signalAccepted(std::string)), this, SLOT(slotLoadObserverAccepted(std::string)));
	dialog.setAcceptMode(ObserverFileDialog::AcceptOpen);
	dialog.exec();
}




void TFDesignUIController::slotSaveObserverAccepted(string path) {
    TFDesignViewerUIController::instance().save(path, m_zoomFactor);
}


void TFDesignUIController::slotSaveObserverPos() {
	ObserverFileDialog dialog;

	connect(&dialog, SIGNAL(signalAccepted(std::string)), this, SLOT(slotSaveObserverAccepted(std::string)));
	dialog.setAcceptMode(ObserverFileDialog::AcceptSave);
	dialog.exec();
}





void TFDesignUIController::slotBenchmarkEnabled(bool enabled) {
	if(enabled) {
		Logger::instance().setRepeatCount(5);
	}
	else{
		Logger::instance().setRepeatCount(1);
	}
}



void TFDesignUIController::slotSetBenchmarkWindowVisible(bool visible) {
	Logger::instance().setWindowVisible(visible);
}






void TFDesignUIController::slotResetColor() {
	if(m_window.view()->items().count() > 0) {
		float4 clusterColor;
		int clusterCount;

		clusterCount = static_cast<int>(VolumeExplorer::instance().tfDesigner().clusterCount());

		for (auto i = 0; i < clusterCount; i++){
            clusterColor = RainbowScaleGenerator::instance().colorAt(i, clusterCount, TFSettings::instance().baseOpacity());

			VolumeExplorer::instance().tfDesigner().setClusterColor(i, clusterColor);
		}
	}
	RenderingUiController::instance().slotUpdate();

	slotUpdate();
}




void TFDesignUIController::slotResetObserver() {
	m_zoomFactor = 1.0;
	slotResize(m_window.view()->width(), m_window.view()->height());
}





void TFDesignUIController::slotSelectColor() {
	if(m_window.view()->items().count() > 0){
		QColorDialog dialog;
		dialog.setOption(QColorDialog::DontUseNativeDialog);

		connect(&dialog, SIGNAL(colorSelected(QColor)), this, SLOT(slotColorSelected(QColor)));

		dialog.exec();
	}
}



void TFDesignUIController::slotColorSelected(const QColor& color) {
	float4 floatColor;

	floatColor.x = static_cast<float>(color.redF());
	floatColor.y = static_cast<float>(color.greenF());
	floatColor.z = static_cast<float>(color.blueF());
	floatColor.w = static_cast<float>(color.alphaF());

	VolumeExplorer::instance().tfDesigner().setSelectedColor(floatColor);
	RenderingUiController::instance().slotUpdate();
}
