#include "tfsettingsuicontroller.h"



#include "volumeexplorer.h"
#include "ui/transfer_function/tfdesigneruicontroller.h"
#include "tfsettingsdialog.h"
#include "settings/tfsettings.h"




using namespace settings;

using namespace std;





TFSettingsUiController::TFSettingsUiController() {
    TFSettings::instance().load();
}






TFSettingsUiController::~TFSettingsUiController(){

}




void TFSettingsUiController::slotSettingsDialogAccepted(float diameter, float borderWidth, float zoomIncrement, float baseOpacity, float selectedOpacity, float unselectedOpacity, bool pivotLabelEnabled) {
	TFSettings::instance().setPivotSize(diameter);
    TFSettings::instance().setPivotBorderWidth(borderWidth);
    TFSettings::instance().setZoomIncrement(zoomIncrement);
    TFSettings::instance().setBaseOpacity(baseOpacity);
    TFSettings::instance().setSelectedOpacity(selectedOpacity);
    TFSettings::instance().setUnselectedOpacity(unselectedOpacity);
    TFSettings::instance().setPivotLabelEnabled(pivotLabelEnabled);
    TFDesignerUIController::instance().updatePivots();

    TFSettings::instance().save();
}






TFSettingsUiController& TFSettingsUiController::instance() {
    static TFSettingsUiController instance;

    return instance;
}





int TFSettingsUiController::slotExecDialog(){
    TFSettings::instance().load();

    TFSettingsDialog dialog;

	dialog.slotSetFields(TFSettings::instance().pivotSize(),
                         TFSettings::instance().pivotBorderWidth(),
                         TFSettings::instance().zoomIncrement(),
                         TFSettings::instance().baseOpacity(),
                         TFSettings::instance().selectedOpacity(),
                         TFSettings::instance().unselectedOpacity(),
                         TFSettings::instance().pivotLabelEnabled());

	connect(&dialog, SIGNAL(signalAccepted(float,float,float,float,float,float, bool)),
			this, SLOT(slotSettingsDialogAccepted(float,float,float,float,float,float, bool)));
    connect(&dialog, SIGNAL(signalRejected()),
            this, SLOT(slotSettingsDialogRejected()));

    return dialog.exec();
}






void TFSettingsUiController::slotSettingsDialogRejected(){
}
