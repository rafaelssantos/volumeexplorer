#include "logger.h"

#include <QFile>
#include <QLocale>


using namespace log_utils;
using namespace std;


Logger& Logger::instance() {
    static Logger instance;

    return instance;
}





void Logger::startTimer(int i) {
	while(i >= static_cast<int>(m_startsTime.size())){
			m_startsTime.emplace_back(chrono::system_clock::now());
	}
	m_startsTime[i] = chrono::system_clock::now();
}



void Logger::appendMessage(string message) {
	m_window.textEdit()->append(QString::fromStdString(message));
}



void Logger::stopTimer(int i, std::string message) {
	auto end = chrono::system_clock::now();
	std::chrono::duration<float> elapsed_seconds = end-m_startsTime[i];

	m_window.textEdit()->append(QString::fromStdString(message + ": " + to_string(elapsed_seconds.count()) + " seconds"));
}




void Logger::setWindowVisible(bool visible) {
    m_window.setVisible(visible);
}



void Logger::saveToFile(QString filePath) {
    QFile fileObject(filePath);


    if(!fileObject.open(QIODevice::WriteOnly))    {
        qDebug() << "Error! could not open file.";
    }

    QTextStream stream(&fileObject);
    stream << m_window.textEdit()->toPlainText();
    fileObject.close();
}



Logger::Logger() {
    m_count = 1;
    m_iter = 0;
}




Logger::~Logger() {

}
