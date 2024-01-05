/********************************************************************************
** Form generated from reading UI file 'loggerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGGERWINDOW_H
#define UI_LOGGERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoggerWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit;
    QMenuBar *menubar;

    void setupUi(QMainWindow *LoggerWindow)
    {
        if (LoggerWindow->objectName().isEmpty())
            LoggerWindow->setObjectName("LoggerWindow");
        LoggerWindow->resize(640, 480);
        centralwidget = new QWidget(LoggerWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setLineWrapMode(QTextEdit::NoWrap);
        textEdit->setReadOnly(true);

        horizontalLayout->addWidget(textEdit);

        LoggerWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoggerWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 640, 21));
        LoggerWindow->setMenuBar(menubar);

        retranslateUi(LoggerWindow);

        QMetaObject::connectSlotsByName(LoggerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoggerWindow)
    {
        LoggerWindow->setWindowTitle(QCoreApplication::translate("LoggerWindow", "Logger Window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoggerWindow: public Ui_LoggerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGGERWINDOW_H
