#include "renderingwindow.h"
#include "ui_renderingwindow.h"


#include "renderinguicontroller.h"



using namespace std;
using namespace graphics_utils;




RenderingWindow::RenderingWindow(QWidget *parent) : QMainWindow(parent), m_ui(new Ui::RenderingWindow) {
    m_ui->setupUi(this);
    initComponents();
}







RenderingWindow::~RenderingWindow() {
    delete m_ui;
    m_ui = nullptr;
}





QLabel* RenderingWindow::labelInfo() const {
    return m_labelInfo;
}




RenderingWidget* RenderingWindow::renderingWidget() const {
    return m_ui->volumeWidget;
}






void RenderingWindow::initComponents() {
    m_labelInfo = new QLabel(this);

    m_ui->statusBar->addWidget(m_labelInfo);
    m_ui->statusBar->setVisible(m_ui->actionDisplayInfo->isChecked());

    connect(m_ui->tbXLeft, SIGNAL(clicked()), this, SLOT(slotRotateXCounterclockwise()));
    connect(m_ui->tbXRight, SIGNAL(clicked()), this, SLOT(slotRotateXClockwise()));
    connect(m_ui->tbYLeft, SIGNAL(clicked()), this, SLOT(slotRotateYCounterclockwise()));
    connect(m_ui->tbYRight, SIGNAL(clicked()), this, SLOT(slotRotateYClockwise()));
    connect(m_ui->tbZLeft, SIGNAL(clicked()), this, SLOT(slotRotateZCounterclockwise()));
    connect(m_ui->tbZRight, SIGNAL(clicked()), this, SLOT(slotRotateZClockwise()));
    connect(m_ui->tbZoomIn, SIGNAL(clicked()), this, SLOT(slotZoomIn()));
    connect(m_ui->tbZoomOut, SIGNAL(clicked()), this, SLOT(slotZoomOut()));

    connect(m_ui->tbXLeft, SIGNAL(released()), this, SLOT(slotEmitSignalUpdate()));
    connect(m_ui->tbXRight, SIGNAL(released()), this, SLOT(slotEmitSignalUpdate()));
    connect(m_ui->tbYLeft, SIGNAL(released()), this, SLOT(slotEmitSignalUpdate()));
    connect(m_ui->tbYRight, SIGNAL(released()), this, SLOT(slotEmitSignalUpdate()));
    connect(m_ui->tbZLeft, SIGNAL(released()), this, SLOT(slotEmitSignalUpdate()));
    connect(m_ui->tbZRight, SIGNAL(released()), this, SLOT(slotEmitSignalUpdate()));
    connect(m_ui->tbZoomIn, SIGNAL(released()), this, SLOT(slotEmitSignalUpdate()));
    connect(m_ui->tbZoomOut, SIGNAL(released()), this, SLOT(slotEmitSignalUpdate()));

    connect(m_ui->tbRestore, SIGNAL(clicked()), this, SLOT(slotEmitSignalReset()));
    connect(m_ui->tbRefresh, SIGNAL(clicked()), this, SLOT(slotEmitSignalUpdate()));
    connect(m_ui->cbHighQuality, SIGNAL(stateChanged(int)), this, SLOT(slotEmitSignalHighQuality(int)));
    connect(m_ui->actionOpenDataset, SIGNAL(triggered()), this, SLOT(slotEmitSignalOpenDataset()));
    connect(m_ui->actionSettings, SIGNAL(triggered()), this, SLOT(slotEmitSignalSettings()));
    connect(m_ui->actionTFDesigner, SIGNAL(triggered()), this, SLOT(slotEmitSignalTFDesigner()));
    connect(m_ui->actionExportScreenshot, SIGNAL(triggered()), this, SLOT(slotEmitSignalScreenshot()));
    connect(m_ui->actionDisplayInfo, SIGNAL(triggered()), this, SLOT(slotDisplayAbout()));
}






void RenderingWindow::slotEmitSignalReset() {
    emit signalReset();
}






void RenderingWindow::slotEmitSignalUpdate() {
    emit signalUpdate();
}






void RenderingWindow::slotZoomIn() {
    RenderingUIController::instance().slotZoom(Zoom::IN);
}






void RenderingWindow::slotZoomOut() {
    RenderingUIController::instance().slotZoom(Zoom::OUT);
}




void RenderingWindow::slotRotateXCounterclockwise() {
    RenderingUIController::instance().slotRotate(RotationAxis::X, RotationSense::COUNTERCLOCKWISE);
}




