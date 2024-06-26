#ifndef ATTRIBUTEUICONTROLLER_H
#define ATTRIBUTEUICONTROLLER_H


#include <cstddef>
#include <vector>
#include <set>
#include <QObject>

#include "attributedialog.h"



class AttributeUIController: public QObject {
	Q_OBJECT

public:
	static AttributeUIController& instance();


private:
	AttributeUIController();

	virtual ~AttributeUIController();

	void init();

    AttributeDialog m_attributeDialog;
    QFileDialog m_fileDialog;


public slots:
    int slotExecAttributeDialog();

    int slotExecFileDialog();


private slots:
    void slotDialogAccepted(std::set<attribute::AttributeType>& types, int mask, std::string filePath);
};



#endif // ATTRIBUTEUICONTROLLER_H
