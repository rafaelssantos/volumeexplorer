#include "clusteringdialog.h"
#include "ui_clusteringdialog.h"


using namespace std;




ClusteringDialog::ClusteringDialog(QWidget *parent) : QDialog(parent), m_ui(new Ui::ClusteringDialog){
    m_ui->setupUi(this);
    initComponents();
}







ClusteringDialog::~ClusteringDialog(){
    delete m_ui;
}




void ClusteringDialog::setFields(int minPoints, float eps, float alpha){
	m_ui->sbMinPoints->setValue(minPoints);
	m_ui->sbEps->setValue(eps);
	m_ui->sbAlpha->setValue(alpha);
}






void ClusteringDialog::initComponents(){
    Qt::WindowFlags flags;
    flags |= Qt::WindowMaximizeButtonHint;
    flags |= Qt::WindowContextHelpButtonHint;
    flags |= Qt::WindowCloseButtonHint;
    setWindowFlags(flags);

    connect(m_ui->pbApply, SIGNAL(clicked()), this, SLOT(slotEmitSignalAccepted()));
    connect(m_ui->pbCancel, SIGNAL(clicked()), this, SLOT(slotEmitSignalRejected()));
    connect(this, SIGNAL(rejected()), this, SLOT(slotEmitSignalRejected()));
}





void ClusteringDialog::slotEmitSignalAccepted(){
	int minPoints = m_ui->sbMinPoints->value();
	float eps = m_ui->sbEps->value();
	float alpha = m_ui->sbAlpha->value();

	emit signalAccepted(minPoints, eps, alpha);
}





void ClusteringDialog::slotEmitSignalRejected(){
    emit signalRejected();
}
