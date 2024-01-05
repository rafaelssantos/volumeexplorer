#include "attributedialog.h"
#include "ui_attributedialog.h"

#include "attributeuicontroller.h"
#include "attribute/attributemanager.h"

using namespace std;
using namespace attribute;






AttributeDialog::AttributeDialog(QWidget *parent) : QDialog(parent), m_ui(new Ui::AttributeDialog){
	m_ui->setupUi(this);
	initComponents();
}






AttributeDialog::~AttributeDialog(){
	m_checkboxes.clear();
	delete m_ui;
}




void AttributeDialog::initComponents(){
    Qt::WindowFlags flags;
	flags |= Qt::WindowMaximizeButtonHint;
	flags |= Qt::WindowContextHelpButtonHint;
	flags |= Qt::WindowCloseButtonHint;
	setWindowFlags(flags);

	connect(m_ui->pbApply, SIGNAL(clicked()), this, SLOT(slotEmitSignalAccepted()));
	connect(m_ui->pbCancel, SIGNAL(clicked()), this, SLOT(slotEmitSignalRejected()));
	connect(this, SIGNAL(rejected()), this, SLOT(slotEmitSignalRejected()));
	connect(m_ui->pbSelectAll, SIGNAL(clicked()), this, SLOT(slotSelectAll()));
    connect(m_ui->pbFilePath, SIGNAL(clicked()), this, SLOT(slotEmitSignalOpenFile()));
}




void AttributeDialog::slotSelectAll() {
	for(auto i = 0u; i < m_checkboxes.size(); i++){
		m_checkboxes[i]->setChecked(true);
	}
}





void AttributeDialog::slotSetAvailableTypes(const std::set<AttributeType> &availableTypes) {
	m_attributeTypes.clear();
	int i = 0;
	for(auto t = availableTypes.begin(); t != availableTypes.end(); t++){
		QCheckBox *checkBox = new QCheckBox(QString::fromStdString(AttributeManager::instance().name(*t)), this);

		m_checkboxes.emplace_back(checkBox);
		m_ui->groupBoxTypesLayout->addWidget(checkBox, i, 0);

		m_attributeTypes[i] = *t;
		i++;
    }
}



void AttributeDialog::slotSetFilePath(QString filePath) {
    m_ui->leFilePath->setText(filePath);
}





void AttributeDialog::slotEmitSignalAccepted(){
	set<AttributeType> selectedTypes;

	for(unsigned i = 0; i < m_checkboxes.size(); i++){
		if(m_checkboxes.at(i)->isChecked()){
			selectedTypes.emplace(m_attributeTypes[static_cast<int>(i)]);
		}
	}
	if(selectedTypes.size() > 0){
        emit signalAccepted(selectedTypes, m_ui->sbSide->value(), m_ui->leFilePath->text().toStdString());
    }
}



void AttributeDialog::slotEmitSignalOpenFile() {
    emit signalOpenCSVFile();
}






void AttributeDialog::slotEmitSignalRejected(){
	emit signalRejected();
}
