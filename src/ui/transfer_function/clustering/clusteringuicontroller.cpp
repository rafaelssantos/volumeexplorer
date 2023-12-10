#include "clusteringuicontroller.h"

#include <string>
#include <QMessageBox>
#include "clusteringdialog.h"
#include "log_utils/logger.h"
#include "transfer_function/tfdesigner.h"
#include "volumeexplorer.h"
#include "ui/transfer_function/tfdesigneruicontroller.h"


using namespace graphics_utils;
using namespace log_utils;
using namespace std;
using namespace transfer_function;






ClusteringUIController::ClusteringUIController() {
	m_eps = 0.2f;
	m_minPoints = 3;
    m_alpha = 0.95f;
}

ClusteringUIController::~ClusteringUIController() {

}





int ClusteringUIController::slotExecDialog() {
	if(TFDesigner::instance().isDimReduced()){
		ClusteringDialog dialog;
		dialog.setFields(m_minPoints, m_eps, m_alpha);

		connect(&dialog,
				SIGNAL(signalAccepted(int, float, float)),
				this,
				SLOT(sloDialogAccepted(int, float, float)));

		connect(&dialog,
				SIGNAL(signalRejected()),
				this,
				SLOT(slotDialogRejected()));

		return dialog.exec();
	}
	else{
		QMessageBox msg_box;
		msg_box.setWindowTitle("Warning");
		msg_box.setText("Option not available before features extraction and dimensionality reduction!");
		msg_box.setStandardButtons(QMessageBox::Ok);
		msg_box.exec();

		return QMessageBox::Rejected;
	}
}



ClusteringUIController& ClusteringUIController::instance() {
	static ClusteringUIController instance;

	return instance;
}





void ClusteringUIController::sloDialogAccepted(int minPoints, float eps, float alpha){
	m_minPoints = minPoints;
	m_eps = eps;
	m_alpha = alpha;

	Logger::instance().appendMessage("\nPARAMETERS");
	Logger::instance().appendMessage("DBSCAN minPts = " + to_string(minPoints));
	Logger::instance().appendMessage("DBSCAN eps = " + to_string(eps));
	Logger::instance().appendMessage("SSS alpha = " + to_string(alpha) + "\n");

	TFDesignerUIController::instance().setProgressBarVisible(true);
	TFDesignerUIController::instance().setProgressBarValue(10);

	Logger::instance().startTimer(0);
	TFDesigner::instance().exeClustering(VolumeExplorer::instance().volume(), eps, minPoints);
	Logger::instance().stopTimer(0, "Runtime DBSCAN");
	TFDesignerUIController::instance().setProgressBarValue(60);

	Logger::instance().startTimer(1);
	TFDesigner::instance().execSimilarySearch(alpha);
	Logger::instance().stopTimer(1, "Runtime SSS");
	TFDesignerUIController::instance().setProgressBarValue(80);

	TFDesigner::instance().freeUI();
	Logger::instance().startTimer(2);
	TFDesigner::instance().buildLookUpTable();
	Logger::instance().stopTimer(2, "Runtime LUT");
	TFDesignerUIController::instance().setProgressBarValue(100);
	TFDesignerUIController::instance().setProgressBarVisible(false);

	if(TFDesigner::instance().isClustered()){
		if(TFDesigner::instance().pivots()->size() > 1000) {
			QMessageBox msg_box;
			msg_box.setWindowTitle("Warning");
			msg_box.setText("More than 1000 representatives. Do you want continue?");
			msg_box.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

			if(msg_box.exec() == QMessageBox::Accepted){
				emit signalClustered();
			}
			else{
				TFDesigner::instance().freeUI();
			}
		}
		else{
			emit signalClustered();
		}
	}
}





void ClusteringUIController::slotDialogRejected() {

}
