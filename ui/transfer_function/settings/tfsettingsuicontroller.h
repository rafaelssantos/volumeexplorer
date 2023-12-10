#ifndef TFSETTINGSUICONTROLLER_H
#define TFSETTINGSUICONTROLLER_H


#include <QObject>
#include "tfsettingsdialog.h"



class TFSettingsUiController: public QObject {
    Q_OBJECT

public:
    static TFSettingsUiController& instance();


public slots:
    int slotExecDialog();

private:
    TFSettingsUiController();

    virtual ~TFSettingsUiController();

private:
    TFSettingsUiController(const TFSettingsUiController &) = delete;
    TFSettingsUiController &operator=(const TFSettingsUiController &) = delete;



private slots:
    void slotSettingsDialogAccepted(float minDiameter, float borderWidth, float zoomIncrement, float baseOpacity, float selectedOpacity, float unselectedOpacity, bool pivotLabelEnabled);

    void slotSettingsDialogRejected();
};



#endif // TFEDITOSETTINGSUICONTROLLER_H
