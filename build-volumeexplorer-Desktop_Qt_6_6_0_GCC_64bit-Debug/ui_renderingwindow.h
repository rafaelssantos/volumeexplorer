/********************************************************************************
** Form generated from reading UI file 'renderingwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENDERINGWINDOW_H
#define UI_RENDERINGWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "ui/rendering/renderingwidget.h"

QT_BEGIN_NAMESPACE

class Ui_RenderingWindow
{
public:
    QAction *actionSettings;
    QAction *actionOpenDataset;
    QAction *actionTFDesigner;
    QAction *actionExportScreenshot;
    QAction *actionSaveViewer;
    QAction *actionOpenViewer;
    QAction *actionDisplayInfo;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    RenderingWidget *volumeWidget;
    QWidget *controlWidget;
    QGridLayout *gridLayout_2;
    QSpacerItem *bottomVerticalSpacer;
    QGroupBox *groupBoxControl;
    QGridLayout *gridLayout_3;
    QToolButton *tbRefresh;
    QGroupBox *groupBoxRotation;
    QGridLayout *gridLayout_5;
    QLabel *lblZ;
    QToolButton *tbYRight;
    QToolButton *tbZLeft;
    QToolButton *tbXRight;
    QToolButton *tbXLeft;
    QLabel *lblY;
    QLabel *lblX;
    QToolButton *tbYLeft;
    QToolButton *tbZRight;
    QSpacerItem *internalTopHorLeftSpacer;
    QSpacerItem *internalTopHorRightSpacer;
    QSpacerItem *internalMidHorLeftSpacer;
    QSpacerItem *internalMidHorRightSpacer;
    QSpacerItem *internalBotHorLeftSpacer;
    QSpacerItem *internalBotHorRightSpacer;
    QGroupBox *groupBoxZoom;
    QHBoxLayout *horizontalLayout;
    QToolButton *tbZoomIn;
    QToolButton *tbZoomOut;
    QToolButton *tbRestore;
    QCheckBox *cbHighQuality;
    QSpacerItem *topVerticalSpacer;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuView;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RenderingWindow)
    {
        if (RenderingWindow->objectName().isEmpty())
            RenderingWindow->setObjectName("RenderingWindow");
        RenderingWindow->resize(640, 480);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/vex_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        RenderingWindow->setWindowIcon(icon);
        actionSettings = new QAction(RenderingWindow);
        actionSettings->setObjectName("actionSettings");
        actionOpenDataset = new QAction(RenderingWindow);
        actionOpenDataset->setObjectName("actionOpenDataset");
        actionTFDesigner = new QAction(RenderingWindow);
        actionTFDesigner->setObjectName("actionTFDesigner");
        actionTFDesigner->setShortcutContext(Qt::ApplicationShortcut);
        actionExportScreenshot = new QAction(RenderingWindow);
        actionExportScreenshot->setObjectName("actionExportScreenshot");
        actionSaveViewer = new QAction(RenderingWindow);
        actionSaveViewer->setObjectName("actionSaveViewer");
        actionOpenViewer = new QAction(RenderingWindow);
        actionOpenViewer->setObjectName("actionOpenViewer");
        actionDisplayInfo = new QAction(RenderingWindow);
        actionDisplayInfo->setObjectName("actionDisplayInfo");
        actionDisplayInfo->setCheckable(true);
        actionDisplayInfo->setChecked(true);
        actionDisplayInfo->setShortcutContext(Qt::ApplicationShortcut);
        centralwidget = new QWidget(RenderingWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        volumeWidget = new RenderingWidget(splitter);
        volumeWidget->setObjectName("volumeWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(volumeWidget->sizePolicy().hasHeightForWidth());
        volumeWidget->setSizePolicy(sizePolicy1);
        volumeWidget->setFocusPolicy(Qt::StrongFocus);
        splitter->addWidget(volumeWidget);
        controlWidget = new QWidget(splitter);
        controlWidget->setObjectName("controlWidget");
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(controlWidget->sizePolicy().hasHeightForWidth());
        controlWidget->setSizePolicy(sizePolicy2);
        controlWidget->setFocusPolicy(Qt::WheelFocus);
        gridLayout_2 = new QGridLayout(controlWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        bottomVerticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout_2->addItem(bottomVerticalSpacer, 2, 0, 1, 1);

        groupBoxControl = new QGroupBox(controlWidget);
        groupBoxControl->setObjectName("groupBoxControl");
        sizePolicy2.setHeightForWidth(groupBoxControl->sizePolicy().hasHeightForWidth());
        groupBoxControl->setSizePolicy(sizePolicy2);
        gridLayout_3 = new QGridLayout(groupBoxControl);
        gridLayout_3->setObjectName("gridLayout_3");
        tbRefresh = new QToolButton(groupBoxControl);
        tbRefresh->setObjectName("tbRefresh");
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tbRefresh->sizePolicy().hasHeightForWidth());
        tbRefresh->setSizePolicy(sizePolicy3);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbRefresh->setIcon(icon1);
        tbRefresh->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(tbRefresh, 3, 1, 1, 1);

        groupBoxRotation = new QGroupBox(groupBoxControl);
        groupBoxRotation->setObjectName("groupBoxRotation");
        sizePolicy2.setHeightForWidth(groupBoxRotation->sizePolicy().hasHeightForWidth());
        groupBoxRotation->setSizePolicy(sizePolicy2);
        groupBoxRotation->setFlat(false);
        gridLayout_5 = new QGridLayout(groupBoxRotation);
        gridLayout_5->setObjectName("gridLayout_5");
        lblZ = new QLabel(groupBoxRotation);
        lblZ->setObjectName("lblZ");
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lblZ->sizePolicy().hasHeightForWidth());
        lblZ->setSizePolicy(sizePolicy4);

        gridLayout_5->addWidget(lblZ, 3, 2, 1, 1);

        tbYRight = new QToolButton(groupBoxRotation);
        tbYRight->setObjectName("tbYRight");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/rotate_right.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbYRight->setIcon(icon2);
        tbYRight->setIconSize(QSize(32, 32));
        tbYRight->setAutoRepeat(true);
        tbYRight->setAutoRepeatInterval(0);

        gridLayout_5->addWidget(tbYRight, 1, 4, 1, 1);

        tbZLeft = new QToolButton(groupBoxRotation);
        tbZLeft->setObjectName("tbZLeft");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/rotate_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbZLeft->setIcon(icon3);
        tbZLeft->setIconSize(QSize(32, 32));
        tbZLeft->setAutoRepeat(true);
        tbZLeft->setAutoRepeatInterval(0);

        gridLayout_5->addWidget(tbZLeft, 3, 0, 1, 1);

        tbXRight = new QToolButton(groupBoxRotation);
        tbXRight->setObjectName("tbXRight");
        tbXRight->setIcon(icon2);
        tbXRight->setIconSize(QSize(32, 32));
        tbXRight->setAutoRepeat(true);
        tbXRight->setAutoRepeatInterval(0);
        tbXRight->setAutoRaise(false);

        gridLayout_5->addWidget(tbXRight, 0, 4, 1, 1);

        tbXLeft = new QToolButton(groupBoxRotation);
        tbXLeft->setObjectName("tbXLeft");
        tbXLeft->setIcon(icon3);
        tbXLeft->setIconSize(QSize(32, 32));
        tbXLeft->setAutoRepeat(true);
        tbXLeft->setAutoRepeatInterval(0);
        tbXLeft->setAutoRaise(false);

        gridLayout_5->addWidget(tbXLeft, 0, 0, 1, 1);

        lblY = new QLabel(groupBoxRotation);
        lblY->setObjectName("lblY");
        sizePolicy4.setHeightForWidth(lblY->sizePolicy().hasHeightForWidth());
        lblY->setSizePolicy(sizePolicy4);

        gridLayout_5->addWidget(lblY, 1, 2, 1, 1);

        lblX = new QLabel(groupBoxRotation);
        lblX->setObjectName("lblX");
        sizePolicy4.setHeightForWidth(lblX->sizePolicy().hasHeightForWidth());
        lblX->setSizePolicy(sizePolicy4);
        lblX->setTextFormat(Qt::AutoText);
        lblX->setScaledContents(false);

        gridLayout_5->addWidget(lblX, 0, 2, 1, 1);

        tbYLeft = new QToolButton(groupBoxRotation);
        tbYLeft->setObjectName("tbYLeft");
        tbYLeft->setIcon(icon3);
        tbYLeft->setIconSize(QSize(32, 32));
        tbYLeft->setAutoRepeat(true);
        tbYLeft->setAutoRepeatInterval(0);

        gridLayout_5->addWidget(tbYLeft, 1, 0, 1, 1);

        tbZRight = new QToolButton(groupBoxRotation);
        tbZRight->setObjectName("tbZRight");
        tbZRight->setIcon(icon2);
        tbZRight->setIconSize(QSize(32, 32));
        tbZRight->setAutoRepeat(true);
        tbZRight->setAutoRepeatInterval(0);

        gridLayout_5->addWidget(tbZRight, 3, 4, 1, 1);

        internalTopHorLeftSpacer = new QSpacerItem(0, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(internalTopHorLeftSpacer, 0, 1, 1, 1);

        internalTopHorRightSpacer = new QSpacerItem(0, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(internalTopHorRightSpacer, 0, 3, 1, 1);

        internalMidHorLeftSpacer = new QSpacerItem(0, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(internalMidHorLeftSpacer, 1, 1, 1, 1);

        internalMidHorRightSpacer = new QSpacerItem(0, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(internalMidHorRightSpacer, 1, 3, 1, 1);

        internalBotHorLeftSpacer = new QSpacerItem(0, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(internalBotHorLeftSpacer, 3, 1, 1, 1);

        internalBotHorRightSpacer = new QSpacerItem(0, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(internalBotHorRightSpacer, 3, 3, 1, 1);


        gridLayout_3->addWidget(groupBoxRotation, 2, 0, 1, 2);

        groupBoxZoom = new QGroupBox(groupBoxControl);
        groupBoxZoom->setObjectName("groupBoxZoom");
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(groupBoxZoom->sizePolicy().hasHeightForWidth());
        groupBoxZoom->setSizePolicy(sizePolicy5);
        horizontalLayout = new QHBoxLayout(groupBoxZoom);
        horizontalLayout->setObjectName("horizontalLayout");
        tbZoomIn = new QToolButton(groupBoxZoom);
        tbZoomIn->setObjectName("tbZoomIn");
        sizePolicy3.setHeightForWidth(tbZoomIn->sizePolicy().hasHeightForWidth());
        tbZoomIn->setSizePolicy(sizePolicy3);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/zoom_out.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbZoomIn->setIcon(icon4);
        tbZoomIn->setIconSize(QSize(32, 32));
        tbZoomIn->setAutoRepeat(true);
        tbZoomIn->setAutoRepeatInterval(0);

        horizontalLayout->addWidget(tbZoomIn);

        tbZoomOut = new QToolButton(groupBoxZoom);
        tbZoomOut->setObjectName("tbZoomOut");
        sizePolicy3.setHeightForWidth(tbZoomOut->sizePolicy().hasHeightForWidth());
        tbZoomOut->setSizePolicy(sizePolicy3);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/zoom_in.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbZoomOut->setIcon(icon5);
        tbZoomOut->setIconSize(QSize(32, 32));
        tbZoomOut->setAutoRepeat(true);
        tbZoomOut->setAutoRepeatInterval(0);

        horizontalLayout->addWidget(tbZoomOut);


        gridLayout_3->addWidget(groupBoxZoom, 1, 0, 1, 2);

        tbRestore = new QToolButton(groupBoxControl);
        tbRestore->setObjectName("tbRestore");
        sizePolicy3.setHeightForWidth(tbRestore->sizePolicy().hasHeightForWidth());
        tbRestore->setSizePolicy(sizePolicy3);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/reload.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbRestore->setIcon(icon6);
        tbRestore->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(tbRestore, 3, 0, 1, 1);

        cbHighQuality = new QCheckBox(groupBoxControl);
        cbHighQuality->setObjectName("cbHighQuality");
        cbHighQuality->setChecked(false);

        gridLayout_3->addWidget(cbHighQuality, 4, 0, 1, 2);


        gridLayout_2->addWidget(groupBoxControl, 1, 0, 1, 1);

        topVerticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(topVerticalSpacer, 0, 0, 1, 1);

        splitter->addWidget(controlWidget);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        RenderingWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RenderingWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 640, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        menuView = new QMenu(menubar);
        menuView->setObjectName("menuView");
        RenderingWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(RenderingWindow);
        statusBar->setObjectName("statusBar");
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(statusBar->sizePolicy().hasHeightForWidth());
        statusBar->setSizePolicy(sizePolicy6);
        statusBar->setMinimumSize(QSize(0, 0));
        RenderingWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(controlWidget, tbZoomIn);
        QWidget::setTabOrder(tbZoomIn, tbZoomOut);
        QWidget::setTabOrder(tbZoomOut, tbXLeft);
        QWidget::setTabOrder(tbXLeft, tbXRight);
        QWidget::setTabOrder(tbXRight, tbYLeft);
        QWidget::setTabOrder(tbYLeft, tbYRight);
        QWidget::setTabOrder(tbYRight, tbZLeft);
        QWidget::setTabOrder(tbZLeft, tbZRight);
        QWidget::setTabOrder(tbZRight, tbRestore);
        QWidget::setTabOrder(tbRestore, tbRefresh);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpenDataset);
        menuHelp->addAction(actionSettings);
        menuView->addAction(actionTFDesigner);
        menuView->addAction(actionExportScreenshot);
        menuView->addAction(actionDisplayInfo);

        retranslateUi(RenderingWindow);

        QMetaObject::connectSlotsByName(RenderingWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RenderingWindow)
    {
        RenderingWindow->setWindowTitle(QCoreApplication::translate("RenderingWindow", "Volume Window - Volume Explorer (VEx)", nullptr));
        actionSettings->setText(QCoreApplication::translate("RenderingWindow", "Settings", nullptr));
#if QT_CONFIG(shortcut)
        actionSettings->setShortcut(QCoreApplication::translate("RenderingWindow", "F12", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpenDataset->setText(QCoreApplication::translate("RenderingWindow", "Open dataset", nullptr));
#if QT_CONFIG(tooltip)
        actionOpenDataset->setToolTip(QCoreApplication::translate("RenderingWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Load dataset and duplicate data to device. </span></p><p><span style=\" font-weight:600;\">Be aware of memory usage on large datasets. Each voxel comprises of three floats (normal vector) and one byte.</span></p><p>Shortcut: <span style=\" font-style:italic;\">CTrl  </span>+ <span style=\" font-style:italic;\">O</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionOpenDataset->setShortcut(QCoreApplication::translate("RenderingWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionTFDesigner->setText(QCoreApplication::translate("RenderingWindow", "Show Transfer Function Designer", nullptr));
#if QT_CONFIG(tooltip)
        actionTFDesigner->setToolTip(QCoreApplication::translate("RenderingWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Show the transfer function designer window if not visible yet.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        actionExportScreenshot->setText(QCoreApplication::translate("RenderingWindow", "Export Screenshot", nullptr));
#if QT_CONFIG(shortcut)
        actionExportScreenshot->setShortcut(QCoreApplication::translate("RenderingWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSaveViewer->setText(QCoreApplication::translate("RenderingWindow", "Save Observer", nullptr));
        actionOpenViewer->setText(QCoreApplication::translate("RenderingWindow", "Load Observer", nullptr));
        actionDisplayInfo->setText(QCoreApplication::translate("RenderingWindow", "Display About", nullptr));
#if QT_CONFIG(shortcut)
        actionDisplayInfo->setShortcut(QCoreApplication::translate("RenderingWindow", "F8", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBoxControl->setTitle(QCoreApplication::translate("RenderingWindow", "Control panel", nullptr));
#if QT_CONFIG(tooltip)
        tbRefresh->setToolTip(QCoreApplication::translate("RenderingWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Refresh.</span></p><p>Shortcut: <span style=\" font-style:italic;\">F5</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbRefresh->setText(QCoreApplication::translate("RenderingWindow", "Refresh", nullptr));
#if QT_CONFIG(shortcut)
        tbRefresh->setShortcut(QCoreApplication::translate("RenderingWindow", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBoxRotation->setTitle(QCoreApplication::translate("RenderingWindow", "Rotation", nullptr));
        lblZ->setText(QCoreApplication::translate("RenderingWindow", "Z", nullptr));
#if QT_CONFIG(tooltip)
        tbYRight->setToolTip(QCoreApplication::translate("RenderingWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Rotate right (Y Axis).</span></p><p>Shortcut: <span style=\" font-style:italic;\">Right </span>(navigation key)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbYRight->setText(QCoreApplication::translate("RenderingWindow", "Y Rotate Right", nullptr));
#if QT_CONFIG(tooltip)
        tbZLeft->setToolTip(QCoreApplication::translate("RenderingWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Rotate left (Z axis).</span></p><p>Shortcut: <span style=\" font-style:italic;\">Page Down</span> (navigation key)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbZLeft->setText(QCoreApplication::translate("RenderingWindow", "Z Rotate Left", nullptr));
#if QT_CONFIG(tooltip)
        tbXRight->setToolTip(QCoreApplication::translate("RenderingWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Rotate right (X Axis).</span></p><p>Shortcut: <span style=\" font-style:italic;\">Up (navigation key)</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbXRight->setText(QCoreApplication::translate("RenderingWindow", "X Rotate Right", nullptr));
#if QT_CONFIG(tooltip)
        tbXLeft->setToolTip(QCoreApplication::translate("RenderingWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Rotate left (X Axis).</span></p><p>Shortcut: <span style=\" font-style:italic;\">Down </span>(navigation key)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbXLeft->setText(QCoreApplication::translate("RenderingWindow", "X Rotate Left", nullptr));
        lblY->setText(QCoreApplication::translate("RenderingWindow", "Y", nullptr));
        lblX->setText(QCoreApplication::translate("RenderingWindow", "X", nullptr));
#if QT_CONFIG(tooltip)
        tbYLeft->setToolTip(QCoreApplication::translate("RenderingWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Rotate left (Y Axis).</span></p><p>Shortcut: <span style=\" font-style:italic;\">Left </span>(navigation key)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbYLeft->setText(QCoreApplication::translate("RenderingWindow", "Y Rotate Left", nullptr));
#if QT_CONFIG(tooltip)
        tbZRight->setToolTip(QCoreApplication::translate("RenderingWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Rotate right (Z axis).</span></p><p>Shortcut: <span style=\" font-style:italic;\">Page Up</span> (navigation key)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbZRight->setText(QCoreApplication::translate("RenderingWindow", "Z Rotate Right", nullptr));
        groupBoxZoom->setTitle(QCoreApplication::translate("RenderingWindow", "Zoom", nullptr));
#if QT_CONFIG(tooltip)
        tbZoomIn->setToolTip(QCoreApplication::translate("RenderingWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Zoom in.</span></p><p>Shortcut: <span style=\" font-style:italic;\">Ctrl </span>+ <span style=\" font-style:italic;\">+</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbZoomIn->setText(QCoreApplication::translate("RenderingWindow", "Zoom in", nullptr));
#if QT_CONFIG(tooltip)
        tbZoomOut->setToolTip(QCoreApplication::translate("RenderingWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Zoom out.</span></p><p>Shortcut: <span style=\" font-style:italic;\">Ctrl </span>+<span style=\" font-style:italic;\"> -</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbZoomOut->setText(QCoreApplication::translate("RenderingWindow", "Zoom out", nullptr));
#if QT_CONFIG(tooltip)
        tbRestore->setToolTip(QCoreApplication::translate("RenderingWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Restore viewer position.</span></p><p>Shortcut: <span style=\" font-style:italic;\">F10</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbRestore->setText(QCoreApplication::translate("RenderingWindow", "Reset", nullptr));
#if QT_CONFIG(shortcut)
        tbRestore->setShortcut(QCoreApplication::translate("RenderingWindow", "F10", nullptr));
#endif // QT_CONFIG(shortcut)
        cbHighQuality->setText(QCoreApplication::translate("RenderingWindow", "High quality", nullptr));
        menuFile->setTitle(QCoreApplication::translate("RenderingWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("RenderingWindow", "Tools", nullptr));
        menuView->setTitle(QCoreApplication::translate("RenderingWindow", "View", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RenderingWindow: public Ui_RenderingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDERINGWINDOW_H
