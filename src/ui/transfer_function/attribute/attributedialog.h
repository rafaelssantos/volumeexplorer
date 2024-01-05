#ifndef ATTRIBUTEDIALOG_H
#define ATTRIBUTEDIALOG_H


#include <cstddef>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <QtWidgets>
#include <QCheckBox>
#include "attribute/attributetype.h"


namespace Ui {
class AttributeDialog;
}



class AttributeDialog : public QDialog{
	Q_OBJECT



public:
	AttributeDialog(QWidget *parent = nullptr);

	virtual ~AttributeDialog();


signals:
    void signalAccepted(std::set<attribute::AttributeType> &types, int mask, std::string filePath);

    void signalOpenCSVFile();

	void signalRejected();



public slots:
	void slotSetAvailableTypes(const std::set<attribute::AttributeType>& availableTypes);

    void slotSetFilePath(QString filePath);

	void slotSelectAll();



private:
	AttributeDialog(const AttributeDialog &) = delete;
	AttributeDialog &operator =(const AttributeDialog &) = delete;

	Ui::AttributeDialog *m_ui;
	std::vector<QCheckBox *> m_checkboxes;
    std::map<int, attribute::AttributeType> m_attributeTypes;

	void initComponents();


private slots:

	void slotEmitSignalAccepted();

    void slotEmitSignalOpenFile();

	void slotEmitSignalRejected();
};



#endif // ATTRIBUTEDIALOG_H
