#include "Logger.h"

#include <fstream>

namespace Engine {
    Logger::Logger() {
        m_OutputStream.open("engine.log");
        if (!m_OutputStream.is_open()) {
            throw std::runtime_error("Unable to open log file!");
        }
    }

    Logger::~Logger() {
        if (m_OutputStream.is_open()) {
            m_OutputStream.close();
        }
    }
}