void RenderingWindow::slotRotateXClockwise() {
    RenderingUIController::instance().slotRotate(RotationAxis::X, RotationSense::CLOCKWISE);
}






void RenderingWindow::slotRotateYCounterclockwise() {
    RenderingUIController::instance().slotRotate(RotationAxis::Y, RotationSense::COUNTERCLOCKWISE);
}






void RenderingWindow::slotRotateYClockwise() {
    RenderingUIController::instance().slotRotate(RotationAxis::Y, RotationSense::CLOCKWISE);
}






void RenderingWindow::slotRotateZCounterclockwise() {
    RenderingUIController::instance().slotRotate(RotationAxis::Z, RotationSense::COUNTERCLOCKWISE);
}






void RenderingWindow::slotRotateZClockwise() {
    RenderingUIController::instance().slotRotate(RotationAxis::Z, RotationSense::CLOCKWISE);
}






void RenderingWindow::slotEmitSignalOpenDataset() {
    emit signalOpenDataset();
}






void RenderingWindow::slotEmitSignalSettings() {
    emit signalSettings();
}





void RenderingWindow::slotEmitSignalTFDesigner() {
    emit signalTFDesigner(true);
}




void RenderingWindow::slotEmitSignalScreenshot() {
    emit signalScreenshot();
}



void RenderingWindow::slotEmitSignalHighQuality(int stateChanged){
    emit signalHighQuality(stateChanged);
}




void RenderingWindow::slotDisplayAbout() {
    m_ui->statusBar->setVisible(m_ui->actionDisplayInfo->isChecked());
}



void RenderingWindow::wheelEvent(QWheelEvent* event) {
    if(event->angleDelta().y() > 0) {
        slotZoomIn();
    }
    else if (event->angleDelta().y() < 0){
        slotZoomOut();
    }
}




// void RenderingWindow::keyReleaseEvent(QKeyEvent *event){
//     if(!event->isAutoRepeat()){
//         bool validKey = false;
//         if (event->key() == Qt::Key_A) {
//             validKey = true;
//         }
//         else if (event->key() == Qt::Key_D) {
//             validKey = true;
//         }
//         else if (event->key() == Qt::Key_W) {
//             validKey = true;
//         }
//         else if (event->key() == Qt::Key_S) {
//             validKey = true;
//         }
//         else if (event->key() == Qt::Key_Q) {
//             validKey = true;
//         }
//         else if (event->key() == Qt::Key_E) {
//             validKey = true;
//         }
//         else if (event->modifiers() & Qt::ControlModifier) {
//             if (event->key() == Qt::Key_Plus || event->key() == Qt::Key_Minus) {
//                 validKey = true;
//             }
//         }
//         if(validKey){
//             RenderingUIController::instance().slotUpdate();
//         }
//     }
// }









void RenderingWindow::keyPressEvent(QKeyEvent *event) {
    bool validKey = false;

    if (event->key() == Qt::Key_A) {
        slotRotateYCounterclockwise();
        validKey = true;
    }
    else if (event->key() == Qt::Key_D) {
        slotRotateYClockwise();
        validKey = true;
    }
    else if (event->key() == Qt::Key_W) {
        slotRotateXClockwise();
        validKey = true;

    }
    else if (event->key() == Qt::Key_S) {
        slotRotateXCounterclockwise();
        validKey = true;
    }
    else if (event->key() == Qt::Key_Q) {
        slotRotateZClockwise();
        validKey = true;
    }
    else if (event->key() == Qt::Key_E) {
        slotRotateZCounterclockwise();
        validKey = true;
    }
    else if (event->modifiers() & Qt::ControlModifier) {
        if (event->key() == Qt::Key_Plus) {
            slotZoomIn();
            validKey = true;
        }
        else if (event->key() == Qt::Key_Minus) {
            slotZoomOut();
            validKey = true;
        }
    }
    else if (event->key() == Qt::Key_H) {
        if(m_ui->cbHighQuality->checkState() == Qt::CheckState::Checked){
            m_ui->cbHighQuality->setCheckState(Qt::CheckState::Unchecked);
        }
        else{
            m_ui->cbHighQuality->setCheckState(Qt::CheckState::Checked);
        }
        slotEmitSignalHighQuality(m_ui->cbHighQuality->checkState());
    }

    if(validKey){
        RenderingUIController::instance().slotUpdate();
    }
}
