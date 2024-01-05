/********************************************************************************
** Form generated from reading UI file 'tfsettingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TFSETTINGSDIALOG_H
#define UI_TFSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TFSettingsDialog
{
public:
    QGridLayout *gridLayout;
    QWidget *settingsWidget;
    QGridLayout *gridLayout_3;
    QGroupBox *pointGroupBox;
    QGridLayout *gridLayout_6;
    QCheckBox *cbPivotLabel;
    QDoubleSpinBox *sbBaseOpacity;
    QDoubleSpinBox *sbBorderWidth;
    QLabel *lblSelectedOpacity;
    QDoubleSpinBox *sbSelectedOpacity;
    QLabel *lblBaseBgOpacity;
    QLabel *lbPivotLabel;
    QLabel *lbBorderWidth;
    QDoubleSpinBox *sbSize;
    QLabel *lblSize;
    QLabel *lblUnselectedOpacity;
    QDoubleSpinBox *sbUnselectedOpacity;
    QGroupBox *observerGroupBox;
    QGridLayout *gridLayout_5;
    QDoubleSpinBox *sbZoomIncrement;
    QLabel *lblZoomIncrement;
    QSpacerItem *topVerticalSpacer;
    QWidget *bottomWidget;
    QGridLayout *gridLayout_2;
    QPushButton *pbApply;
    QSpacerItem *leftHorizontalSpacer;
    QPushButton *pbCancel;
    QSpacerItem *bottomVerticalSpacer;

    void setupUi(QDialog *TFSettingsDialog)
    {
        if (TFSettingsDialog->objectName().isEmpty())
            TFSettingsDialog->setObjectName("TFSettingsDialog");
        TFSettingsDialog->setWindowModality(Qt::ApplicationModal);
        TFSettingsDialog->resize(420, 432);
        TFSettingsDialog->setFocusPolicy(Qt::StrongFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ui/icons/vex_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        TFSettingsDialog->setWindowIcon(icon);
        TFSettingsDialog->setModal(true);
        gridLayout = new QGridLayout(TFSettingsDialog);
        gridLayout->setObjectName("gridLayout");
        settingsWidget = new QWidget(TFSettingsDialog);
        settingsWidget->setObjectName("settingsWidget");
        gridLayout_3 = new QGridLayout(settingsWidget);
        gridLayout_3->setObjectName("gridLayout_3");
        pointGroupBox = new QGroupBox(settingsWidget);
        pointGroupBox->setObjectName("pointGroupBox");
        gridLayout_6 = new QGridLayout(pointGroupBox);
        gridLayout_6->setObjectName("gridLayout_6");
        cbPivotLabel = new QCheckBox(pointGroupBox);
        cbPivotLabel->setObjectName("cbPivotLabel");
        cbPivotLabel->setChecked(false);
        cbPivotLabel->setAutoExclusive(false);

        gridLayout_6->addWidget(cbPivotLabel, 9, 1, 1, 1);

        sbBaseOpacity = new QDoubleSpinBox(pointGroupBox);
        sbBaseOpacity->setObjectName("sbBaseOpacity");
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sbBaseOpacity->sizePolicy().hasHeightForWidth());
        sbBaseOpacity->setSizePolicy(sizePolicy);
        sbBaseOpacity->setDecimals(3);
        sbBaseOpacity->setMinimum(0.000000000000000);
        sbBaseOpacity->setMaximum(1.000000000000000);
        sbBaseOpacity->setSingleStep(0.005000000000000);
        sbBaseOpacity->setValue(0.000000000000000);

        gridLayout_6->addWidget(sbBaseOpacity, 3, 1, 1, 1);

        sbBorderWidth = new QDoubleSpinBox(pointGroupBox);
        sbBorderWidth->setObjectName("sbBorderWidth");
        sizePolicy.setHeightForWidth(sbBorderWidth->sizePolicy().hasHeightForWidth());
        sbBorderWidth->setSizePolicy(sizePolicy);
        sbBorderWidth->setDecimals(3);
        sbBorderWidth->setMinimum(0.000000000000000);
        sbBorderWidth->setMaximum(1000000.000000000000000);
        sbBorderWidth->setSingleStep(0.500000000000000);

        gridLayout_6->addWidget(sbBorderWidth, 2, 1, 1, 1);

        lblSelectedOpacity = new QLabel(pointGroupBox);
        lblSelectedOpacity->setObjectName("lblSelectedOpacity");

        gridLayout_6->addWidget(lblSelectedOpacity, 6, 0, 1, 1);

        sbSelectedOpacity = new QDoubleSpinBox(pointGroupBox);
        sbSelectedOpacity->setObjectName("sbSelectedOpacity");
        sizePolicy.setHeightForWidth(sbSelectedOpacity->sizePolicy().hasHeightForWidth());
        sbSelectedOpacity->setSizePolicy(sizePolicy);
        sbSelectedOpacity->setDecimals(3);
        sbSelectedOpacity->setMinimum(0.000000000000000);
        sbSelectedOpacity->setMaximum(1.000000000000000);
        sbSelectedOpacity->setSingleStep(0.005000000000000);
        sbSelectedOpacity->setValue(0.000000000000000);

        gridLayout_6->addWidget(sbSelectedOpacity, 6, 1, 1, 1);

        lblBaseBgOpacity = new QLabel(pointGroupBox);
        lblBaseBgOpacity->setObjectName("lblBaseBgOpacity");

        gridLayout_6->addWidget(lblBaseBgOpacity, 3, 0, 1, 1);

        lbPivotLabel = new QLabel(pointGroupBox);
        lbPivotLabel->setObjectName("lbPivotLabel");

        gridLayout_6->addWidget(lbPivotLabel, 9, 0, 1, 1);

        lbBorderWidth = new QLabel(pointGroupBox);
        lbBorderWidth->setObjectName("lbBorderWidth");

        gridLayout_6->addWidget(lbBorderWidth, 2, 0, 1, 1);

        sbSize = new QDoubleSpinBox(pointGroupBox);
        sbSize->setObjectName("sbSize");
        sizePolicy.setHeightForWidth(sbSize->sizePolicy().hasHeightForWidth());
        sbSize->setSizePolicy(sizePolicy);
        sbSize->setDecimals(3);
        sbSize->setMinimum(0.000000000000000);
        sbSize->setMaximum(1000000.000000000000000);
        sbSize->setSingleStep(0.500000000000000);

        gridLayout_6->addWidget(sbSize, 0, 1, 1, 1);

        lblSize = new QLabel(pointGroupBox);
        lblSize->setObjectName("lblSize");

        gridLayout_6->addWidget(lblSize, 0, 0, 1, 1);

        lblUnselectedOpacity = new QLabel(pointGroupBox);
        lblUnselectedOpacity->setObjectName("lblUnselectedOpacity");

        gridLayout_6->addWidget(lblUnselectedOpacity, 8, 0, 1, 1);

        sbUnselectedOpacity = new QDoubleSpinBox(pointGroupBox);
        sbUnselectedOpacity->setObjectName("sbUnselectedOpacity");
        sizePolicy.setHeightForWidth(sbUnselectedOpacity->sizePolicy().hasHeightForWidth());
        sbUnselectedOpacity->setSizePolicy(sizePolicy);
        sbUnselectedOpacity->setDecimals(3);
        sbUnselectedOpacity->setMinimum(0.000000000000000);
        sbUnselectedOpacity->setMaximum(1.000000000000000);
        sbUnselectedOpacity->setSingleStep(0.005000000000000);
        sbUnselectedOpacity->setValue(0.000000000000000);

        gridLayout_6->addWidget(sbUnselectedOpacity, 8, 1, 1, 1);


        gridLayout_3->addWidget(pointGroupBox, 1, 0, 1, 1);

        observerGroupBox = new QGroupBox(settingsWidget);
        observerGroupBox->setObjectName("observerGroupBox");
        gridLayout_5 = new QGridLayout(observerGroupBox);
        gridLayout_5->setObjectName("gridLayout_5");
        sbZoomIncrement = new QDoubleSpinBox(observerGroupBox);
        sbZoomIncrement->setObjectName("sbZoomIncrement");
        sizePolicy.setHeightForWidth(sbZoomIncrement->sizePolicy().hasHeightForWidth());
        sbZoomIncrement->setSizePolicy(sizePolicy);
        sbZoomIncrement->setDecimals(3);
        sbZoomIncrement->setMaximum(1000000.000000000000000);
        sbZoomIncrement->setSingleStep(0.005000000000000);

        gridLayout_5->addWidget(sbZoomIncrement, 5, 1, 1, 1);

        lblZoomIncrement = new QLabel(observerGroupBox);
        lblZoomIncrement->setObjectName("lblZoomIncrement");

        gridLayout_5->addWidget(lblZoomIncrement, 5, 0, 1, 1);


        gridLayout_3->addWidget(observerGroupBox, 0, 0, 1, 1);


        gridLayout->addWidget(settingsWidget, 1, 0, 1, 1);

        topVerticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(topVerticalSpacer, 0, 0, 1, 1);

        bottomWidget = new QWidget(TFSettingsDialog);
        bottomWidget->setObjectName("bottomWidget");
        gridLayout_2 = new QGridLayout(bottomWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        pbApply = new QPushButton(bottomWidget);
        pbApply->setObjectName("pbApply");

        gridLayout_2->addWidget(pbApply, 0, 1, 1, 1);

        leftHorizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(leftHorizontalSpacer, 0, 0, 1, 1);

        pbCancel = new QPushButton(bottomWidget);
        pbCancel->setObjectName("pbCancel");

        gridLayout_2->addWidget(pbCancel, 0, 2, 1, 1);


        gridLayout->addWidget(bottomWidget, 2, 0, 1, 1);

        bottomVerticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(bottomVerticalSpacer, 3, 0, 1, 1);

        QWidget::setTabOrder(sbZoomIncrement, sbBorderWidth);
        QWidget::setTabOrder(sbBorderWidth, sbBaseOpacity);
        QWidget::setTabOrder(sbBaseOpacity, sbSelectedOpacity);
        QWidget::setTabOrder(sbSelectedOpacity, sbUnselectedOpacity);
        QWidget::setTabOrder(sbUnselectedOpacity, pbApply);
        QWidget::setTabOrder(pbApply, pbCancel);

        retranslateUi(TFSettingsDialog);
        QObject::connect(pbApply, &QPushButton::clicked, TFSettingsDialog, qOverload<>(&QDialog::accept));
        QObject::connect(pbCancel, &QPushButton::clicked, TFSettingsDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(TFSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *TFSettingsDialog)
    {
        TFSettingsDialog->setWindowTitle(QCoreApplication::translate("TFSettingsDialog", "Transfer Function Settings", nullptr));
        pointGroupBox->setTitle(QCoreApplication::translate("TFSettingsDialog", "Pivot", nullptr));
        cbPivotLabel->setText(QCoreApplication::translate("TFSettingsDialog", "Enabled", nullptr));
        lblSelectedOpacity->setText(QCoreApplication::translate("TFSettingsDialog", "Selected opacity:", nullptr));
        lblBaseBgOpacity->setText(QCoreApplication::translate("TFSettingsDialog", "Base opacity:", nullptr));
        lbPivotLabel->setText(QCoreApplication::translate("TFSettingsDialog", "Pivot label:", nullptr));
        lbBorderWidth->setText(QCoreApplication::translate("TFSettingsDialog", "Border width:", nullptr));
        lblSize->setText(QCoreApplication::translate("TFSettingsDialog", "Size:", nullptr));
        lblUnselectedOpacity->setText(QCoreApplication::translate("TFSettingsDialog", "Unselected  opacity:", nullptr));
        observerGroupBox->setTitle(QCoreApplication::translate("TFSettingsDialog", "Observer", nullptr));
        lblZoomIncrement->setText(QCoreApplication::translate("TFSettingsDialog", "Zoom increment:", nullptr));
        pbApply->setText(QCoreApplication::translate("TFSettingsDialog", "Apply", nullptr));
#if QT_CONFIG(shortcut)
        pbApply->setShortcut(QCoreApplication::translate("TFSettingsDialog", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        pbCancel->setText(QCoreApplication::translate("TFSettingsDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TFSettingsDialog: public Ui_TFSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TFSETTINGSDIALOG_H
