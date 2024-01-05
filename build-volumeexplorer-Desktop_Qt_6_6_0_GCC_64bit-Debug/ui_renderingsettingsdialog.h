/********************************************************************************
** Form generated from reading UI file 'renderingsettingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENDERINGSETTINGSDIALOG_H
#define UI_RENDERINGSETTINGSDIALOG_H

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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RenderingSettingsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *topVerticalSpacer;
    QWidget *settingsWidget;
    QGridLayout *gridLayout_2;
    QGroupBox *ViewerGroupBox;
    QGridLayout *gridLayout_4;
    QLabel *lblRotationDegree;
    QLabel *lblZoomIncrement;
    QDoubleSpinBox *sbRotationDegree;
    QDoubleSpinBox *sbZoomIncrement;
    QGroupBox *cudaGroupBox;
    QGridLayout *gridLayout_3;
    QSpinBox *sbBlockDimZ;
    QLabel *lblBlockDim;
    QSpinBox *sbBlockDimX;
    QSpinBox *sbBlockDimY;
    QCheckBox *cbDevSyncronize;
    QLabel *lblDevSyncronize;
    QGroupBox *rayCastingGroupBox;
    QGridLayout *gridLayout_5;
    QLabel *lblMaxOpacity;
    QSpinBox *sbMaxNumberOfSteps;
    QDoubleSpinBox *sbMaxOpacity;
    QRadioButton *rbNearest;
    QLabel *lblInterpolation;
    QDoubleSpinBox *sbStepLength;
    QLabel *lbMaxNumberOfSteps;
    QLabel *lblStep;
    QRadioButton *rbTrilinear;
    QGroupBox *illuminationGroupBox;
    QGridLayout *gridLayout_6;
    QSlider *sdAmbient;
    QLabel *lblDiffuse;
    QCheckBox *cbEnabled;
    QSlider *sdDiffuse;
    QLabel *lblSpecular;
    QLabel *lblAmbient;
    QSlider *sdSpecular;
    QSpinBox *sbAmbient;
    QSpinBox *sbDiffuse;
    QSpinBox *sbSpecular;
    QSpinBox *spShininess;
    QLabel *lblShininess;
    QWidget *bottomWidget;
    QGridLayout *gridLayout;
    QSpacerItem *leftHorizontalSpacer;
    QPushButton *pbCancel;
    QPushButton *pbApply;
    QSpacerItem *bottomVerticalSpacer;

    void setupUi(QDialog *RenderingSettingsDialog)
    {
        if (RenderingSettingsDialog->objectName().isEmpty())
            RenderingSettingsDialog->setObjectName("RenderingSettingsDialog");
        RenderingSettingsDialog->setWindowModality(Qt::ApplicationModal);
        RenderingSettingsDialog->resize(500, 703);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RenderingSettingsDialog->sizePolicy().hasHeightForWidth());
        RenderingSettingsDialog->setSizePolicy(sizePolicy);
        RenderingSettingsDialog->setFocusPolicy(Qt::StrongFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ui/icons/vex_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        RenderingSettingsDialog->setWindowIcon(icon);
        RenderingSettingsDialog->setSizeGripEnabled(false);
        RenderingSettingsDialog->setModal(true);
        verticalLayout = new QVBoxLayout(RenderingSettingsDialog);
        verticalLayout->setObjectName("verticalLayout");
        topVerticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(topVerticalSpacer);

        settingsWidget = new QWidget(RenderingSettingsDialog);
        settingsWidget->setObjectName("settingsWidget");
        gridLayout_2 = new QGridLayout(settingsWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        ViewerGroupBox = new QGroupBox(settingsWidget);
        ViewerGroupBox->setObjectName("ViewerGroupBox");
        gridLayout_4 = new QGridLayout(ViewerGroupBox);
        gridLayout_4->setObjectName("gridLayout_4");
        lblRotationDegree = new QLabel(ViewerGroupBox);
        lblRotationDegree->setObjectName("lblRotationDegree");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblRotationDegree->sizePolicy().hasHeightForWidth());
        lblRotationDegree->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(lblRotationDegree, 2, 0, 1, 1);

        lblZoomIncrement = new QLabel(ViewerGroupBox);
        lblZoomIncrement->setObjectName("lblZoomIncrement");
        sizePolicy1.setHeightForWidth(lblZoomIncrement->sizePolicy().hasHeightForWidth());
        lblZoomIncrement->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(lblZoomIncrement, 1, 0, 1, 1);

        sbRotationDegree = new QDoubleSpinBox(ViewerGroupBox);
        sbRotationDegree->setObjectName("sbRotationDegree");
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sbRotationDegree->sizePolicy().hasHeightForWidth());
        sbRotationDegree->setSizePolicy(sizePolicy2);
        sbRotationDegree->setDecimals(3);
        sbRotationDegree->setMinimum(0.000000000000000);
        sbRotationDegree->setMaximum(360.000000000000000);
        sbRotationDegree->setValue(0.000000000000000);

        gridLayout_4->addWidget(sbRotationDegree, 2, 1, 1, 2);

        sbZoomIncrement = new QDoubleSpinBox(ViewerGroupBox);
        sbZoomIncrement->setObjectName("sbZoomIncrement");
        sizePolicy2.setHeightForWidth(sbZoomIncrement->sizePolicy().hasHeightForWidth());
        sbZoomIncrement->setSizePolicy(sizePolicy2);
        sbZoomIncrement->setDecimals(3);
        sbZoomIncrement->setMaximum(1000000000.000000000000000);
        sbZoomIncrement->setSingleStep(0.001000000000000);

        gridLayout_4->addWidget(sbZoomIncrement, 1, 1, 1, 2);


        gridLayout_2->addWidget(ViewerGroupBox, 1, 0, 1, 1);

        cudaGroupBox = new QGroupBox(settingsWidget);
        cudaGroupBox->setObjectName("cudaGroupBox");
        gridLayout_3 = new QGridLayout(cudaGroupBox);
        gridLayout_3->setObjectName("gridLayout_3");
        sbBlockDimZ = new QSpinBox(cudaGroupBox);
        sbBlockDimZ->setObjectName("sbBlockDimZ");
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(sbBlockDimZ->sizePolicy().hasHeightForWidth());
        sbBlockDimZ->setSizePolicy(sizePolicy3);
        sbBlockDimZ->setMinimum(1);
        sbBlockDimZ->setMaximum(1000000000);
        sbBlockDimZ->setSingleStep(1);

        gridLayout_3->addWidget(sbBlockDimZ, 1, 5, 1, 1);

        lblBlockDim = new QLabel(cudaGroupBox);
        lblBlockDim->setObjectName("lblBlockDim");

        gridLayout_3->addWidget(lblBlockDim, 1, 1, 1, 1);

        sbBlockDimX = new QSpinBox(cudaGroupBox);
        sbBlockDimX->setObjectName("sbBlockDimX");
        sizePolicy3.setHeightForWidth(sbBlockDimX->sizePolicy().hasHeightForWidth());
        sbBlockDimX->setSizePolicy(sizePolicy3);
        sbBlockDimX->setMinimum(1);
        sbBlockDimX->setMaximum(1000000000);

        gridLayout_3->addWidget(sbBlockDimX, 1, 3, 1, 1);

        sbBlockDimY = new QSpinBox(cudaGroupBox);
        sbBlockDimY->setObjectName("sbBlockDimY");
        sizePolicy3.setHeightForWidth(sbBlockDimY->sizePolicy().hasHeightForWidth());
        sbBlockDimY->setSizePolicy(sizePolicy3);
        sbBlockDimY->setMinimum(1);
        sbBlockDimY->setMaximum(1000000000);
        sbBlockDimY->setSingleStep(1);

        gridLayout_3->addWidget(sbBlockDimY, 1, 4, 1, 1);

        cbDevSyncronize = new QCheckBox(cudaGroupBox);
        cbDevSyncronize->setObjectName("cbDevSyncronize");

        gridLayout_3->addWidget(cbDevSyncronize, 2, 5, 1, 1);

        lblDevSyncronize = new QLabel(cudaGroupBox);
        lblDevSyncronize->setObjectName("lblDevSyncronize");

        gridLayout_3->addWidget(lblDevSyncronize, 2, 1, 1, 3);


        gridLayout_2->addWidget(cudaGroupBox, 0, 0, 1, 1);

        rayCastingGroupBox = new QGroupBox(settingsWidget);
        rayCastingGroupBox->setObjectName("rayCastingGroupBox");
        gridLayout_5 = new QGridLayout(rayCastingGroupBox);
        gridLayout_5->setObjectName("gridLayout_5");
        lblMaxOpacity = new QLabel(rayCastingGroupBox);
        lblMaxOpacity->setObjectName("lblMaxOpacity");

        gridLayout_5->addWidget(lblMaxOpacity, 2, 0, 1, 1);

        sbMaxNumberOfSteps = new QSpinBox(rayCastingGroupBox);
        sbMaxNumberOfSteps->setObjectName("sbMaxNumberOfSteps");
        sizePolicy3.setHeightForWidth(sbMaxNumberOfSteps->sizePolicy().hasHeightForWidth());
        sbMaxNumberOfSteps->setSizePolicy(sizePolicy3);
        sbMaxNumberOfSteps->setMinimum(1);
        sbMaxNumberOfSteps->setMaximum(1000000000);
        sbMaxNumberOfSteps->setSingleStep(100);
        sbMaxNumberOfSteps->setValue(100);

        gridLayout_5->addWidget(sbMaxNumberOfSteps, 4, 1, 1, 2);

        sbMaxOpacity = new QDoubleSpinBox(rayCastingGroupBox);
        sbMaxOpacity->setObjectName("sbMaxOpacity");
        sizePolicy3.setHeightForWidth(sbMaxOpacity->sizePolicy().hasHeightForWidth());
        sbMaxOpacity->setSizePolicy(sizePolicy3);
        sbMaxOpacity->setDecimals(3);
        sbMaxOpacity->setMinimum(0.000000000000000);
        sbMaxOpacity->setMaximum(1.000000000000000);
        sbMaxOpacity->setSingleStep(0.050000000000000);
        sbMaxOpacity->setValue(0.000000000000000);

        gridLayout_5->addWidget(sbMaxOpacity, 2, 1, 1, 2);

        rbNearest = new QRadioButton(rayCastingGroupBox);
        rbNearest->setObjectName("rbNearest");
        rbNearest->setChecked(true);

        gridLayout_5->addWidget(rbNearest, 6, 1, 1, 1);

        lblInterpolation = new QLabel(rayCastingGroupBox);
        lblInterpolation->setObjectName("lblInterpolation");

        gridLayout_5->addWidget(lblInterpolation, 6, 0, 2, 1);

        sbStepLength = new QDoubleSpinBox(rayCastingGroupBox);
        sbStepLength->setObjectName("sbStepLength");
        sizePolicy3.setHeightForWidth(sbStepLength->sizePolicy().hasHeightForWidth());
        sbStepLength->setSizePolicy(sizePolicy3);
        sbStepLength->setProperty("showGroupSeparator", QVariant(false));
        sbStepLength->setDecimals(3);
        sbStepLength->setMaximum(1000000.000000000000000);
        sbStepLength->setSingleStep(0.050000000000000);
        sbStepLength->setValue(0.000000000000000);

        gridLayout_5->addWidget(sbStepLength, 3, 1, 1, 2);

        lbMaxNumberOfSteps = new QLabel(rayCastingGroupBox);
        lbMaxNumberOfSteps->setObjectName("lbMaxNumberOfSteps");

        gridLayout_5->addWidget(lbMaxNumberOfSteps, 4, 0, 1, 1);

        lblStep = new QLabel(rayCastingGroupBox);
        lblStep->setObjectName("lblStep");

        gridLayout_5->addWidget(lblStep, 3, 0, 1, 1);

        rbTrilinear = new QRadioButton(rayCastingGroupBox);
        rbTrilinear->setObjectName("rbTrilinear");

        gridLayout_5->addWidget(rbTrilinear, 6, 2, 1, 1);


        gridLayout_2->addWidget(rayCastingGroupBox, 4, 0, 1, 1);

        illuminationGroupBox = new QGroupBox(settingsWidget);
        illuminationGroupBox->setObjectName("illuminationGroupBox");
        gridLayout_6 = new QGridLayout(illuminationGroupBox);
        gridLayout_6->setObjectName("gridLayout_6");
        sdAmbient = new QSlider(illuminationGroupBox);
        sdAmbient->setObjectName("sdAmbient");
        sdAmbient->setEnabled(false);
        sizePolicy2.setHeightForWidth(sdAmbient->sizePolicy().hasHeightForWidth());
        sdAmbient->setSizePolicy(sizePolicy2);
        sdAmbient->setMaximum(200);
        sdAmbient->setSingleStep(10);
        sdAmbient->setPageStep(10);
        sdAmbient->setValue(0);
        sdAmbient->setSliderPosition(0);
        sdAmbient->setTracking(true);
        sdAmbient->setOrientation(Qt::Horizontal);
        sdAmbient->setTickPosition(QSlider::TicksAbove);
        sdAmbient->setTickInterval(10);

        gridLayout_6->addWidget(sdAmbient, 1, 1, 1, 1);

        lblDiffuse = new QLabel(illuminationGroupBox);
        lblDiffuse->setObjectName("lblDiffuse");
        lblDiffuse->setEnabled(false);

        gridLayout_6->addWidget(lblDiffuse, 2, 0, 1, 1);

        cbEnabled = new QCheckBox(illuminationGroupBox);
        cbEnabled->setObjectName("cbEnabled");
        cbEnabled->setChecked(false);

        gridLayout_6->addWidget(cbEnabled, 0, 0, 1, 1);

        sdDiffuse = new QSlider(illuminationGroupBox);
        sdDiffuse->setObjectName("sdDiffuse");
        sdDiffuse->setEnabled(false);
        sizePolicy3.setHeightForWidth(sdDiffuse->sizePolicy().hasHeightForWidth());
        sdDiffuse->setSizePolicy(sizePolicy3);
        sdDiffuse->setMaximum(200);
        sdDiffuse->setSingleStep(10);
        sdDiffuse->setPageStep(10);
        sdDiffuse->setValue(0);
        sdDiffuse->setSliderPosition(0);
        sdDiffuse->setOrientation(Qt::Horizontal);
        sdDiffuse->setTickPosition(QSlider::TicksAbove);
        sdDiffuse->setTickInterval(10);

        gridLayout_6->addWidget(sdDiffuse, 2, 1, 1, 1);

        lblSpecular = new QLabel(illuminationGroupBox);
        lblSpecular->setObjectName("lblSpecular");
        lblSpecular->setEnabled(false);

        gridLayout_6->addWidget(lblSpecular, 3, 0, 1, 1);

        lblAmbient = new QLabel(illuminationGroupBox);
        lblAmbient->setObjectName("lblAmbient");
        lblAmbient->setEnabled(false);

        gridLayout_6->addWidget(lblAmbient, 1, 0, 1, 1);

        sdSpecular = new QSlider(illuminationGroupBox);
        sdSpecular->setObjectName("sdSpecular");
        sdSpecular->setEnabled(false);
        sizePolicy3.setHeightForWidth(sdSpecular->sizePolicy().hasHeightForWidth());
        sdSpecular->setSizePolicy(sizePolicy3);
        sdSpecular->setMaximum(200);
        sdSpecular->setSingleStep(10);
        sdSpecular->setPageStep(10);
        sdSpecular->setValue(0);
        sdSpecular->setSliderPosition(0);
        sdSpecular->setOrientation(Qt::Horizontal);
        sdSpecular->setTickPosition(QSlider::TicksAbove);
        sdSpecular->setTickInterval(10);

        gridLayout_6->addWidget(sdSpecular, 3, 1, 1, 1);

        sbAmbient = new QSpinBox(illuminationGroupBox);
        sbAmbient->setObjectName("sbAmbient");
        sbAmbient->setEnabled(false);
        sbAmbient->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        sbAmbient->setProperty("showGroupSeparator", QVariant(false));
        sbAmbient->setMaximum(200);
        sbAmbient->setSingleStep(5);
        sbAmbient->setValue(0);

        gridLayout_6->addWidget(sbAmbient, 1, 2, 1, 1);

        sbDiffuse = new QSpinBox(illuminationGroupBox);
        sbDiffuse->setObjectName("sbDiffuse");
        sbDiffuse->setEnabled(false);
        sbDiffuse->setAccelerated(false);
        sbDiffuse->setMaximum(200);
        sbDiffuse->setSingleStep(5);
        sbDiffuse->setValue(0);
        sbDiffuse->setDisplayIntegerBase(10);

        gridLayout_6->addWidget(sbDiffuse, 2, 2, 1, 1);

        sbSpecular = new QSpinBox(illuminationGroupBox);
        sbSpecular->setObjectName("sbSpecular");
        sbSpecular->setEnabled(false);
        sbSpecular->setMaximum(200);
        sbSpecular->setSingleStep(5);
        sbSpecular->setStepType(QAbstractSpinBox::DefaultStepType);
        sbSpecular->setValue(0);

        gridLayout_6->addWidget(sbSpecular, 3, 2, 1, 1);

        spShininess = new QSpinBox(illuminationGroupBox);
        spShininess->setObjectName("spShininess");
        spShininess->setEnabled(false);
        spShininess->setMinimum(0);
        spShininess->setMaximum(1024);
        spShininess->setSingleStep(2);
        spShininess->setValue(2);

        gridLayout_6->addWidget(spShininess, 4, 2, 1, 1);

        lblShininess = new QLabel(illuminationGroupBox);
        lblShininess->setObjectName("lblShininess");
        lblShininess->setEnabled(false);

        gridLayout_6->addWidget(lblShininess, 4, 0, 1, 2);


        gridLayout_2->addWidget(illuminationGroupBox, 2, 0, 1, 1);


        verticalLayout->addWidget(settingsWidget);

        bottomWidget = new QWidget(RenderingSettingsDialog);
        bottomWidget->setObjectName("bottomWidget");
        gridLayout = new QGridLayout(bottomWidget);
        gridLayout->setObjectName("gridLayout");
        leftHorizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(leftHorizontalSpacer, 0, 0, 1, 1);

        pbCancel = new QPushButton(bottomWidget);
        pbCancel->setObjectName("pbCancel");

        gridLayout->addWidget(pbCancel, 0, 2, 1, 1);

        pbApply = new QPushButton(bottomWidget);
        pbApply->setObjectName("pbApply");

        gridLayout->addWidget(pbApply, 0, 1, 1, 1);


        verticalLayout->addWidget(bottomWidget);

        bottomVerticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(bottomVerticalSpacer);

        QWidget::setTabOrder(sbBlockDimX, sbBlockDimY);
        QWidget::setTabOrder(sbBlockDimY, sbBlockDimZ);
        QWidget::setTabOrder(sbBlockDimZ, sbZoomIncrement);
        QWidget::setTabOrder(sbZoomIncrement, sbRotationDegree);
        QWidget::setTabOrder(sbRotationDegree, cbEnabled);
        QWidget::setTabOrder(cbEnabled, sdAmbient);
        QWidget::setTabOrder(sdAmbient, sbAmbient);
        QWidget::setTabOrder(sbAmbient, sdDiffuse);
        QWidget::setTabOrder(sdDiffuse, sbDiffuse);
        QWidget::setTabOrder(sbDiffuse, sdSpecular);
        QWidget::setTabOrder(sdSpecular, sbSpecular);
        QWidget::setTabOrder(sbSpecular, spShininess);
        QWidget::setTabOrder(spShininess, sbMaxOpacity);
        QWidget::setTabOrder(sbMaxOpacity, sbStepLength);
        QWidget::setTabOrder(sbStepLength, sbMaxNumberOfSteps);
        QWidget::setTabOrder(sbMaxNumberOfSteps, rbNearest);
        QWidget::setTabOrder(rbNearest, pbApply);
        QWidget::setTabOrder(pbApply, pbCancel);

        retranslateUi(RenderingSettingsDialog);
        QObject::connect(pbApply, &QPushButton::clicked, RenderingSettingsDialog, qOverload<>(&QDialog::accept));
        QObject::connect(pbCancel, &QPushButton::clicked, RenderingSettingsDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(RenderingSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *RenderingSettingsDialog)
    {
        RenderingSettingsDialog->setWindowTitle(QCoreApplication::translate("RenderingSettingsDialog", "Rendering Settings", nullptr));
        ViewerGroupBox->setTitle(QCoreApplication::translate("RenderingSettingsDialog", "Viewer", nullptr));
        lblRotationDegree->setText(QCoreApplication::translate("RenderingSettingsDialog", "Rotation degree:", nullptr));
        lblZoomIncrement->setText(QCoreApplication::translate("RenderingSettingsDialog", "Zoom increment:", nullptr));
        cudaGroupBox->setTitle(QCoreApplication::translate("RenderingSettingsDialog", "CUDA", nullptr));
        lblBlockDim->setText(QCoreApplication::translate("RenderingSettingsDialog", "Block size:", nullptr));
        cbDevSyncronize->setText(QCoreApplication::translate("RenderingSettingsDialog", "Enabled", nullptr));
        lblDevSyncronize->setText(QCoreApplication::translate("RenderingSettingsDialog", "Device Syncronization:", nullptr));
        rayCastingGroupBox->setTitle(QCoreApplication::translate("RenderingSettingsDialog", "Ray Casting", nullptr));
        lblMaxOpacity->setText(QCoreApplication::translate("RenderingSettingsDialog", "Maximum opacity:", nullptr));
        rbNearest->setText(QCoreApplication::translate("RenderingSettingsDialog", "Nearest", nullptr));
        lblInterpolation->setText(QCoreApplication::translate("RenderingSettingsDialog", "Interpolation Scheme:", nullptr));
        lbMaxNumberOfSteps->setText(QCoreApplication::translate("RenderingSettingsDialog", "Maximum number of steps:", nullptr));
        lblStep->setText(QCoreApplication::translate("RenderingSettingsDialog", "Step length:", nullptr));
        rbTrilinear->setText(QCoreApplication::translate("RenderingSettingsDialog", "Trilinear", nullptr));
        illuminationGroupBox->setTitle(QCoreApplication::translate("RenderingSettingsDialog", "Illumination", nullptr));
        lblDiffuse->setText(QCoreApplication::translate("RenderingSettingsDialog", "Diffuse:", nullptr));
        cbEnabled->setText(QCoreApplication::translate("RenderingSettingsDialog", "Enabled", nullptr));
        lblSpecular->setText(QCoreApplication::translate("RenderingSettingsDialog", "Specular:", nullptr));
        lblAmbient->setText(QCoreApplication::translate("RenderingSettingsDialog", "Ambient: ", nullptr));
        sbAmbient->setSuffix(QCoreApplication::translate("RenderingSettingsDialog", "%", nullptr));
        sbAmbient->setPrefix(QString());
        sbDiffuse->setSuffix(QCoreApplication::translate("RenderingSettingsDialog", "%", nullptr));
        sbSpecular->setSuffix(QCoreApplication::translate("RenderingSettingsDialog", "%", nullptr));
        lblShininess->setText(QCoreApplication::translate("RenderingSettingsDialog", "Shininess:", nullptr));
        pbCancel->setText(QCoreApplication::translate("RenderingSettingsDialog", "Cancel", nullptr));
        pbApply->setText(QCoreApplication::translate("RenderingSettingsDialog", "Apply", nullptr));
#if QT_CONFIG(shortcut)
        pbApply->setShortcut(QCoreApplication::translate("RenderingSettingsDialog", "Enter", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class RenderingSettingsDialog: public Ui_RenderingSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDERINGSETTINGSDIALOG_H
