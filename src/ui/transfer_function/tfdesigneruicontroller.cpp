#include "tfdesigneruicontroller.h"

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
#include "transfer_function/tfdesigner.h"
#include "tfdesignerviewmanager.h"
#include "volumeexplorer.h"


using namespace std;
using namespace settings;
using namespace graphics_utils;
using namespace log_utils;
using namespace transfer_function;




TFDesignerUIController& TFDesignerUIController::instance() {
	static TFDesignerUIController instance;
	return instance;
}





void TFDesignerUIController::updatePivots() {
	if(m_window.view()->items().count() > 0) {
		for(auto r = TFDesigner::instance().pivots()->begin(); r != TFDesigner::instance().pivots()->end(); r++){
			(*r)->ui()->setBorderWidth(TFSettings::instance().pivotBorderWidth());
		}
	}
	slotResize(m_window.view()->width(), m_window.view()->height());
}



void TFDesignerUIController::setProgressBarVisible(bool visible) {
	m_window.progressBar()->setVisible(visible);
}



void TFDesignerUIController::setProgressBarValue(int value) {
	m_window.progressBar()->setValue(value);
}



void TFDesignerUIController::connecToRenderingUIController() {
	connect(&m_window, SIGNAL(signalShowRenderingWindow()), &RenderingUIController::instance(), SLOT(slotSetWindowVisible()));

}





TFDesignerUIController::TFDesignerUIController() {
	m_pivotMaxChildrenCount = 0;
	m_pivotMinChildrenCount = 0;
	m_maxDistPivot = 0;
	m_selectionMode = SelectionMode::PIVOT;
	m_curCluster = -1;
	m_curGroup = -1;
	m_curPivot = -1;

	init();
}





TFDesignerUIController::~TFDesignerUIController() {
}





void TFDesignerUIController::init() {
	connect(&m_window, SIGNAL(signalClustering()), &ClusteringUIController::instance(), SLOT(slotExecDialog()));
    connect(&m_window, SIGNAL(signalFeaturesExtraction()), &AttributeUIController::instance(), SLOT(slotExecAttributeDialog()));
	connect(&m_window, SIGNAL(signalSettingsDialog()), &TFSettingsUiController::instance(), SLOT(slotExecDialog()));

	connect(&m_window, SIGNAL(signalScreenshot()), this, SLOT(slotExecScreenshotDialog()));
	connect(&m_window, SIGNAL(signalScreenshotForPivots()), this, SLOT(slotExecScreenshotDialogForPivots()));
	connect(&m_window, SIGNAL(signalScreenshotForClusters()), this, SLOT(slotExecScreenshotDialogForClusters()));
	connect(&m_window, SIGNAL(signalScreenshotForGroups()), this, SLOT(slotExecScreenshotDialogForGroups()));

	connect(&m_window, SIGNAL(signalUpdate()), this, SLOT(slotUpdate()));
	connect(&m_window, SIGNAL(signalGroup()), this, SLOT(slotGroup()));
	connect(&m_window, SIGNAL(signalUngroup()), this, SLOT(slotUngroup()));
	connect(&m_window, SIGNAL(signalRestoreColor()), this, SLOT(slotResetColor()));
	connect(&m_window, SIGNAL(signalRestorePos()), this, SLOT(slotResetObserver()));
	connect(&m_window, SIGNAL(signalUnselectAll()), this, SLOT(slotUnselectAll()));
	connect(&m_window, SIGNAL(signalSelectionModeChanged(transfer_function::SelectionMode)), this, SLOT(slotSelectionMode(transfer_function::SelectionMode)));

	connect(&m_window, SIGNAL(signalLeft()), this, SLOT(slotPrevious()));
	connect(&m_window, SIGNAL(signalRight()), this, SLOT(slotNext()));

	connect(&m_window, SIGNAL(signalShowLogWindow()), this, SLOT(slotSetLogWindowVisible()));

	connect(&m_window, SIGNAL(signalZoom(graphics_utils::Zoom)), this, SLOT(slotZoom(graphics_utils::Zoom)));
	connect(&m_window, SIGNAL(signalColorChoose()), this, SLOT(slotSelectColor()));
	connect(m_window.view(), SIGNAL(signalSizeChanged(int, int)), this, SLOT(slotResize(int, int)));
	connect(&ClusteringUIController::instance(), SIGNAL(signalClustered()), this, SLOT(slotPlot()));
}





