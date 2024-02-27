#include "voxeldialog.h"
#include "ui_voxeldialog.h"


#include <limits>
#include <string>
#include <QDoubleValidator>
#include <QFileInfo>
#include <fstream>


using namespace std;






VoxelDialog::VoxelDialog(QWidget *parent) :  QDialog(parent), m_ui(new Ui::VoxelDialog){
    m_ui->setupUi(this);
	initComponents();
}






VoxelDialog::~VoxelDialog() {
	delete m_ui;
    m_ui = nullptr;
}




void VoxelDialog::initComponents() {
    Qt::WindowFlags flags;
	flags |= Qt::WindowMaximizeButtonHint;
	flags |= Qt::WindowContextHelpButtonHint;
	flags |= Qt::WindowCloseButtonHint;
	setWindowFlags(flags);

	m_ui->leSizeX->selectAll();

	connect(m_ui->pbApply, SIGNAL(clicked()), this, SLOT(slotEmitSignalAccepted()));
	connect(m_ui->pbCancel, SIGNAL(clicked()), this, SLOT(slotEmitSignalRejected()));
	connect(this, SIGNAL(rejected()), this, SLOT(slotEmitSignalRejected()));
}



std::string VoxelDialog::dirPath() const {
	return m_dirPath;
}



void VoxelDialog::setDirPath(const std::string& dirPath) {
	m_dirPath = dirPath;
}






void VoxelDialog::slotEmitSignalAccepted() {
    emit signalAccepted(QLocale().toFloat(m_ui->leSizeX->text()), QLocale().toFloat(m_ui->leSizeY->text()), QLocale().toFloat(m_ui->leSizeZ->text()));
}





void VoxelDialog::slotEmitSignalRejected() {
	emit signalRejected();
}
