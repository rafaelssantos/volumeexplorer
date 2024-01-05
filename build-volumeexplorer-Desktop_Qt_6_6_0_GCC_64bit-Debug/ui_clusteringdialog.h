/********************************************************************************
** Form generated from reading UI file 'clusteringdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLUSTERINGDIALOG_H
#define UI_CLUSTERINGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClusteringDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBoxRepresenSelect;
    QGridLayout *gridLayout_6;
    QLabel *lblAlpha;
    QDoubleSpinBox *sbAlpha;
    QGroupBox *groupBoxDBSCAN;
    QGridLayout *gridLayout_5;
    QLabel *lblMinPoints;
    QLabel *lblEps;
    QSpinBox *sbMinPoints;
    QDoubleSpinBox *sbEps;
    QSpacerItem *bottomVerticalSpacer;
    QSpacerItem *topVerticalSpacer;
    QWidget *bottomWidget;
    QGridLayout *gridLayout_2;
    QPushButton *pbApply;
    QPushButton *pbCancel;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *ClusteringDialog)
    {
        if (ClusteringDialog->objectName().isEmpty())
            ClusteringDialog->setObjectName("ClusteringDialog");
        ClusteringDialog->setWindowModality(Qt::ApplicationModal);
        ClusteringDialog->resize(390, 257);
        ClusteringDialog->setFocusPolicy(Qt::StrongFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ui/icons/vex_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        ClusteringDialog->setWindowIcon(icon);
        ClusteringDialog->setModal(true);
        gridLayout = new QGridLayout(ClusteringDialog);
        gridLayout->setObjectName("gridLayout");
        groupBoxRepresenSelect = new QGroupBox(ClusteringDialog);
        groupBoxRepresenSelect->setObjectName("groupBoxRepresenSelect");
        gridLayout_6 = new QGridLayout(groupBoxRepresenSelect);
        gridLayout_6->setObjectName("gridLayout_6");
        lblAlpha = new QLabel(groupBoxRepresenSelect);
        lblAlpha->setObjectName("lblAlpha");

        gridLayout_6->addWidget(lblAlpha, 1, 0, 1, 1);

        sbAlpha = new QDoubleSpinBox(groupBoxRepresenSelect);
        sbAlpha->setObjectName("sbAlpha");
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sbAlpha->sizePolicy().hasHeightForWidth());
        sbAlpha->setSizePolicy(sizePolicy);
        sbAlpha->setDecimals(3);
        sbAlpha->setMinimum(0.000000000000000);
        sbAlpha->setMaximum(1.000000000000000);
        sbAlpha->setSingleStep(0.010000000000000);
        sbAlpha->setValue(0.500000000000000);

        gridLayout_6->addWidget(sbAlpha, 1, 1, 1, 1);


        gridLayout->addWidget(groupBoxRepresenSelect, 2, 0, 1, 1);

        groupBoxDBSCAN = new QGroupBox(ClusteringDialog);
        groupBoxDBSCAN->setObjectName("groupBoxDBSCAN");
        gridLayout_5 = new QGridLayout(groupBoxDBSCAN);
        gridLayout_5->setObjectName("gridLayout_5");
        lblMinPoints = new QLabel(groupBoxDBSCAN);
        lblMinPoints->setObjectName("lblMinPoints");

        gridLayout_5->addWidget(lblMinPoints, 1, 0, 1, 1);

        lblEps = new QLabel(groupBoxDBSCAN);
        lblEps->setObjectName("lblEps");

        gridLayout_5->addWidget(lblEps, 2, 0, 1, 1);

        sbMinPoints = new QSpinBox(groupBoxDBSCAN);
        sbMinPoints->setObjectName("sbMinPoints");
        sizePolicy.setHeightForWidth(sbMinPoints->sizePolicy().hasHeightForWidth());
        sbMinPoints->setSizePolicy(sizePolicy);
        sbMinPoints->setMinimum(1);
        sbMinPoints->setMaximum(1000000000);
        sbMinPoints->setSingleStep(1);
        sbMinPoints->setValue(2);

        gridLayout_5->addWidget(sbMinPoints, 1, 1, 1, 1);

        sbEps = new QDoubleSpinBox(groupBoxDBSCAN);
        sbEps->setObjectName("sbEps");
        sizePolicy.setHeightForWidth(sbEps->sizePolicy().hasHeightForWidth());
        sbEps->setSizePolicy(sizePolicy);
        sbEps->setDecimals(3);
        sbEps->setMinimum(0.000000000000000);
        sbEps->setMaximum(1000000000.000000000000000);
        sbEps->setSingleStep(0.010000000000000);
        sbEps->setValue(0.100000000000000);

        gridLayout_5->addWidget(sbEps, 2, 1, 1, 1);


        gridLayout->addWidget(groupBoxDBSCAN, 1, 0, 1, 1);

        bottomVerticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(bottomVerticalSpacer, 4, 0, 1, 1);

        topVerticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(topVerticalSpacer, 0, 0, 1, 1);

        bottomWidget = new QWidget(ClusteringDialog);
        bottomWidget->setObjectName("bottomWidget");
        gridLayout_2 = new QGridLayout(bottomWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        pbApply = new QPushButton(bottomWidget);
        pbApply->setObjectName("pbApply");
        pbApply->setAutoDefault(false);

        gridLayout_2->addWidget(pbApply, 0, 1, 1, 1);

        pbCancel = new QPushButton(bottomWidget);
        pbCancel->setObjectName("pbCancel");
        pbCancel->setAutoDefault(false);

        gridLayout_2->addWidget(pbCancel, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);


        gridLayout->addWidget(bottomWidget, 3, 0, 1, 1);

        QWidget::setTabOrder(sbMinPoints, sbEps);
        QWidget::setTabOrder(sbEps, sbAlpha);
        QWidget::setTabOrder(sbAlpha, pbApply);
        QWidget::setTabOrder(pbApply, pbCancel);

        retranslateUi(ClusteringDialog);
        QObject::connect(pbCancel, &QPushButton::clicked, ClusteringDialog, qOverload<>(&QDialog::reject));
        QObject::connect(pbApply, &QPushButton::clicked, ClusteringDialog, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(ClusteringDialog);
    } // setupUi

    void retranslateUi(QDialog *ClusteringDialog)
    {
        ClusteringDialog->setWindowTitle(QCoreApplication::translate("ClusteringDialog", "Clustering and Pivot Selection", nullptr));
        groupBoxRepresenSelect->setTitle(QCoreApplication::translate("ClusteringDialog", "Sparse Spatial Selection", nullptr));
        lblAlpha->setText(QCoreApplication::translate("ClusteringDialog", "Alpha:", nullptr));
#if QT_CONFIG(tooltip)
        sbAlpha->setToolTip(QCoreApplication::translate("ClusteringDialog", "Normalized value [0.000001, 1].", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBoxDBSCAN->setTitle(QCoreApplication::translate("ClusteringDialog", "DBSCAN", nullptr));
        lblMinPoints->setText(QCoreApplication::translate("ClusteringDialog", "Minimum number of points: ", nullptr));
        lblEps->setText(QCoreApplication::translate("ClusteringDialog", "Epsilon:", nullptr));
#if QT_CONFIG(tooltip)
        sbEps->setToolTip(QCoreApplication::translate("ClusteringDialog", "Normalized value [0.000001, 1].", nullptr));
#endif // QT_CONFIG(tooltip)
        pbApply->setText(QCoreApplication::translate("ClusteringDialog", "OK", nullptr));
#if QT_CONFIG(shortcut)
        pbApply->setShortcut(QCoreApplication::translate("ClusteringDialog", "Enter", nullptr));
#endif // QT_CONFIG(shortcut)
        pbCancel->setText(QCoreApplication::translate("ClusteringDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClusteringDialog: public Ui_ClusteringDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLUSTERINGDIALOG_H
