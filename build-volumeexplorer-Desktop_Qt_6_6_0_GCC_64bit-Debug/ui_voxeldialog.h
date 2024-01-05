/********************************************************************************
** Form generated from reading UI file 'voxeldialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOXELDIALOG_H
#define UI_VOXELDIALOG_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VoxelDialog
{
public:
    QGridLayout *gridLayout;
    QWidget *bottomWidget;
    QGridLayout *gridLayout_3;
    QSpacerItem *leftHorizontalSpacer;
    QPushButton *pbApply;
    QPushButton *pbCancel;
    QSpacerItem *bottomVerticalSpacer;
    QSpacerItem *topVerticalSpacer;
    QWidget *spacingWidget;
    QGridLayout *gridLayout_2;
    QGroupBox *gbSpacing;
    QGridLayout *gridLayout_4;
    QLabel *lblMultSymbol1;
    QLineEdit *leSizeX;
    QLineEdit *leSizeY;
    QLineEdit *leSizeZ;
    QLabel *lblMultSymbol2;

    void setupUi(QDialog *VoxelDialog)
    {
        if (VoxelDialog->objectName().isEmpty())
            VoxelDialog->setObjectName("VoxelDialog");
        VoxelDialog->setWindowModality(Qt::ApplicationModal);
        VoxelDialog->resize(320, 242);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VoxelDialog->sizePolicy().hasHeightForWidth());
        VoxelDialog->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ui/icons/vex_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        VoxelDialog->setWindowIcon(icon);
        VoxelDialog->setModal(true);
        gridLayout = new QGridLayout(VoxelDialog);
        gridLayout->setObjectName("gridLayout");
        bottomWidget = new QWidget(VoxelDialog);
        bottomWidget->setObjectName("bottomWidget");
        gridLayout_3 = new QGridLayout(bottomWidget);
        gridLayout_3->setObjectName("gridLayout_3");
        leftHorizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(leftHorizontalSpacer, 0, 0, 1, 1);

        pbApply = new QPushButton(bottomWidget);
        pbApply->setObjectName("pbApply");
        pbApply->setAutoDefault(false);

        gridLayout_3->addWidget(pbApply, 0, 1, 1, 1);

        pbCancel = new QPushButton(bottomWidget);
        pbCancel->setObjectName("pbCancel");
        pbCancel->setAutoDefault(false);

        gridLayout_3->addWidget(pbCancel, 0, 2, 1, 1);


        gridLayout->addWidget(bottomWidget, 3, 0, 1, 2);

        bottomVerticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(bottomVerticalSpacer, 4, 0, 1, 2);

        topVerticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(topVerticalSpacer, 0, 0, 1, 2);

        spacingWidget = new QWidget(VoxelDialog);
        spacingWidget->setObjectName("spacingWidget");
        gridLayout_2 = new QGridLayout(spacingWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gbSpacing = new QGroupBox(spacingWidget);
        gbSpacing->setObjectName("gbSpacing");
        gridLayout_4 = new QGridLayout(gbSpacing);
        gridLayout_4->setObjectName("gridLayout_4");
        lblMultSymbol1 = new QLabel(gbSpacing);
        lblMultSymbol1->setObjectName("lblMultSymbol1");

        gridLayout_4->addWidget(lblMultSymbol1, 0, 1, 1, 1);

        leSizeX = new QLineEdit(gbSpacing);
        leSizeX->setObjectName("leSizeX");

        gridLayout_4->addWidget(leSizeX, 0, 0, 1, 1);

        leSizeY = new QLineEdit(gbSpacing);
        leSizeY->setObjectName("leSizeY");

        gridLayout_4->addWidget(leSizeY, 0, 2, 1, 1);

        leSizeZ = new QLineEdit(gbSpacing);
        leSizeZ->setObjectName("leSizeZ");

        gridLayout_4->addWidget(leSizeZ, 0, 4, 1, 1);

        lblMultSymbol2 = new QLabel(gbSpacing);
        lblMultSymbol2->setObjectName("lblMultSymbol2");

        gridLayout_4->addWidget(lblMultSymbol2, 0, 3, 1, 1);


        gridLayout_2->addWidget(gbSpacing, 0, 0, 1, 1);


        gridLayout->addWidget(spacingWidget, 1, 0, 1, 2);

        QWidget::setTabOrder(leSizeX, leSizeY);
        QWidget::setTabOrder(leSizeY, leSizeZ);
        QWidget::setTabOrder(leSizeZ, pbApply);
        QWidget::setTabOrder(pbApply, pbCancel);

        retranslateUi(VoxelDialog);
        QObject::connect(pbCancel, &QPushButton::clicked, VoxelDialog, qOverload<>(&QDialog::reject));
        QObject::connect(pbApply, &QPushButton::clicked, VoxelDialog, qOverload<>(&QDialog::accept));

        pbApply->setDefault(true);


        QMetaObject::connectSlotsByName(VoxelDialog);
    } // setupUi

    void retranslateUi(QDialog *VoxelDialog)
    {
        VoxelDialog->setWindowTitle(QCoreApplication::translate("VoxelDialog", "Voxel Aspect", nullptr));
        pbApply->setText(QCoreApplication::translate("VoxelDialog", "OK", nullptr));
#if QT_CONFIG(shortcut)
        pbApply->setShortcut(QCoreApplication::translate("VoxelDialog", "Enter", nullptr));
#endif // QT_CONFIG(shortcut)
        pbCancel->setText(QCoreApplication::translate("VoxelDialog", "Cancel", nullptr));
        gbSpacing->setTitle(QCoreApplication::translate("VoxelDialog", "Voxel spacing:", nullptr));
        lblMultSymbol1->setText(QCoreApplication::translate("VoxelDialog", "\303\227", nullptr));
        leSizeX->setText(QCoreApplication::translate("VoxelDialog", "1.0", nullptr));
        leSizeX->setPlaceholderText(QString());
        leSizeY->setText(QCoreApplication::translate("VoxelDialog", "1.0", nullptr));
        leSizeZ->setText(QCoreApplication::translate("VoxelDialog", "1.0", nullptr));
        lblMultSymbol2->setText(QCoreApplication::translate("VoxelDialog", "\303\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VoxelDialog: public Ui_VoxelDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOXELDIALOG_H
