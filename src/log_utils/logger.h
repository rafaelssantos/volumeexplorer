#ifndef LOGGER_H
#define LOGGER_H


#include <chrono>
#include <string>
#include <vector>
#include "loggerwindow.h"

namespace log_utils {


class Logger {
public:
    static Logger& instance();

	void startTimer(int i);

	void appendMessage(std::string message);

	void stopTimer(int i, std::string message);

    void setWindowVisible(bool visible);



private:
    Logger();

    virtual ~Logger();

    std::vector<std::chrono::system_clock::time_point> m_startsTime;
    LoggerWindow m_window;
    int m_count;
    int m_iter;
    bool m_benchmarkEnabled;
};


}

#endif // LOGGER_H
