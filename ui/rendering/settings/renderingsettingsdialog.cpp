#include "renderingsettingsdialog.h"
#include "ui_renderingsettingsdialog.h"



using namespace std;
using namespace transfer_function;
using namespace settings;






RenderingSettingsDialog::RenderingSettingsDialog(QWidget *parent) : QDialog(parent), ui(new Ui::RenderingSettingsDialog) {
    ui->setupUi(this);
    initComponents();
}






RenderingSettingsDialog::~RenderingSettingsDialog() {
    delete ui;
}






void RenderingSettingsDialog::slotEmitSignalAccepted() {
    dim3 blockDim = {static_cast<unsigned>(ui->sbBlockDimX->value()), static_cast<unsigned>(ui->sbBlockDimY->value()), static_cast<unsigned>(ui->sbBlockDimZ->value())};
    bool devSyncronize = ui->cbDevSyncronize->isChecked();

    float maxOpacity = static_cast<float>(ui->sbMaxOpacity->value());

    float step = static_cast<float>(ui->sbStepLength->value());
    unsigned maxNumberOfSteps = static_cast<unsigned>(ui->sbMaxNumberOfSteps->value());

    float zoomIncrement = static_cast<float>(ui->sbZoomIncrement->value());
    float rotationDegree = static_cast<float>(ui->sbRotationDegree->value());

    bool illuminationEnabled = ui->cbEnabled->isChecked();
    float ambient = ui->sbAmbient->value() / 100.0f;
    float diffuse = ui->sbDiffuse->value() / 100.0f;
    float specular = ui->sbSpecular->value() / 100.0f;
    int shininness = ui->spShininess->value();

    Interpolation interpolation;
    if (ui->rbTrilinear->isChecked()) {
        interpolation = Interpolation::TRILINEAR;
    }
    else {
        interpolation = Interpolation::NEAREST;
    }

    emit signalAccepted(blockDim, devSyncronize, zoomIncrement, rotationDegree, maxOpacity, step, maxNumberOfSteps, interpolation, illuminationEnabled, ambient, diffuse, specular, shininness);
}






void RenderingSettingsDialog::slotEmitSignalRejected() {
    emit signalRejected();
}




void RenderingSettingsDialog::slotIlluminationEnabled(bool enabled) {
    ui->lblAmbient->setEnabled(enabled);
    ui->lblDiffuse->setEnabled(enabled);
    ui->lblSpecular->setEnabled(enabled);
    ui->lblShininess->setEnabled(enabled);
    ui->sdAmbient->setEnabled(enabled);
    ui->sdDiffuse->setEnabled(enabled);
    ui->sdSpecular->setEnabled(enabled);
    ui->spShininess->setEnabled(enabled);
    ui->sbAmbient->setEnabled(enabled);
    ui->sbDiffuse->setEnabled(enabled);
    ui->sbSpecular->setEnabled(enabled);
}






void RenderingSettingsDialog::initComponents() {
    Qt::WindowFlags flags;
    flags |= Qt::WindowMaximizeButtonHint;
    flags |= Qt::WindowContextHelpButtonHint;
    flags |= Qt::WindowCloseButtonHint;
    setWindowFlags(flags);

    connect(ui->pbApply, SIGNAL(clicked()), this, SLOT(slotEmitSignalAccepted()));
    connect(ui->pbCancel, SIGNAL(clicked()), this, SLOT(slotEmitSignalRejected()));
    connect(ui->cbEnabled, SIGNAL(toggled(bool)), this, SLOT(slotIlluminationEnabled(bool)));
    connect(this, SIGNAL(rejected()), this, SLOT(slotEmitSignalRejected()));

    connect(ui->sdAmbient, SIGNAL(valueChanged(int)), ui->sbAmbient, SLOT(setValue(int)));
    connect(ui->sdDiffuse, SIGNAL(valueChanged(int)), ui->sbDiffuse, SLOT(setValue(int)));
    connect(ui->sdSpecular, SIGNAL(valueChanged(int)), ui->sbSpecular, SLOT(setValue(int)));

    connect(ui->sbAmbient, SIGNAL(valueChanged(int)), ui->sdAmbient, SLOT(setValue(int)));
    connect(ui->sbDiffuse, SIGNAL(valueChanged(int)), ui->sdDiffuse, SLOT(setValue(int)));
    connect(ui->sbSpecular, SIGNAL(valueChanged(int)), ui->sdSpecular, SLOT(setValue(int)));
}






void RenderingSettingsDialog::slotSetFields(dim3 blockDim, bool devSyncronize, float zoomIncrement, float rotationDegree, float maxOpacity, float step, unsigned maxNumberOfSteps, Interpolation filterType, bool illuminationEnabled, float ambient, float diffuse, float specular, int power) {
    ui->sbBlockDimX->setValue(static_cast<int>(blockDim.x));
    ui->sbBlockDimY->setValue(static_cast<int>(blockDim.y));
    ui->sbBlockDimZ->setValue(static_cast<int>(blockDim.z));
    ui->cbDevSyncronize->setChecked(devSyncronize);
    ui->sbZoomIncrement->setValue(zoomIncrement);

    ui->sbRotationDegree->setValue(rotationDegree);
    ui->sbMaxOpacity->setValue(maxOpacity);
    ui->sbMaxNumberOfSteps->setValue(static_cast<int>(maxNumberOfSteps));
    ui->sbStepLength->setValue(step);
    ui->cbEnabled->setChecked(illuminationEnabled);

    ui->sdAmbient->setValue(static_cast<int>(100.0f * ambient));
    ui->sdDiffuse->setValue(static_cast<int>(100.0f * diffuse));
    ui->sdSpecular->setValue(static_cast<int>(100.0f * specular));
    ui->spShininess->setValue(static_cast<int>(power));

    if (filterType == Interpolation::TRILINEAR) {
        ui->rbTrilinear->setChecked(true);
    }
    else {
        ui->rbNearest->setChecked(true);
    }
}
