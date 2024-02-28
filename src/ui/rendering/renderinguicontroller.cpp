#include "renderinguicontroller.h"


#include <QString>
#include "datasetfiledialog.h"
#include "settings/renderingsettingsuicontroller.h"
#include "log_utils/logger.h"
#include "ui/common/screenshotfiledialog.h"
#include "ui/transfer_function/tfdesigneruicontroller.h"
#include "voxeldialog.h"
#include "volumeexplorer.h"
#include "settings/renderingsettings.h"



using namespace log_utils;
using namespace graphics_utils;
using namespace std;
using namespace settings;



RenderingUIController& RenderingUIController::instance() {
	static RenderingUIController instance;

	return instance;
}



void RenderingUIController::connecToFeatureUiController() {
	connect(&m_window, SIGNAL(signalTFDesigner(bool)), &TFDesignerUIController::instance(), SLOT(slotSetWindowVisible(bool)));
}





void RenderingUIController::slotRegisterGlPBOAsResource(GLuint pbo) {
	VolumeExplorer::instance().registerGlPBOAsCudaResource(pbo);
}





void RenderingUIController::slotUnregisterGlPBOAsResource() {
	VolumeExplorer::instance().unregisterGlPBOAsCudaResource();
}





void RenderingUIController::slotSetWindowVisible(bool visible) {
	m_window.setVisible(visible);
}





void RenderingUIController::slotExecOpenDatasetDialog() {
	RenderingSettingsUiController::instance().slotLoadSettingsToCore();


	DatasetFileDialog fileDialog;

	connect(&fileDialog, SIGNAL(signalAccepted(std::list<std::string>,std::string)), this, SLOT(slotSetDatasetFilesPath(std::list<std::string>, std::string)));

	if (fileDialog.exec()) {
        VoxelDialog voxelDialog;
        voxelDialog.setDirPath(m_dirPath);

        connect(&voxelDialog, SIGNAL(signalAccepted(float, float, float)), this, SLOT(slotSetVolumeSpacing(float, float, float)));

        if (voxelDialog.exec()) {
            string datasetDescript = VolumeExplorer::instance().loadDataset(m_datasetFilesPath, m_volumeSpacingX, m_volumeSpacingY, m_volumeSpacingZ);
			m_window.labelInfo()->setText(QString::fromStdString(datasetDescript));

			Logger::instance().appendMessage("DATASET\n" + datasetDescript + "\n");

			TFDesignerUIController::instance().slotErasePlot();
			if(VolumeExplorer::instance().isDatasetLoaded()){
				TFDesignerUIController::instance().slotSetWindowVisible(true);
			}

            slotUpdate();
		}
	}
}









void RenderingUIController::slotExecScreenshotDialog() {
	ScreenshotFileDialog dialog;

    connect(&dialog, SIGNAL(signalAccepted(QString)), this, SLOT(slotExportScreenshot(QString)));
	dialog.exec();
}




void RenderingUIController::slotExportScreenshot(QString path) {
    bool hqEnabled = RenderingSettings::instance().HQEnabled();

    RenderingSettings::instance().setHQEnabled(true);
    slotUpdate();
    cudaDeviceSynchronize();
    m_window.renderingWidget()->grabFramebuffer().save(path);
    RenderingSettings::instance().setHQEnabled(hqEnabled);
}





void RenderingUIController::slotZoom(Zoom zoom) {
	VolumeExplorer::instance().zoom(zoom);
    slotUpdate();
}





void RenderingUIController::slotUpdate() {
    m_window.renderingWidget()->update();
}


void RenderingUIController::slotRotate(RotationAxis axis, graphics_utils::RotationSense sense) {
	VolumeExplorer::instance().rotate(axis, sense);
}




void RenderingUIController::slotResetViewer() {
	VolumeExplorer::instance().resetViewer();
    slotUpdate();
}





void RenderingUIController::slotSetDatasetFilesPath(std::list<std::string> filesPath, std::string dirPath) {
	m_datasetFilesPath = filesPath;
	m_dirPath = dirPath;
}




RenderingUIController::RenderingUIController() {
    m_volumeSpacingX = m_volumeSpacingY = m_volumeSpacingZ = 1.0f;
	m_dirPath = "";
    init();
}





RenderingUIController::~RenderingUIController() {

}





void RenderingUIController::init() {
	connect(&m_window, SIGNAL(signalOpenDataset()), this, SLOT(slotExecOpenDatasetDialog()));
    connect(&m_window, SIGNAL(signalUpdate()), this, SLOT(slotUpdate()));
	connect(&m_window, SIGNAL(signalReset()), this, SLOT(slotResetViewer()));
	connect(&m_window, SIGNAL(signalScreenshot()), this, SLOT(slotExecScreenshotDialog()));
    connect(&m_window, SIGNAL(signalSettings()), &RenderingSettingsUiController::instance(), SLOT(slotExecDialog()));
    connect(&m_window, SIGNAL(signalHighQuality(int)), &RenderingSettingsUiController::instance(), SLOT(slotSetHighQualityEnabled(int)));
}





void RenderingUIController::slotRender() {
    slotRender(m_window.renderingWidget()->width(), m_window.renderingWidget()->height());
}






void RenderingUIController::slotRender(int width, int height) {
    VolumeExplorer::instance().render(static_cast<unsigned>(width), static_cast<unsigned>(height));
}





void RenderingUIController::slotSetVolumeSpacing(float x, float y, float z) {
    m_volumeSpacingX = x;
    m_volumeSpacingY = y;
    m_volumeSpacingZ = z;
}
