#ifndef RENDERINGSETTINGSDIALOG_H
#define RENDERINGSETTINGSDIALOG_H


#include <QDialog>
#include "settings/renderingsettings.h"



namespace Ui {
class RenderingSettingsDialog;
}



class RenderingSettingsDialog : public QDialog {
    Q_OBJECT



public:
    RenderingSettingsDialog(QWidget *parent = nullptr);

    virtual ~RenderingSettingsDialog();



public slots:
    void slotSetFields(dim3 blockDim, bool devSyncronize, float zoomIncrement, float rotationDegree, float maxOpacity, float step, unsigned maxNumberOfSteps, transfer_function::Interpolation filterType, bool illuminationEnabled, float ambient, float diffuse, float specular, int power);



signals:
    void signalAccepted(dim3 blockDim, bool devSyncronize, float zoomIncrement, float rotationDegree,  float maxOpacity, float step, unsigned maxNumberOfSteps, transfer_function::Interpolation filterType, bool illuminationEnabled, float ambient, float diffuse, float specular, int power);

    void signalRejected();



protected:
    virtual void initComponents();



private:
    RenderingSettingsDialog(const RenderingSettingsDialog &) = delete;
    RenderingSettingsDialog &operator=(const RenderingSettingsDialog &) = delete;

    Ui::RenderingSettingsDialog *ui;



private slots:
    void slotEmitSignalAccepted();

    void slotEmitSignalRejected();

    void slotIlluminationEnabled(bool enabled);
};



#endif // RENDERINGSETTINGSDIALOG_HPP
