#include "attributeuicontroller.h"


#include <vector>
#include <QMessageBox>
#include <QPushButton>
#include "attribute/attributemanager.h"
#include "log_utils/logger.h"
#include "transfer_function/transferfunction.cuh"
#include "volumeexplorer.h"
#include "ui/rendering/renderinguicontroller.h"
#include "ui/transfer_function/tfdesigneruicontroller.h"


using namespace attribute;
using namespace log_utils;
using namespace std;
using namespace transfer_function;







AttributeUIController& AttributeUIController::instance() {
	static AttributeUIController instance;

	return instance;
}





AttributeUIController::AttributeUIController(){
	init();
}






AttributeUIController::~AttributeUIController(){

}



void AttributeUIController::init(){
    connect(&m_attributeDialog, SIGNAL(signalAccepted(std::set<attribute::AttributeType>&, int, std::string)), this, SLOT(slotDialogAccepted(std::set<attribute::AttributeType>&, int, std::string)));
    connect(&m_attributeDialog, SIGNAL(signalOpenCSVFile()), this, SLOT(slotExecFileDialog()));
    connect(&m_fileDialog, SIGNAL(fileSelected(QString)), &m_attributeDialog, SLOT(slotSetFilePath(QString)));

    m_attributeDialog.slotSetAvailableTypes(VolumeExplorer::instance().availableAttributes());

    m_fileDialog.setWindowTitle("Save CSV attribute data");
    m_fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    m_fileDialog.setNameFilter("*.attr");
    m_fileDialog.setDefaultSuffix(".attr");
}






int AttributeUIController::slotExecAttributeDialog(){
    return m_attributeDialog.exec();
}



int AttributeUIController::slotExecFileDialog() {
    return m_fileDialog.exec();
}



void AttributeUIController::slotDialogAccepted(std::set<attribute::AttributeType> &types, int mask, std::string filePath) {
	if(VolumeExplorer::instance().isDatasetLoaded()){
		Logger::instance().appendMessage("SELECTED ATTRIBUTES:");
		for(auto t = types.begin(); t != types.end(); t++){
			Logger::instance().appendMessage("- " + AttributeManager::instance().name(*t));
		}
		Logger::instance().appendMessage("");

		TFDesignerUIController::instance().setProgressBarVisible(true);
		TFDesignerUIController::instance().setProgressBarValue(25);

        VolumeExplorer::instance().selectAttributes(types, mask, filePath);

		TFDesignerUIController::instance().setProgressBarValue(90);

		if(TFDesigner::instance().isDimReduced() ){
			TFDesignerUIController::instance().slotErasePlot();
		}

		RenderingUIController::instance().slotUpdate();

		TFDesignerUIController::instance().setProgressBarValue(100);
		TFDesignerUIController::instance().setProgressBarVisible(false);
	}
	else{
		QMessageBox msg_box;
		msg_box.setWindowTitle("Warning");
		msg_box.setText("Option not available before dataset loading.");
		msg_box.setStandardButtons(QMessageBox::Ok);
		msg_box.exec();
	}
}