void TFDesignerUIController::pivotsLimitsCalc() {
	if(m_window.view()->items().count() > 0) {
		m_pivotMinChildrenCount = numeric_limits<float>::max();
		m_pivotMaxChildrenCount = numeric_limits<float>::min();
		float2 min = TFDesigner::instance().pivots()->front()->ui()->basePos();
		float2 max = TFDesigner::instance().pivots()->front()->ui()->basePos();

		for(auto r = TFDesigner::instance().pivots()->begin(); r != TFDesigner::instance().pivots()->end(); r++){
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
			if((*r)->voxelIndices()->size() < m_pivotMinChildrenCount){
				m_pivotMinChildrenCount = (*r)->voxelIndices()->size();
			}
			if((*r)->voxelIndices()->size() > m_pivotMaxChildrenCount){
				m_pivotMaxChildrenCount = (*r)->voxelIndices()->size();
			}
		}

		m_maxDistPivot = fmaxf(max.x - min.x, max.y - min.y);
	}
}










void TFDesignerUIController::slotSetWindowVisible(bool visible) {
	m_window.setVisible(visible);
}





void TFDesignerUIController::slotUpdate() {
	m_window.view()->update();
}




void TFDesignerUIController::slotExecScreenshotDialog() {
	ScreenshotFileDialog dialog;

    connect(&dialog, SIGNAL(signalAccepted(QString)), this, SLOT(slotScreenshot(QString)));

	dialog.exec();
}



void TFDesignerUIController::slotExecScreenshotDialogForPivots() {
	DirectotyFileDialog dialog;

    connect(&dialog, SIGNAL(signalAccepted(QString)), this, SLOT(slotPivotScreenshot(QString)));

	dialog.exec();
}





void TFDesignerUIController::slotExecScreenshotDialogForClusters() {
	DirectotyFileDialog dialog;

    connect(&dialog, SIGNAL(signalAccepted(QString)), this, SLOT(slotClusterScreenshot(QString)));

	dialog.exec();
}



void TFDesignerUIController::slotExecScreenshotDialogForGroups() {
	DirectotyFileDialog dialog;

    connect(&dialog, SIGNAL(signalAccepted(QString)), this, SLOT(slotGroupScreenshot(QString)));

	dialog.exec();
}



void TFDesignerUIController::slotUnselectAll() {
	TFDesigner::instance().unselectAll();
	RenderingUIController::instance().slotUpdate();

	m_curCluster = -1;
	m_curGroup = -1;
}



void TFDesignerUIController::slotErasePlot() {
	m_zoomFactor = 1.0;
	m_window.view()->update();
	m_window.view()->scene()->clear();


	m_window.labelSatus()->setText(QString::fromStdString(""));

	m_curCluster = -1;
	m_curGroup = -1;

	slotUpdate();

}





void TFDesignerUIController::slotPlot() {
	slotErasePlot();

	for(auto r = TFDesigner::instance().pivots()->begin(); r != TFDesigner::instance().pivots()->end(); r++){
		m_window.view()->scene()->addItem((*r)->ui());
		connect((*r)->ui(), SIGNAL(signalSelect(bool, int)), this, SLOT(slotSelect(bool, int)));
	}

	pivotsLimitsCalc();

	string status = "Clusters: " + to_string(TFDesigner::instance().clusterCount()) + " | ";
	status += "Pivots: " + to_string(TFDesigner::instance().pivotCount());
	m_window.labelSatus()->setText(QString::fromStdString(status));

	slotResize(m_window.view()->width(), m_window.view()->height());
	slotResetColor();
}




void TFDesignerUIController::slotScreenshot(QString path) {
	m_window.view()->grab().save(path);
}





