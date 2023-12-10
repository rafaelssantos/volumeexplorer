#ifndef LOGGERWINDOW_H
#define LOGGERWINDOW_H

#include <QMainWindow>
#include <QTextEdit>

namespace Ui {
class LoggerWindow;
}

class LoggerWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit LoggerWindow(QWidget *parent = 0);

    virtual ~LoggerWindow();

    QTextEdit *textEdit() const;

private:
    Ui::LoggerWindow *m_ui;
};

#endif // LOGGERWINDOW_H
