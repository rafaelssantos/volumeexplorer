#include "tfsettingsdialog.h"
#include "ui_tfsettingsdialog.h"



using namespace std;





TFSettingsDialog::TFSettingsDialog(QWidget *parent) : QDialog(parent), m_ui(new Ui::TFSettingsDialog){
    m_ui->setupUi(this);
    initUI();
}






TFSettingsDialog::~TFSettingsDialog(){
    delete m_ui;
    m_ui = nullptr;
}





void TFSettingsDialog::slotSetFields(float size, float borderWidth, float zoomIncrement, float baseOpacity, float selectedOpacity, float unselectedOpacity, bool pivotLabelEnabled){
	m_ui->sbSize->setValue(size);
	m_ui->sbBorderWidth->setValue(borderWidth);
    m_ui->sbZoomIncrement->setValue(zoomIncrement);
    m_ui->sbBaseOpacity->setValue(baseOpacity);
    m_ui->sbSelectedOpacity->setValue(selectedOpacity);
    m_ui->sbUnselectedOpacity->setValue(unselectedOpacity);
    if(pivotLabelEnabled){
        m_ui->cbPivotLabel->setCheckState(Qt::Checked);
    }
    else{
        m_ui->cbPivotLabel->setCheckState(Qt::Unchecked);
    }
}






void TFSettingsDialog::initUI(){
    Qt::WindowFlags flags;
    flags |= Qt::WindowMaximizeButtonHint;
    flags |= Qt::WindowContextHelpButtonHint;
    flags |= Qt::WindowCloseButtonHint;
    setWindowFlags(flags);


    connect(m_ui->pbApply, SIGNAL(clicked()), this, SLOT(slotEmitSignalAccepted()));
    connect(m_ui->pbCancel, SIGNAL(clicked()), this, SLOT(slotEmitSignalRejected()));
}






void TFSettingsDialog::slotEmitSignalAccepted(){
	float diameter = m_ui->sbSize->value();
    float borderWidth = m_ui->sbBorderWidth->value();
    float zoomIncrement = static_cast<float>(m_ui->sbZoomIncrement->value());
    float baseOpacity = static_cast<float>(m_ui->sbBaseOpacity->value());
    float selectedOpacity = static_cast<float>(m_ui->sbSelectedOpacity->value());
    float unselectedOpacity = static_cast<float>(m_ui->sbUnselectedOpacity->value());
    bool pivotLabelEnabled = false;

    if(m_ui->cbPivotLabel->checkState() == Qt::Checked){
        pivotLabelEnabled = true;
    }

	emit signalAccepted(diameter, borderWidth, zoomIncrement, baseOpacity, selectedOpacity, unselectedOpacity, pivotLabelEnabled);
}






void TFSettingsDialog::slotEmitSignalRejected(){
    emit signalRejected();
}
