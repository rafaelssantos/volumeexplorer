#include "renderingsettingsdialog.h"
#include "ui_renderingsettingsdialog.h"



using namespace std;
using namespace transfer_function;
using namespace settings;






RenderingSettingsDialog::RenderingSettingsDialog(QWidget *parent) : QDialog(parent), m_ui(new Ui::RenderingSettingsDialog) {
    m_ui->setupUi(this);
    initComponents();
}






RenderingSettingsDialog::~RenderingSettingsDialog() {
    delete m_ui;
    m_ui = nullptr;
}






void RenderingSettingsDialog::slotEmitSignalAccepted() {
    dim3 blockDim = {static_cast<unsigned>(m_ui->sbBlockDimX->value()), static_cast<unsigned>(m_ui->sbBlockDimY->value()), static_cast<unsigned>(m_ui->sbBlockDimZ->value())};
    bool devSyncronize = m_ui->cbDevSyncronize->isChecked();

    float maxOpacity = static_cast<float>(m_ui->sbMaxOpacity->value());

    float step = static_cast<float>(m_ui->sbStepLength->value());
    unsigned maxNumberOfSteps = static_cast<unsigned>(m_ui->sbMaxNumberOfSteps->value());

    float zoomIncrement = static_cast<float>(m_ui->sbZoomIncrement->value());
    float rotationDegree = static_cast<float>(m_ui->sbRotationDegree->value());

    bool illuminationEnabled = m_ui->cbEnabled->isChecked();
    float ambient = m_ui->sbAmbient->value() / 100.0f;
    float diffuse = m_ui->sbDiffuse->value() / 100.0f;
    float specular = m_ui->sbSpecular->value() / 100.0f;
    int shininness = m_ui->spShininess->value();

    Interpolation interpolation;
    if (m_ui->rbTrilinear->isChecked()) {
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
    m_ui->lblAmbient->setEnabled(enabled);
    m_ui->lblDiffuse->setEnabled(enabled);
    m_ui->lblSpecular->setEnabled(enabled);
    m_ui->lblShininess->setEnabled(enabled);
    m_ui->sdAmbient->setEnabled(enabled);
    m_ui->sdDiffuse->setEnabled(enabled);
    m_ui->sdSpecular->setEnabled(enabled);
    m_ui->spShininess->setEnabled(enabled);
    m_ui->sbAmbient->setEnabled(enabled);
    m_ui->sbDiffuse->setEnabled(enabled);
    m_ui->sbSpecular->setEnabled(enabled);
}






void RenderingSettingsDialog::initComponents() {
    Qt::WindowFlags flags;
    flags |= Qt::WindowMaximizeButtonHint;
    flags |= Qt::WindowContextHelpButtonHint;
    flags |= Qt::WindowCloseButtonHint;
    setWindowFlags(flags);

    connect(m_ui->pbApply, SIGNAL(clicked()), this, SLOT(slotEmitSignalAccepted()));
    connect(m_ui->pbCancel, SIGNAL(clicked()), this, SLOT(slotEmitSignalRejected()));
    connect(m_ui->cbEnabled, SIGNAL(toggled(bool)), this, SLOT(slotIlluminationEnabled(bool)));
    connect(this, SIGNAL(rejected()), this, SLOT(slotEmitSignalRejected()));

    connect(m_ui->sdAmbient, SIGNAL(valueChanged(int)), m_ui->sbAmbient, SLOT(setValue(int)));
    connect(m_ui->sdDiffuse, SIGNAL(valueChanged(int)), m_ui->sbDiffuse, SLOT(setValue(int)));
    connect(m_ui->sdSpecular, SIGNAL(valueChanged(int)), m_ui->sbSpecular, SLOT(setValue(int)));

    connect(m_ui->sbAmbient, SIGNAL(valueChanged(int)), m_ui->sdAmbient, SLOT(setValue(int)));
    connect(m_ui->sbDiffuse, SIGNAL(valueChanged(int)), m_ui->sdDiffuse, SLOT(setValue(int)));
    connect(m_ui->sbSpecular, SIGNAL(valueChanged(int)), m_ui->sdSpecular, SLOT(setValue(int)));
}






void RenderingSettingsDialog::slotSetFields(dim3 blockDim, bool devSyncronize, float zoomIncrement, float rotationDegree, float maxOpacity, float step, unsigned maxNumberOfSteps, Interpolation filterType, bool illuminationEnabled, float ambient, float diffuse, float specular, int power) {
    m_ui->sbBlockDimX->setValue(static_cast<int>(blockDim.x));
    m_ui->sbBlockDimY->setValue(static_cast<int>(blockDim.y));
    m_ui->sbBlockDimZ->setValue(static_cast<int>(blockDim.z));
    m_ui->cbDevSyncronize->setChecked(devSyncronize);
    m_ui->sbZoomIncrement->setValue(zoomIncrement);

    m_ui->sbRotationDegree->setValue(rotationDegree);
    m_ui->sbMaxOpacity->setValue(maxOpacity);
    m_ui->sbMaxNumberOfSteps->setValue(static_cast<int>(maxNumberOfSteps));
    m_ui->sbStepLength->setValue(step);
    m_ui->cbEnabled->setChecked(illuminationEnabled);

    m_ui->sdAmbient->setValue(static_cast<int>(100.0f * ambient));
    m_ui->sdDiffuse->setValue(static_cast<int>(100.0f * diffuse));
    m_ui->sdSpecular->setValue(static_cast<int>(100.0f * specular));
    m_ui->spShininess->setValue(static_cast<int>(power));

    if (filterType == Interpolation::TRILINEAR) {
        m_ui->rbTrilinear->setChecked(true);
    }
    else {
        m_ui->rbNearest->setChecked(true);
    }
}
