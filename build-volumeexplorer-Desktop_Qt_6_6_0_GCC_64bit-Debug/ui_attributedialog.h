/********************************************************************************
** Form generated from reading UI file 'attributedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTRIBUTEDIALOG_H
#define UI_ATTRIBUTEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AttributeDialog
{
public:
    QGridLayout *gridLayout;
    QWidget *fileWidget;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_6;
    QLineEdit *leCSVFilePath;
    QPushButton *pbCSVFile;
    QGroupBox *localHistogramWidget;
    QGridLayout *gridLayout_4;
    QLabel *lblSide;
    QSpinBox *sbSide;
    QSpacerItem *bottomVerticalSpacer;
    QSpacerItem *topVerticalSpacer;
    QWidget *featureWidget;
    QGridLayout *gridLayout_3;
    QPushButton *pbSelectAll;
    QGroupBox *groupBoxTypes;
    QGridLayout *groupBoxTypesLayout;
    QWidget *bottomWidget;
    QGridLayout *gridLayout_2;
    QPushButton *pbApply;
    QPushButton *pbCancel;

    void setupUi(QDialog *AttributeDialog)
    {
        if (AttributeDialog->objectName().isEmpty())
            AttributeDialog->setObjectName("AttributeDialog");
        AttributeDialog->setWindowModality(Qt::ApplicationModal);
        AttributeDialog->resize(320, 360);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AttributeDialog->sizePolicy().hasHeightForWidth());
        AttributeDialog->setSizePolicy(sizePolicy);
        AttributeDialog->setFocusPolicy(Qt::StrongFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ui/icons/vex_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        AttributeDialog->setWindowIcon(icon);
        AttributeDialog->setModal(true);
        gridLayout = new QGridLayout(AttributeDialog);
        gridLayout->setObjectName("gridLayout");
        fileWidget = new QWidget(AttributeDialog);
        fileWidget->setObjectName("fileWidget");
        gridLayout_5 = new QGridLayout(fileWidget);
        gridLayout_5->setObjectName("gridLayout_5");
        groupBox = new QGroupBox(fileWidget);
        groupBox->setObjectName("groupBox");
        gridLayout_6 = new QGridLayout(groupBox);
        gridLayout_6->setObjectName("gridLayout_6");
        leCSVFilePath = new QLineEdit(groupBox);
        leCSVFilePath->setObjectName("leCSVFilePath");

        gridLayout_6->addWidget(leCSVFilePath, 0, 0, 1, 1);

        pbCSVFile = new QPushButton(groupBox);
        pbCSVFile->setObjectName("pbCSVFile");

        gridLayout_6->addWidget(pbCSVFile, 0, 1, 1, 1);


        gridLayout_5->addWidget(groupBox, 0, 0, 1, 1);


        gridLayout->addWidget(fileWidget, 4, 0, 1, 1);

        localHistogramWidget = new QGroupBox(AttributeDialog);
        localHistogramWidget->setObjectName("localHistogramWidget");
        gridLayout_4 = new QGridLayout(localHistogramWidget);
        gridLayout_4->setObjectName("gridLayout_4");
        lblSide = new QLabel(localHistogramWidget);
        lblSide->setObjectName("lblSide");

        gridLayout_4->addWidget(lblSide, 0, 0, 1, 1);

        sbSide = new QSpinBox(localHistogramWidget);
        sbSide->setObjectName("sbSide");
        sbSide->setMinimum(1);
        sbSide->setMaximum(1000000);
        sbSide->setSingleStep(2);
        sbSide->setValue(5);

        gridLayout_4->addWidget(sbSide, 0, 1, 1, 1);


        gridLayout->addWidget(localHistogramWidget, 3, 0, 1, 1);

        bottomVerticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(bottomVerticalSpacer, 6, 0, 1, 1);

        topVerticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(topVerticalSpacer, 0, 0, 1, 1);

        featureWidget = new QWidget(AttributeDialog);
        featureWidget->setObjectName("featureWidget");
        gridLayout_3 = new QGridLayout(featureWidget);
        gridLayout_3->setObjectName("gridLayout_3");
        pbSelectAll = new QPushButton(featureWidget);
        pbSelectAll->setObjectName("pbSelectAll");

        gridLayout_3->addWidget(pbSelectAll, 1, 0, 1, 2);

        groupBoxTypes = new QGroupBox(featureWidget);
        groupBoxTypes->setObjectName("groupBoxTypes");
        groupBoxTypesLayout = new QGridLayout(groupBoxTypes);
        groupBoxTypesLayout->setObjectName("groupBoxTypesLayout");

        gridLayout_3->addWidget(groupBoxTypes, 0, 0, 1, 2);


        gridLayout->addWidget(featureWidget, 1, 0, 1, 1);

        bottomWidget = new QWidget(AttributeDialog);
        bottomWidget->setObjectName("bottomWidget");
        gridLayout_2 = new QGridLayout(bottomWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        pbApply = new QPushButton(bottomWidget);
        pbApply->setObjectName("pbApply");

        gridLayout_2->addWidget(pbApply, 1, 1, 1, 1);

        pbCancel = new QPushButton(bottomWidget);
        pbCancel->setObjectName("pbCancel");

        gridLayout_2->addWidget(pbCancel, 1, 2, 1, 1);


        gridLayout->addWidget(bottomWidget, 5, 0, 1, 1);

        QWidget::setTabOrder(pbSelectAll, sbSide);
        QWidget::setTabOrder(sbSide, pbApply);
        QWidget::setTabOrder(pbApply, pbCancel);

        retranslateUi(AttributeDialog);
        QObject::connect(pbApply, &QPushButton::clicked, AttributeDialog, qOverload<>(&QDialog::accept));
        QObject::connect(pbCancel, &QPushButton::clicked, AttributeDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AttributeDialog);
    } // setupUi

    void retranslateUi(QDialog *AttributeDialog)
    {
        AttributeDialog->setWindowTitle(QCoreApplication::translate("AttributeDialog", "Attribute Extraction", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AttributeDialog", "Attribute values file:", nullptr));
        leCSVFilePath->setText(QString());
        pbCSVFile->setText(QCoreApplication::translate("AttributeDialog", "...", nullptr));
        localHistogramWidget->setTitle(QCoreApplication::translate("AttributeDialog", "Local histogram:", nullptr));
        lblSide->setText(QCoreApplication::translate("AttributeDialog", "Texture dim (n\303\227n\303\227n):", nullptr));
        pbSelectAll->setText(QCoreApplication::translate("AttributeDialog", "Select all", nullptr));
        groupBoxTypes->setTitle(QCoreApplication::translate("AttributeDialog", "Attributes", nullptr));
        pbApply->setText(QCoreApplication::translate("AttributeDialog", "OK", nullptr));
#if QT_CONFIG(shortcut)
        pbApply->setShortcut(QCoreApplication::translate("AttributeDialog", "Enter", nullptr));
#endif // QT_CONFIG(shortcut)
        pbCancel->setText(QCoreApplication::translate("AttributeDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AttributeDialog: public Ui_AttributeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTRIBUTEDIALOG_H
