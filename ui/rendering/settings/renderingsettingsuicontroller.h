#ifndef RENDERINGSETTINGSUICONTROLLER_H
#define RENDERINGSETTINGSUICONTROLLER_H


#include <string>
#include <QObject>
#include "settings/renderingsettings.h"
#include "transfer_function/interpolation.h"


using transfer_function::Interpolation;



class RenderingSettingsUiController : public QObject {
    Q_OBJECT

public:
    static RenderingSettingsUiController& instance();


public slots:
    int slotExecDialog();

    void slotLoadSettingsToCore();

    void slotSetHighQualityEnabled(int checkState);



protected:
    RenderingSettingsUiController();

    virtual ~RenderingSettingsUiController();



private:
    RenderingSettingsUiController(const RenderingSettingsUiController &) = delete;
    RenderingSettingsUiController &operator=(const RenderingSettingsUiController &) = delete;



private slots:
    void slotSettingsDialogAccepted(dim3 blockDim, bool devSyncronize, float zoomIncrement, float rotationDegree, float maxOpacity, float step, unsigned maxNumberOfSteps, transfer_function::Interpolation filterType, bool illuminationEnabled, float ambient, float diffuse, float specular, int power);

    void slotSettingsDialogRejected();
};



#endif // RENDERINGSETTINGSUICONTROLLER_HPP
