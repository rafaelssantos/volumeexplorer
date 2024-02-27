#include "tfdesignerwindow.h"
#include "ui_tfdesignerwindow.h"



using namespace transfer_function;
using namespace graphics_utils;






TFDesignerWindow::TFDesignerWindow(QWidget *parent) : QMainWindow(parent), m_ui(new Ui::TFDesignerWindow){
    m_ui->setupUi(this);

    initComponents();
}






TFDesignerWindow::~TFDesignerWindow(){
    delete m_ui;
    m_ui = nullptr;
}





TFDesignerSpace *TFDesignerWindow::view() const{
    return m_ui->view;
}





QLabel *TFDesignerWindow::labelSatus() const{
	return m_lblStatus;
}




QProgressBar* TFDesignerWindow::progressBar() const {
    return m_ui->progressBar;
}





void TFDesignerWindow::initComponents(){
	m_lblStatus = new QLabel(this);
	m_ui->statusbar->addWidget(m_lblStatus);
    m_ui->progressBar->setVisible(false);

    connect(m_ui->actionCluster, SIGNAL(triggered()), this, SLOT(slotEmitSignalClustering()));
	connect(m_ui->actionSelectAttribute, SIGNAL(triggered()), this, SLOT(slotEmitSignalFeaturesExtraction()));

    connect(m_ui->actionSettingsDialog, SIGNAL(triggered()), this, SLOT(slotEmitSignalSettingsDialog()));
    connect(m_ui->actionRenderingWindow, SIGNAL(triggered()), this,  SLOT(slotEmitSignalShowRenderingWindow()));
	connect(m_ui->actionScreenshot, SIGNAL(triggered()), this, SLOT(slotEmitSignalScreenshot()));
	connect(m_ui->actionScreenshotForPivots, SIGNAL(triggered()), this, SLOT(slotEmitSignalScreenshotForPivots()));
	connect(m_ui->actionScreenshotForClusters, SIGNAL(triggered()), this, SLOT(slotEmitSignalScreenshotForClusters()));
	connect(m_ui->actionScreenshotForGroups, SIGNAL(triggered()), this, SLOT(slotEmitSignalScreenshotForGroups()));
	connect(m_ui->actionShowLogWindow, SIGNAL(triggered()), this, SLOT(slotEmitSignalShowLogWindow()));

    connect(m_ui->rbPivot, SIGNAL(clicked()), this, SLOT(slotEmitSignalPointSelection()));
    connect(m_ui->rbCluster, SIGNAL(clicked()), this, SLOT(slotEmitSignalClusterSelection()));
    connect(m_ui->rbGroup, SIGNAL(clicked()), this, SLOT(slotEmitSignalGroupSelection()));

    connect(m_ui->tbGroup, SIGNAL(clicked()), this, SLOT(slotEmitSignalGroup()));
    connect(m_ui->tbUngroup, SIGNAL(clicked()), this, SLOT(slotEmitSignalUngroup()));

    connect(m_ui->tbUnselectAll, SIGNAL(clicked()), this, SLOT(slotEmitSignalUnselectAll()));
    connect(m_ui->tbRefresh, SIGNAL(clicked()), this, SLOT(slotEmitSignalUpdate()));
    connect(m_ui->tbZoomOut, SIGNAL(clicked()), this, SLOT(slotEmitSignalZoomOut()));
    connect(m_ui->tbZoomIn, SIGNAL(clicked()), this, SLOT(slotEmitSignalZoomIn()));
    connect(m_ui->tbReset, SIGNAL(clicked()), this, SLOT(slotEmitSignalResetObserver()));
    connect(m_ui->tbResetColor, SIGNAL(clicked()), this, SLOT(slotEmitSignalResetColor()));
    connect(m_ui->tbSelectColor, SIGNAL(clicked()), this, SLOT(slotEmitSignalColorChoose()));
    connect(m_ui->tbLeft, SIGNAL(clicked()), this, SLOT(slotEmitSignalLeft()));
    connect(m_ui->tbRight, SIGNAL(clicked()), this, SLOT(slotEmitSignalRight()));
}



void TFDesignerWindow::slotEmitSignalRight() {
    emit signalRight();
}




void TFDesignerWindow::slotEmitSignalLeft() {
    emit signalLeft();
}








void TFDesignerWindow::slotEmitSignalFeaturesExtraction(){
    emit signalFeaturesExtraction();
}




void TFDesignerWindow::slotEmitSignalClustering(){
    emit signalClustering();
}






void TFDesignerWindow::slotEmitSignalSettingsDialog(){
    emit signalSettingsDialog();
}





void TFDesignerWindow::slotEmitSignalUnselectAll(){
    emit signalUnselectAll();
}





void TFDesignerWindow::slotEmitSignalResetObserver(){
    emit signalRestorePos();
}






void TFDesignerWindow::slotEmitSignalResetColor(){
    emit signalRestoreColor();
}





void TFDesignerWindow::slotEmitSignalUpdate(){
    emit signalUpdate();
}




void TFDesignerWindow::slotEmitSignalZoomIn(){
    emit signalZoom(Zoom::IN);
}





void TFDesignerWindow::slotEmitSignalZoomOut(){
    emit signalZoom(Zoom::OUT);
}






void TFDesignerWindow::slotEmitSignalShowRenderingWindow(){
    emit signalShowRenderingWindow();
}






void TFDesignerWindow::slotEmitSignalColorChoose(){
    emit signalColorChoose();
}




void TFDesignerWindow::slotEmitSignalPointSelection(){
    emit signalSelectionModeChanged(SelectionMode::PIVOT);
}






void TFDesignerWindow::slotEmitSignalClusterSelection(){
    emit signalSelectionModeChanged(SelectionMode::CLUSTER);
}






void TFDesignerWindow::slotEmitSignalGroupSelection(){
    emit signalSelectionModeChanged(SelectionMode::GROUP);
}






void TFDesignerWindow::slotEmitSignalGroup(){
    emit signalGroup();
}






void TFDesignerWindow::slotEmitSignalUngroup(){
    emit signalUngroup();
}




void TFDesignerWindow::slotEmitSignalScreenshot(){
	emit signalScreenshot();
}




void TFDesignerWindow::slotEmitSignalScreenshotForPivots(){
	emit signalScreenshotForPivots();
}




void TFDesignerWindow::slotEmitSignalScreenshotForClusters(){
    emit signalScreenshotForClusters();
}





void TFDesignerWindow::slotEmitSignalScreenshotForGroups() {
    emit signalScreenshotForGroups();
}




void TFDesignerWindow::slotEmitSignalShowLogWindow() {
    emit signalShowLogWindow();
}




void TFDesignerWindow::wheelEvent(QWheelEvent* event) {
    if(event->modifiers() & Qt::ControlModifier){
        if(event->angleDelta().y() > 0){
            slotEmitSignalZoomIn();
        }
        else {
            slotEmitSignalZoomOut();
        }
    }
}






void TFDesignerWindow::keyPressEvent(QKeyEvent *event){
    if(event->modifiers() & Qt::ControlModifier){
        if(event->key() == Qt::Key_Plus){
            slotEmitSignalZoomIn();
        }
        else if(event->key() == Qt::Key_Minus){
            slotEmitSignalZoomOut();
        }
    }
}
