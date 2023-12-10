#include "renderingsettingsuicontroller.h"


#include "volumeexplorer.h"
#include "renderingsettingsdialog.h"


using namespace settings;

using namespace std;






RenderingSettingsUiController::RenderingSettingsUiController() {
}






RenderingSettingsUiController::~RenderingSettingsUiController() {

}




void RenderingSettingsUiController::slotSettingsDialogAccepted(dim3 blockDim, bool devSyncronize, float zoomIncrement, float rotationDegree, float maxOpacity, float step, unsigned maxNumberOfSteps, transfer_function::Interpolation filterType, bool illuminationEnabled, float ambient, float diffuse, float specular, int power) {
    RenderingSettings::instance().setBlockDim(blockDim);
    RenderingSettings::instance().setDevSyncronizeEnable(devSyncronize);
    RenderingSettings::instance().setZoomIncrement(zoomIncrement);
    RenderingSettings::instance().setRotationDegree(rotationDegree);
    RenderingSettings::instance().setMaxOpacity(maxOpacity);
    RenderingSettings::instance().setStep(step);
    RenderingSettings::instance().setMaxNumberOfSteps(maxNumberOfSteps);
    RenderingSettings::instance().setInterpolation(filterType);
    RenderingSettings::instance().setIllumEnabled(illuminationEnabled);
    RenderingSettings::instance().setIllumAmbientPower(ambient);
    RenderingSettings::instance().setIllumDiffusePower(diffuse);
    RenderingSettings::instance().setIllumSpecularPower(specular);
    RenderingSettings::instance().setIllumShininess(power);
    RenderingSettings::instance().save();
}






void RenderingSettingsUiController::slotLoadSettingsToCore() {
    RenderingSettings::instance().load();
}


void RenderingSettingsUiController::slotSetHighQualityEnabled(int checkState) {
    if(checkState == Qt::CheckState::Checked){
        RenderingSettings::instance().setHQEnabled(true);
    }
    else{
        RenderingSettings::instance().setHQEnabled(false);
    }
}




RenderingSettingsUiController& RenderingSettingsUiController::instance() {
    static RenderingSettingsUiController instance;

    return instance;
}





int RenderingSettingsUiController::slotExecDialog() {

    RenderingSettings::instance().load();

    RenderingSettingsDialog dialog;
    dialog.slotSetFields(
        RenderingSettings::instance().blockDim(),
        RenderingSettings::instance().devSyncronizeEnabled(),
        RenderingSettings::instance().zoomIncrement(),
        RenderingSettings::instance().rotationDegree(),
        RenderingSettings::instance().maxOpacity(),
        RenderingSettings::instance().step(),
        RenderingSettings::instance().maxNumberOfSteps(),
        RenderingSettings::instance().interpolation(),
        RenderingSettings::instance().illumEnabled(),
        RenderingSettings::instance().illumAmbientPower(),
        RenderingSettings::instance().illumDiffusePower(),
        RenderingSettings::instance().illumSpecularPower(),
        RenderingSettings::instance().illumShininess());

    connect(&dialog, SIGNAL(signalAccepted(dim3,bool,float,float,float,float,uint,transfer_function::Interpolation,bool,float,float,float,int)), this,
            SLOT(slotSettingsDialogAccepted(dim3,bool,float,float,float,float,uint,transfer_function::Interpolation,bool,float,float,float,int)));

    connect(&dialog,
            SIGNAL(signalRejected()),
            this,
            SLOT(slotSettingsDialogRejected()));

    return dialog.exec();
}




void RenderingSettingsUiController::slotSettingsDialogRejected() {

}