void TFDesignerUIController::slotPivotScreenshot(QString path) {
    TFDesigner::instance().unselectAll();
    slotScreenshot(path + "/tf_overview.png");

	for(auto i  = 0; i < TFDesigner::instance().pivotCount(); i++){
		TFDesigner::instance().unselectAll();
		TFDesigner::instance().setSelectedPivot(i);

		slotScreenshot(path + "/tf_pivot_" + QString::number(i) + ".png");

		RenderingUIController::instance().slotExportScreenshot(path + "/rendering_pivot_" + QString::number(i) + ".png");
	}
    Logger::instance().saveToFile(path +"/rendering.log");

	TFDesigner::instance().unselectAll();
	RenderingUIController::instance().slotUpdate();
}





void TFDesignerUIController::slotClusterScreenshot(QString path) {
    TFDesigner::instance().unselectAll();
    slotScreenshot(path + "/tf_overview.png");

	for(auto i  = 0; i < TFDesigner::instance().clusterCount(); i++){
		TFDesigner::instance().unselectAll();
		TFDesigner::instance().setSelectedCluster(i);

		slotScreenshot(path + "/tf_cluster_" + QString::number(i) + ".png");

        RenderingUIController::instance().slotExportScreenshot(path + "/rendering_cluster_" + QString::number(i) + ".png");
	}
    Logger::instance().saveToFile(path +"/rendering.log");

	TFDesigner::instance().unselectAll();
	RenderingUIController::instance().slotUpdate();
}




void TFDesignerUIController::slotGroupScreenshot(QString path) {
    TFDesigner::instance().unselectAll();
    slotScreenshot(path + "/tf_overview.png");

    for(auto i  = 0; i < TFDesigner::instance().groupCount(); i++){
		TFDesigner::instance().unselectAll();
		TFDesigner::instance().setSelectedGroup(i);

		slotScreenshot(path + "/tf_group_" + QString::number(i) + ".png");

		RenderingUIController::instance().slotExportScreenshot(path + "/rendering_group_" + QString::number(i) + ".png");
	}
    Logger::instance().saveToFile(path +"/rendering.log");

	TFDesigner::instance().unselectAll();
	RenderingUIController::instance().slotUpdate();
}





void TFDesignerUIController::slotResize(int width, int height) {
	if(m_window.view()->items().count() > 0) {
		float maxDiameter = log10f(m_pivotMaxChildrenCount /  m_pivotMinChildrenCount) * TFSettings::instance().pivotSize();
		float viewMinSize = fminf((width - maxDiameter - 2.0f * TFSettings::instance().pivotBorderWidth()) * m_zoomFactor, (height - maxDiameter - 2.0f * TFSettings::instance().pivotBorderWidth()) * m_zoomFactor);
		float scaleFactor = m_maxDistPivot != 0.0f ? (viewMinSize / m_maxDistPivot) : (viewMinSize);


		for(auto p = TFDesigner::instance().pivots()->begin(); p != TFDesigner::instance().pivots()->end(); p++){
			float diameter = log10f((*p)->voxelIndices()->size() /  m_pivotMinChildrenCount) * TFSettings::instance().pivotSize();

			float2 pos;

			pos.x = (*p)->ui()->basePos().x * scaleFactor + maxDiameter / 2.0f - diameter / 2.0f;
			pos.y = (*p)->ui()->basePos().y * scaleFactor + maxDiameter / 2.0f - diameter / 2.0f;

			(*p)->ui()->setRect(pos.x, pos.y, diameter, diameter);
		}

		m_window.view()->setSceneRect(m_window.view()->scene()->itemsBoundingRect());

		slotUpdate();
	}
}




