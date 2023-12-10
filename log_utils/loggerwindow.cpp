#include "loggerwindow.h"
#include "ui_loggerwindow.h"



LoggerWindow::LoggerWindow(QWidget *parent) : QMainWindow(parent), m_ui(new Ui::LoggerWindow) {
    m_ui->setupUi(this);
}



LoggerWindow::~LoggerWindow() {
    delete m_ui;
}




QTextEdit* LoggerWindow::textEdit() const {
    return m_ui->textEdit;
}
