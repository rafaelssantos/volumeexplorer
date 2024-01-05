/********************************************************************************
** Form generated from reading UI file 'tfdesignerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TFDESIGNERWINDOW_H
#define UI_TFDESIGNERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "ui/transfer_function/tfdesignerspace.h"

QT_BEGIN_NAMESPACE

class Ui_TFDesignerWindow
{
public:
    QAction *actionSelectAttribute;
    QAction *actionCluster;
    QAction *actionSettingsDialog;
    QAction *actionRenderingWindow;
    QAction *actionBenchmarkActivated;
    QAction *actionScreenshot;
    QAction *actionLoadViewerPos;
    QAction *actionSaveViewerPos;
    QAction *actionScreenshotForClusters;
    QAction *actionScreenshotForGroups;
    QAction *actionShowLogWindow;
    QAction *actionLoadTFDesign;
    QAction *actionSaveTFDesign;
    QAction *actionScreenshotForPivots;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QProgressBar *progressBar;
    QSplitter *splitter;
    TFDesignerSpace *view;
    QWidget *controlWidget;
    QGridLayout *gridLayout_2;
    QSpacerItem *topVerticalSpacer;
    QSpacerItem *bottomVerticalSpacer;
    QGroupBox *groupBoxControl;
    QGridLayout *gridLayout_3;
    QToolButton *tbReset;
    QToolButton *tbRefresh;
    QToolButton *tbResetColor;
    QGroupBox *zoomGroupBox;
    QGridLayout *gridLayout_4;
    QToolButton *tbZoomIn;
    QToolButton *tbZoomOut;
    QGroupBox *groupBoxSelection;
    QGridLayout *gridLayout_5;
    QToolButton *tbUnselectAll;
    QRadioButton *rbGroup;
    QGroupBox *groupBoxNavigation;
    QGridLayout *gridLayout_7;
    QToolButton *tbLeft;
    QToolButton *tbRight;
    QToolButton *tbGroup;
    QToolButton *tbUngroup;
    QRadioButton *rbPivot;
    QRadioButton *rbCluster;
    QToolButton *tbSelectColor;
    QMenuBar *menubar;
    QMenu *menuGraph;
    QMenu *menuHelp;
    QMenu *menuView;
    QMenu *menuScreenshot;
    QMenu *menuLog;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TFDesignerWindow)
    {
        if (TFDesignerWindow->objectName().isEmpty())
            TFDesignerWindow->setObjectName("TFDesignerWindow");
        TFDesignerWindow->resize(800, 605);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ui/icons/vex_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        TFDesignerWindow->setWindowIcon(icon);
        actionSelectAttribute = new QAction(TFDesignerWindow);
        actionSelectAttribute->setObjectName("actionSelectAttribute");
        actionSelectAttribute->setCheckable(false);
        actionCluster = new QAction(TFDesignerWindow);
        actionCluster->setObjectName("actionCluster");
        actionSettingsDialog = new QAction(TFDesignerWindow);
        actionSettingsDialog->setObjectName("actionSettingsDialog");
        actionRenderingWindow = new QAction(TFDesignerWindow);
        actionRenderingWindow->setObjectName("actionRenderingWindow");
        actionBenchmarkActivated = new QAction(TFDesignerWindow);
        actionBenchmarkActivated->setObjectName("actionBenchmarkActivated");
        actionBenchmarkActivated->setCheckable(true);
        actionScreenshot = new QAction(TFDesignerWindow);
        actionScreenshot->setObjectName("actionScreenshot");
        actionLoadViewerPos = new QAction(TFDesignerWindow);
        actionLoadViewerPos->setObjectName("actionLoadViewerPos");
        actionSaveViewerPos = new QAction(TFDesignerWindow);
        actionSaveViewerPos->setObjectName("actionSaveViewerPos");
        actionScreenshotForClusters = new QAction(TFDesignerWindow);
        actionScreenshotForClusters->setObjectName("actionScreenshotForClusters");
        actionScreenshotForGroups = new QAction(TFDesignerWindow);
        actionScreenshotForGroups->setObjectName("actionScreenshotForGroups");
        actionShowLogWindow = new QAction(TFDesignerWindow);
        actionShowLogWindow->setObjectName("actionShowLogWindow");
        actionLoadTFDesign = new QAction(TFDesignerWindow);
        actionLoadTFDesign->setObjectName("actionLoadTFDesign");
        actionSaveTFDesign = new QAction(TFDesignerWindow);
        actionSaveTFDesign->setObjectName("actionSaveTFDesign");
        actionScreenshotForPivots = new QAction(TFDesignerWindow);
        actionScreenshotForPivots->setObjectName("actionScreenshotForPivots");
        centralwidget = new QWidget(TFDesignerWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setEnabled(true);
        progressBar->setValue(0);
        progressBar->setTextDirection(QProgressBar::TopToBottom);

        gridLayout->addWidget(progressBar, 2, 0, 1, 1);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        view = new TFDesignerSpace(splitter);
        view->setObjectName("view");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(view->sizePolicy().hasHeightForWidth());
        view->setSizePolicy(sizePolicy);
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        view->setBackgroundBrush(brush);
        splitter->addWidget(view);
        controlWidget = new QWidget(splitter);
        controlWidget->setObjectName("controlWidget");
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(controlWidget->sizePolicy().hasHeightForWidth());
        controlWidget->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(controlWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        topVerticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout_2->addItem(topVerticalSpacer, 0, 0, 1, 1);

        bottomVerticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout_2->addItem(bottomVerticalSpacer, 3, 0, 1, 1);

        groupBoxControl = new QGroupBox(controlWidget);
        groupBoxControl->setObjectName("groupBoxControl");
        sizePolicy1.setHeightForWidth(groupBoxControl->sizePolicy().hasHeightForWidth());
        groupBoxControl->setSizePolicy(sizePolicy1);
        gridLayout_3 = new QGridLayout(groupBoxControl);
        gridLayout_3->setObjectName("gridLayout_3");
        tbReset = new QToolButton(groupBoxControl);
        tbReset->setObjectName("tbReset");
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tbReset->sizePolicy().hasHeightForWidth());
        tbReset->setSizePolicy(sizePolicy2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/reload.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbReset->setIcon(icon1);
        tbReset->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(tbReset, 4, 0, 1, 1);

        tbRefresh = new QToolButton(groupBoxControl);
        tbRefresh->setObjectName("tbRefresh");
        sizePolicy2.setHeightForWidth(tbRefresh->sizePolicy().hasHeightForWidth());
        tbRefresh->setSizePolicy(sizePolicy2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbRefresh->setIcon(icon2);
        tbRefresh->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(tbRefresh, 4, 1, 1, 1);

        tbResetColor = new QToolButton(groupBoxControl);
        tbResetColor->setObjectName("tbResetColor");
        sizePolicy2.setHeightForWidth(tbResetColor->sizePolicy().hasHeightForWidth());
        tbResetColor->setSizePolicy(sizePolicy2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/palette.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbResetColor->setIcon(icon3);
        tbResetColor->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(tbResetColor, 5, 0, 1, 1);

        zoomGroupBox = new QGroupBox(groupBoxControl);
        zoomGroupBox->setObjectName("zoomGroupBox");
        sizePolicy1.setHeightForWidth(zoomGroupBox->sizePolicy().hasHeightForWidth());
        zoomGroupBox->setSizePolicy(sizePolicy1);
        gridLayout_4 = new QGridLayout(zoomGroupBox);
        gridLayout_4->setObjectName("gridLayout_4");
        tbZoomIn = new QToolButton(zoomGroupBox);
        tbZoomIn->setObjectName("tbZoomIn");
        sizePolicy2.setHeightForWidth(tbZoomIn->sizePolicy().hasHeightForWidth());
        tbZoomIn->setSizePolicy(sizePolicy2);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/zoom_out.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbZoomIn->setIcon(icon4);
        tbZoomIn->setIconSize(QSize(32, 32));
        tbZoomIn->setAutoRepeat(true);
        tbZoomIn->setAutoRepeatInterval(50);

        gridLayout_4->addWidget(tbZoomIn, 0, 0, 1, 1);

        tbZoomOut = new QToolButton(zoomGroupBox);
        tbZoomOut->setObjectName("tbZoomOut");
        sizePolicy2.setHeightForWidth(tbZoomOut->sizePolicy().hasHeightForWidth());
        tbZoomOut->setSizePolicy(sizePolicy2);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/zoom_in.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbZoomOut->setIcon(icon5);
        tbZoomOut->setIconSize(QSize(32, 32));
        tbZoomOut->setAutoRepeat(true);
        tbZoomOut->setAutoRepeatInterval(50);

        gridLayout_4->addWidget(tbZoomOut, 0, 1, 1, 1);


        gridLayout_3->addWidget(zoomGroupBox, 0, 0, 1, 2);

        groupBoxSelection = new QGroupBox(groupBoxControl);
        groupBoxSelection->setObjectName("groupBoxSelection");
        sizePolicy1.setHeightForWidth(groupBoxSelection->sizePolicy().hasHeightForWidth());
        groupBoxSelection->setSizePolicy(sizePolicy1);
        gridLayout_5 = new QGridLayout(groupBoxSelection);
        gridLayout_5->setObjectName("gridLayout_5");
        tbUnselectAll = new QToolButton(groupBoxSelection);
        tbUnselectAll->setObjectName("tbUnselectAll");
        sizePolicy2.setHeightForWidth(tbUnselectAll->sizePolicy().hasHeightForWidth());
        tbUnselectAll->setSizePolicy(sizePolicy2);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/unselect_all.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbUnselectAll->setIcon(icon6);
        tbUnselectAll->setIconSize(QSize(32, 32));

        gridLayout_5->addWidget(tbUnselectAll, 0, 1, 3, 1);

        rbGroup = new QRadioButton(groupBoxSelection);
        rbGroup->setObjectName("rbGroup");

        gridLayout_5->addWidget(rbGroup, 2, 0, 1, 1);

        groupBoxNavigation = new QGroupBox(groupBoxSelection);
        groupBoxNavigation->setObjectName("groupBoxNavigation");
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBoxNavigation->sizePolicy().hasHeightForWidth());
        groupBoxNavigation->setSizePolicy(sizePolicy3);
        gridLayout_7 = new QGridLayout(groupBoxNavigation);
        gridLayout_7->setObjectName("gridLayout_7");
        tbLeft = new QToolButton(groupBoxNavigation);
        tbLeft->setObjectName("tbLeft");
        sizePolicy2.setHeightForWidth(tbLeft->sizePolicy().hasHeightForWidth());
        tbLeft->setSizePolicy(sizePolicy2);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbLeft->setIcon(icon7);
        tbLeft->setIconSize(QSize(32, 32));
        tbLeft->setAutoRaise(false);
        tbLeft->setArrowType(Qt::NoArrow);

        gridLayout_7->addWidget(tbLeft, 1, 1, 1, 1);

        tbRight = new QToolButton(groupBoxNavigation);
        tbRight->setObjectName("tbRight");
        sizePolicy2.setHeightForWidth(tbRight->sizePolicy().hasHeightForWidth());
        tbRight->setSizePolicy(sizePolicy2);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/img/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbRight->setIcon(icon8);
        tbRight->setIconSize(QSize(32, 32));

        gridLayout_7->addWidget(tbRight, 1, 2, 1, 1);

        tbGroup = new QToolButton(groupBoxNavigation);
        tbGroup->setObjectName("tbGroup");
        sizePolicy2.setHeightForWidth(tbGroup->sizePolicy().hasHeightForWidth());
        tbGroup->setSizePolicy(sizePolicy2);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/img/group.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbGroup->setIcon(icon9);
        tbGroup->setIconSize(QSize(32, 32));

        gridLayout_7->addWidget(tbGroup, 0, 1, 1, 1);

        tbUngroup = new QToolButton(groupBoxNavigation);
        tbUngroup->setObjectName("tbUngroup");
        sizePolicy2.setHeightForWidth(tbUngroup->sizePolicy().hasHeightForWidth());
        tbUngroup->setSizePolicy(sizePolicy2);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/img/ungroup.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbUngroup->setIcon(icon10);
        tbUngroup->setIconSize(QSize(32, 32));

        gridLayout_7->addWidget(tbUngroup, 0, 2, 1, 1);


        gridLayout_5->addWidget(groupBoxNavigation, 3, 0, 1, 2);

        rbPivot = new QRadioButton(groupBoxSelection);
        rbPivot->setObjectName("rbPivot");
        rbPivot->setChecked(false);

        gridLayout_5->addWidget(rbPivot, 0, 0, 1, 1);

        rbCluster = new QRadioButton(groupBoxSelection);
        rbCluster->setObjectName("rbCluster");
        rbCluster->setChecked(true);

        gridLayout_5->addWidget(rbCluster, 1, 0, 1, 1);


        gridLayout_3->addWidget(groupBoxSelection, 1, 0, 1, 2);

        tbSelectColor = new QToolButton(groupBoxControl);
        tbSelectColor->setObjectName("tbSelectColor");
        sizePolicy2.setHeightForWidth(tbSelectColor->sizePolicy().hasHeightForWidth());
        tbSelectColor->setSizePolicy(sizePolicy2);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/img/fill.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbSelectColor->setIcon(icon11);
        tbSelectColor->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(tbSelectColor, 5, 1, 1, 1);


        gridLayout_2->addWidget(groupBoxControl, 2, 0, 1, 1);

        splitter->addWidget(controlWidget);

        gridLayout->addWidget(splitter, 1, 0, 1, 1);

        TFDesignerWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TFDesignerWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuGraph = new QMenu(menubar);
        menuGraph->setObjectName("menuGraph");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        menuView = new QMenu(menubar);
        menuView->setObjectName("menuView");
        menuScreenshot = new QMenu(menuView);
        menuScreenshot->setObjectName("menuScreenshot");
        menuLog = new QMenu(menubar);
        menuLog->setObjectName("menuLog");
        TFDesignerWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TFDesignerWindow);
        statusbar->setObjectName("statusbar");
        TFDesignerWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(view, tbZoomIn);
        QWidget::setTabOrder(tbZoomIn, tbZoomOut);
        QWidget::setTabOrder(tbZoomOut, rbPivot);
        QWidget::setTabOrder(rbPivot, rbCluster);
        QWidget::setTabOrder(rbCluster, rbGroup);
        QWidget::setTabOrder(rbGroup, tbUnselectAll);
        QWidget::setTabOrder(tbUnselectAll, tbGroup);
        QWidget::setTabOrder(tbGroup, tbUngroup);
        QWidget::setTabOrder(tbUngroup, tbLeft);
        QWidget::setTabOrder(tbLeft, tbRight);
        QWidget::setTabOrder(tbRight, tbReset);
        QWidget::setTabOrder(tbReset, tbRefresh);
        QWidget::setTabOrder(tbRefresh, tbResetColor);
        QWidget::setTabOrder(tbResetColor, tbSelectColor);

        menubar->addAction(menuGraph->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuLog->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuGraph->addAction(actionSelectAttribute);
        menuGraph->addAction(actionCluster);
        menuGraph->addSeparator();
        menuHelp->addAction(actionSettingsDialog);
        menuView->addAction(actionRenderingWindow);
        menuView->addSeparator();
        menuView->addSeparator();
        menuView->addAction(menuScreenshot->menuAction());
        menuScreenshot->addAction(actionScreenshot);
        menuScreenshot->addAction(actionScreenshotForPivots);
        menuScreenshot->addAction(actionScreenshotForClusters);
        menuScreenshot->addAction(actionScreenshotForGroups);
        menuLog->addAction(actionShowLogWindow);

        retranslateUi(TFDesignerWindow);

        QMetaObject::connectSlotsByName(TFDesignerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TFDesignerWindow)
    {
        TFDesignerWindow->setWindowTitle(QCoreApplication::translate("TFDesignerWindow", "Transfer Function Designer - Volume Explorer (VEx)", nullptr));
        actionSelectAttribute->setText(QCoreApplication::translate("TFDesignerWindow", "Attribute Extraction", nullptr));
#if QT_CONFIG(tooltip)
        actionSelectAttribute->setToolTip(QCoreApplication::translate("TFDesignerWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Extract features and execute FastMap.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSelectAttribute->setShortcut(QCoreApplication::translate("TFDesignerWindow", "Ctrl+Shift+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCluster->setText(QCoreApplication::translate("TFDesignerWindow", "Clustering and Pivot Selection", nullptr));
#if QT_CONFIG(tooltip)
        actionCluster->setToolTip(QCoreApplication::translate("TFDesignerWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Execute GridDBSCAN and Sparse Spatial Selection.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionCluster->setShortcut(QCoreApplication::translate("TFDesignerWindow", "Ctrl+Shift+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSettingsDialog->setText(QCoreApplication::translate("TFDesignerWindow", "Settings", nullptr));
#if QT_CONFIG(shortcut)
        actionSettingsDialog->setShortcut(QCoreApplication::translate("TFDesignerWindow", "F12", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRenderingWindow->setText(QCoreApplication::translate("TFDesignerWindow", "Show Rendering Window", nullptr));
#if QT_CONFIG(tooltip)
        actionRenderingWindow->setToolTip(QCoreApplication::translate("TFDesignerWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Show the rendering window if not visible yet.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        actionBenchmarkActivated->setText(QCoreApplication::translate("TFDesignerWindow", "Activated", nullptr));
        actionScreenshot->setText(QCoreApplication::translate("TFDesignerWindow", "Current View", nullptr));
        actionLoadViewerPos->setText(QCoreApplication::translate("TFDesignerWindow", "Load Observer", nullptr));
        actionSaveViewerPos->setText(QCoreApplication::translate("TFDesignerWindow", "Save Observer", nullptr));
        actionScreenshotForClusters->setText(QCoreApplication::translate("TFDesignerWindow", "for Clusters", nullptr));
#if QT_CONFIG(shortcut)
        actionScreenshotForClusters->setShortcut(QCoreApplication::translate("TFDesignerWindow", "Ctrl+2", nullptr));
#endif // QT_CONFIG(shortcut)
        actionScreenshotForGroups->setText(QCoreApplication::translate("TFDesignerWindow", "for Groups", nullptr));
#if QT_CONFIG(shortcut)
        actionScreenshotForGroups->setShortcut(QCoreApplication::translate("TFDesignerWindow", "Ctrl+3", nullptr));
#endif // QT_CONFIG(shortcut)
        actionShowLogWindow->setText(QCoreApplication::translate("TFDesignerWindow", "Show Log Window", nullptr));
        actionLoadTFDesign->setText(QCoreApplication::translate("TFDesignerWindow", "Open Transfer Function Design", nullptr));
#if QT_CONFIG(shortcut)
        actionLoadTFDesign->setShortcut(QCoreApplication::translate("TFDesignerWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSaveTFDesign->setText(QCoreApplication::translate("TFDesignerWindow", "Save Transfer Function Design", nullptr));
#if QT_CONFIG(shortcut)
        actionSaveTFDesign->setShortcut(QCoreApplication::translate("TFDesignerWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionScreenshotForPivots->setText(QCoreApplication::translate("TFDesignerWindow", "for Pivots", nullptr));
#if QT_CONFIG(shortcut)
        actionScreenshotForPivots->setShortcut(QCoreApplication::translate("TFDesignerWindow", "Ctrl+1", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBoxControl->setTitle(QCoreApplication::translate("TFDesignerWindow", "Control panel", nullptr));
#if QT_CONFIG(tooltip)
        tbReset->setToolTip(QCoreApplication::translate("TFDesignerWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Restore viwer position.</span></p><p>Shortcut: <span style=\" font-style:italic;\">F10</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbReset->setText(QCoreApplication::translate("TFDesignerWindow", "Reset", nullptr));
#if QT_CONFIG(shortcut)
        tbReset->setShortcut(QCoreApplication::translate("TFDesignerWindow", "F10", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        tbRefresh->setToolTip(QCoreApplication::translate("TFDesignerWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Refresh.</span></p><p>Shortcut: <span style=\" font-style:italic;\">F5</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbRefresh->setText(QCoreApplication::translate("TFDesignerWindow", "Refresh", nullptr));
#if QT_CONFIG(shortcut)
        tbRefresh->setShortcut(QCoreApplication::translate("TFDesignerWindow", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        tbResetColor->setToolTip(QCoreApplication::translate("TFDesignerWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Restore color.</span></p><p>Shortcut: <span style=\" font-style:italic;\">F6</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbResetColor->setText(QCoreApplication::translate("TFDesignerWindow", "Reset colors", nullptr));
#if QT_CONFIG(shortcut)
        tbResetColor->setShortcut(QCoreApplication::translate("TFDesignerWindow", "F8", nullptr));
#endif // QT_CONFIG(shortcut)
        zoomGroupBox->setTitle(QCoreApplication::translate("TFDesignerWindow", "Zoom", nullptr));
#if QT_CONFIG(tooltip)
        tbZoomIn->setToolTip(QCoreApplication::translate("TFDesignerWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Zoom out.</span></p><p>Shortcut: <span style=\" font-style:italic;\">Ctrl </span>+<span style=\" font-style:italic;\"> -</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbZoomIn->setText(QCoreApplication::translate("TFDesignerWindow", "Zoom out", nullptr));
#if QT_CONFIG(tooltip)
        tbZoomOut->setToolTip(QCoreApplication::translate("TFDesignerWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Zoom in.</span></p><p>Shortcut: <span style=\" font-style:italic;\">Ctrl </span>+ <span style=\" font-style:italic;\">+</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbZoomOut->setText(QCoreApplication::translate("TFDesignerWindow", "Zoom in", nullptr));
        groupBoxSelection->setTitle(QCoreApplication::translate("TFDesignerWindow", "Selection Mode", nullptr));
#if QT_CONFIG(tooltip)
        tbUnselectAll->setToolTip(QCoreApplication::translate("TFDesignerWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Unselect all.</span></p><p>Shortcut: <span style=\" font-style:italic;\">Esc</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbUnselectAll->setText(QCoreApplication::translate("TFDesignerWindow", "Unselect all", nullptr));
#if QT_CONFIG(shortcut)
        tbUnselectAll->setShortcut(QCoreApplication::translate("TFDesignerWindow", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        rbGroup->setToolTip(QCoreApplication::translate("TFDesignerWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Select points of a group. </span></p><p>Shortcut: <span style=\" font-style:italic;\">3</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        rbGroup->setText(QCoreApplication::translate("TFDesignerWindow", "Group", nullptr));
#if QT_CONFIG(shortcut)
        rbGroup->setShortcut(QCoreApplication::translate("TFDesignerWindow", "3", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBoxNavigation->setTitle(QCoreApplication::translate("TFDesignerWindow", "Navigation", nullptr));
        tbLeft->setText(QCoreApplication::translate("TFDesignerWindow", "Left", nullptr));
#if QT_CONFIG(shortcut)
        tbLeft->setShortcut(QCoreApplication::translate("TFDesignerWindow", "Left", nullptr));
#endif // QT_CONFIG(shortcut)
        tbRight->setText(QCoreApplication::translate("TFDesignerWindow", "Right", nullptr));
#if QT_CONFIG(shortcut)
        tbRight->setShortcut(QCoreApplication::translate("TFDesignerWindow", "Right", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        tbGroup->setToolTip(QCoreApplication::translate("TFDesignerWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Group selected points.</span></p><p>Shortcut: <span style=\" font-style:italic;\">CTrl </span>+ <span style=\" font-style:italic;\">G</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbGroup->setText(QCoreApplication::translate("TFDesignerWindow", "Group", nullptr));
#if QT_CONFIG(shortcut)
        tbGroup->setShortcut(QCoreApplication::translate("TFDesignerWindow", "Ctrl+G", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        tbUngroup->setToolTip(QCoreApplication::translate("TFDesignerWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Ungroup selected points.</span></p><p>Shortcut: <span style=\" font-style:italic;\">CTrl </span>+ <span style=\" font-style:italic;\">U</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbUngroup->setText(QCoreApplication::translate("TFDesignerWindow", "Ungroup", nullptr));
#if QT_CONFIG(shortcut)
        tbUngroup->setShortcut(QCoreApplication::translate("TFDesignerWindow", "Ctrl+U", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        rbPivot->setToolTip(QCoreApplication::translate("TFDesignerWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Select a single point. </span></p><p><span style=\" font-weight:600;\">Each point is a representative.</span></p><p>Shortcut: <span style=\" font-style:italic;\">1</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        rbPivot->setText(QCoreApplication::translate("TFDesignerWindow", "Pivot", nullptr));
#if QT_CONFIG(shortcut)
        rbPivot->setShortcut(QCoreApplication::translate("TFDesignerWindow", "1", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        rbCluster->setToolTip(QCoreApplication::translate("TFDesignerWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Select points of a cluster.</span></p><p>Shortcut: <span style=\" font-style:italic;\">2</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        rbCluster->setText(QCoreApplication::translate("TFDesignerWindow", "Cluster", nullptr));
#if QT_CONFIG(shortcut)
        rbCluster->setShortcut(QCoreApplication::translate("TFDesignerWindow", "2", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        tbSelectColor->setToolTip(QCoreApplication::translate("TFDesignerWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Color fill.</span></p><p>Shortcut: <span style=\" font-style:italic;\">F2</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbSelectColor->setText(QCoreApplication::translate("TFDesignerWindow", "Fill", nullptr));
#if QT_CONFIG(shortcut)
        tbSelectColor->setShortcut(QCoreApplication::translate("TFDesignerWindow", "F2", nullptr));
#endif // QT_CONFIG(shortcut)
        menuGraph->setTitle(QCoreApplication::translate("TFDesignerWindow", "Classification", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("TFDesignerWindow", "Tools", nullptr));
        menuView->setTitle(QCoreApplication::translate("TFDesignerWindow", "View", nullptr));
        menuScreenshot->setTitle(QCoreApplication::translate("TFDesignerWindow", "Export Screenshot(s)", nullptr));
        menuLog->setTitle(QCoreApplication::translate("TFDesignerWindow", "Log", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TFDesignerWindow: public Ui_TFDesignerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TFDESIGNERWINDOW_H