void TFDesignerUIController::slotZoom(Zoom zoom) {
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




void TFDesignerUIController::slotSelect(bool selected, int index) {
	TFDesigner::instance().setSelected(m_selectionMode, selected, index);


	RenderingUIController::instance().slotUpdate();
}




void TFDesignerUIController::slotSelectionMode(SelectionMode selectionMode) {
	m_selectionMode = selectionMode;
	m_curCluster = -1;
	m_curGroup = -1;
}




void TFDesignerUIController::slotGroup() {
	TFDesigner::instance().group();
}




void TFDesignerUIController::slotUngroup() {
	TFDesigner::instance().ungroup();
}





void TFDesignerUIController::slotNext() {
	if(m_window.view()->items().count() > 0) {
		TFDesigner::instance().unselectAll();

		if(m_selectionMode == SelectionMode::PIVOT){
			m_curPivot++;
			if(m_curPivot >= static_cast<int>(TFDesigner::instance().pivotCount())){
				m_curPivot = 0;
			}
			if(TFDesigner::instance().pivotCount() > 0) {
                TFDesigner::instance().pivots()->at(m_curPivot)->ui()->setSelected(true, false);
                RenderingUIController::instance().slotUpdate();
			}
		}
		else if(m_selectionMode == SelectionMode::CLUSTER){
			m_curCluster++;
			if(m_curCluster >= static_cast<int>(TFDesigner::instance().clusterCount())){
				m_curCluster = 0;
			}
			if(TFDesigner::instance().clusterCount() > 0) {
				TFDesigner::instance().setSelectedCluster(m_curCluster);
				RenderingUIController::instance().slotUpdate();
			}
		}
		else if(m_selectionMode == SelectionMode::GROUP){
			m_curGroup++;
			if(m_curGroup >= static_cast<int>(TFDesigner::instance().groupCount())){
				m_curGroup = 0;
			}
			if(TFDesigner::instance().groupCount() > 0) {
				TFDesigner::instance().setSelectedGroup(m_curGroup);
				RenderingUIController::instance().slotUpdate();
			}
		}
	}
}



void TFDesignerUIController::slotPrevious() {
	if(m_window.view()->items().count() > 0) {
		TFDesigner::instance().unselectAll();

		if(m_selectionMode == SelectionMode::PIVOT){
			m_curPivot--;
			if(m_curPivot < 0){
				m_curPivot = 0;
			}
			if(TFDesigner::instance().pivotCount() > 0) {
				TFDesigner::instance().pivots()->at(m_curPivot)->ui()->setSelected(true, false);               RenderingUIController::instance().slotUpdate();
			}
		}
		else if(m_selectionMode == SelectionMode::CLUSTER){
			m_curCluster--;
			if(m_curCluster < 0){
				m_curCluster = static_cast<int>(TFDesigner::instance().clusterCount()) -1;
			}
			if(TFDesigner::instance().clusterCount() > 0) {
				TFDesigner::instance().setSelectedCluster(m_curCluster);
				RenderingUIController::instance().slotUpdate();
			}
		}
		else if(m_selectionMode == SelectionMode::GROUP) {
			m_curGroup--;
			if(m_curGroup < 0){
				m_curGroup = static_cast<int>(TFDesigner::instance().groupCount()) -1;
			}
			if(TFDesigner::instance().groupCount() > 0) {
				TFDesigner::instance().setSelectedGroup(m_curGroup);
				RenderingUIController::instance().slotUpdate();
			}
		}
	}
}





void TFDesignerUIController::slotSetLogWindowVisible(bool visible) {
	Logger::instance().setWindowVisible(visible);
}






void TFDesignerUIController::slotResetColor() {
	if(m_window.view()->items().count() > 0) {
		float4 clusterColor;
		int clusterCount;

		clusterCount = static_cast<int>(TFDesigner::instance().clusterCount());

		for (auto i = 0; i < clusterCount; i++){
			clusterColor = RainbowScaleGenerator::instance().colorAt(i, clusterCount, TFSettings::instance().baseOpacity());

			TFDesigner::instance().setClusterColor(i, clusterColor);
		}
	}
	RenderingUIController::instance().slotUpdate();

	slotUpdate();
}




void TFDesignerUIController::slotResetObserver() {
	m_zoomFactor = 1.0;
	slotResize(m_window.view()->width(), m_window.view()->height());
}





void TFDesignerUIController::slotSelectColor() {
	if(m_window.view()->items().count() > 0){
		QColorDialog dialog;
		dialog.setOption(QColorDialog::DontUseNativeDialog);

		connect(&dialog, SIGNAL(colorSelected(QColor)), this, SLOT(slotColorSelected(QColor)));

		dialog.exec();
	}
}



void TFDesignerUIController::slotColorSelected(const QColor& color) {
	float4 floatColor;

	floatColor.x = static_cast<float>(color.redF());
	floatColor.y = static_cast<float>(color.greenF());
	floatColor.z = static_cast<float>(color.blueF());
	floatColor.w = static_cast<float>(color.alphaF());

	TFDesigner::instance().setSelectedColor(floatColor);
	RenderingUIController::instance().slotUpdate();
}
