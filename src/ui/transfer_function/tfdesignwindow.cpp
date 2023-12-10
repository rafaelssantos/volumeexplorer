#include "tfdesignwindow.h"
#include "ui_tfdesignwindow.h"



using namespace transfer_function;
using namespace graphics_utils;






TFDesignWindow::TFDesignWindow(QWidget *parent) : QMainWindow(parent), m_ui(new Ui::TFDesignWindow){
    m_ui->setupUi(this);

    initComponents();
}






TFDesignWindow::~TFDesignWindow(){
    delete m_ui;
}





TFDesignSpace *TFDesignWindow::view() const{
    return m_ui->view;
}





QLabel *TFDesignWindow::labelClusterCount() const{
    return m_lblClusterCount;
}




QProgressBar* TFDesignWindow::progressBar() const {
    return m_ui->progressBar;
}





void TFDesignWindow::initComponents(){
    m_lblClusterCount = new QLabel(this);
    m_ui->statusbar->addWidget(m_lblClusterCount);
    m_ui->progressBar->setVisible(false);

    connect(m_ui->actionCluster, SIGNAL(triggered()), this, SLOT(slotEmitSignalClustering()));
    connect(m_ui->actionExtractAttribute, SIGNAL(triggered()), this, SLOT(slotEmitSignalAttributeExtraction()));

    connect(m_ui->actionSettingsDialog, SIGNAL(triggered()), this, SLOT(slotEmitSignalSettingsDialog()));
    connect(m_ui->actionRenderingWindow, SIGNAL(triggered()), this,  SLOT(slotEmitSignalShowRenderingWindow()));
    connect(m_ui->actionBenchmarkActivated, SIGNAL(triggered()), this, SLOT(slotEmitBenchmarkEnabled()));
    connect(m_ui->actionExportScreenshot, SIGNAL(triggered()), this, SLOT(slotEmitSignalScreenshot()));
    connect(m_ui->actionExportScreenshotForGroup, SIGNAL(triggered()), this, SLOT(slotEmitSignalScreenshotForGroup()));
    connect(m_ui->actionExportScreenshotForCluster, SIGNAL(triggered()), this, SLOT(slotEmitSignalScreenshotForCluster()));
    connect(m_ui->actionShowLogWindow, SIGNAL(triggered()), this, SLOT(slotEmitSignalShowLogWindow()));

    connect(m_ui->actionLoadViewerPos, SIGNAL(triggered()), this, SLOT(slotEmitSignalLoadViewerPos()));
    connect(m_ui->actionSaveViewerPos, SIGNAL(triggered()), this, SLOT(slotEmitSignalSaveViewerPos()));

    connect(m_ui->actionLoadTFDesign, SIGNAL(triggered()), this, SLOT(slotEmitSignalLoadTFDesign()));
    connect(m_ui->actionSaveTFDesign, SIGNAL(triggered()), this, SLOT(slotEmitSignalSaveTFDesign()));

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



void TFDesignWindow::slotEmitSignalRight() {
    emit signalRight();
}




void TFDesignWindow::slotEmitSignalLeft() {
    emit signalLeft();
}








void TFDesignWindow::slotEmitSignalAttributeExtraction(){
    emit signalAttributeExtraction();
}




void TFDesignWindow::slotEmitSignalClustering(){
    emit signalClustering();
}






void TFDesignWindow::slotEmitSignalSettingsDialog(){
    emit signalSettingsDialog();
}





void TFDesignWindow::slotEmitSignalUnselectAll(){
    emit signalUnselectAll();
}





void TFDesignWindow::slotEmitSignalResetObserver(){
    emit signalRestorePos();
}






void TFDesignWindow::slotEmitSignalResetColor(){
    emit signalRestoreColor();
}





void TFDesignWindow::slotEmitSignalUpdate(){
    emit signalUpdate();
}




void TFDesignWindow::slotEmitSignalZoomIn(){
    emit signalZoom(Zoom::IN);
}





void TFDesignWindow::slotEmitSignalZoomOut(){
    emit signalZoom(Zoom::OUT);
}






void TFDesignWindow::slotEmitSignalShowRenderingWindow(){
    emit signalShowRenderingWindow();
}






void TFDesignWindow::slotEmitSignalColorChoose(){
    emit signalColorChoose();
}



void TFDesignWindow::slotEmitBenchmarkEnabled(){
    emit signalBenchmarkEnabled(m_ui->actionBenchmarkActivated->isChecked());
}






void TFDesignWindow::slotEmitSignalPointSelection(){
    emit signalSelectionModeChanged(SelectionMode::PIVOT);
}






void TFDesignWindow::slotEmitSignalClusterSelection(){
    emit signalSelectionModeChanged(SelectionMode::CLUSTER);
}






void TFDesignWindow::slotEmitSignalGroupSelection(){
    emit signalSelectionModeChanged(SelectionMode::GROUP);
}






void TFDesignWindow::slotEmitSignalGroup(){
    emit signalGroup();
}






void TFDesignWindow::slotEmitSignalUngroup(){
    emit signalUngroup();
}




void TFDesignWindow::slotEmitSignalScreenshot(){
    emit signalScreenshot();
}




void TFDesignWindow::slotEmitSignalScreenshotForCluster(){
    emit signalScreenshotForCluster();
}





void TFDesignWindow::slotEmitSignalScreenshotForGroup() {
    emit signalScreenshotForGroup();
}




void TFDesignWindow::slotEmitSignalSaveViewerPos(){
    emit signalSaveViewerPos();
}



void TFDesignWindow::slotEmitSignalLoadViewerPos(){
    emit signalLoadViewerPos();
}




void TFDesignWindow::slotEmitSignalSaveTFDesign() {
    emit signalSaveTFDesign();
}



void TFDesignWindow::slotEmitSignalLoadTFDesign() {
    emit signalLoadTFDesign();
}




void TFDesignWindow::slotEmitSignalShowLogWindow() {
    emit signalShowLogWindow();
}




void TFDesignWindow::wheelEvent(QWheelEvent* event) {
    if(event->modifiers() & Qt::ControlModifier){
        if(event->angleDelta().y() > 0){
            slotEmitSignalZoomIn();
        }
        else {
            slotEmitSignalZoomOut();
        }
    }
}






void TFDesignWindow::keyPressEvent(QKeyEvent *event){
    if(event->modifiers() & Qt::ControlModifier){
        if(event->key() == Qt::Key_Plus){
            slotEmitSignalZoomIn();
        }
        else if(event->key() == Qt::Key_Minus){
            slotEmitSignalZoomOut();
        }
    }
}
