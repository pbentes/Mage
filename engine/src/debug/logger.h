#pragma once

#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>

#define LOGGER_OUTPUT_COUT

#ifndef DO_NOT_OUTPUT_ERRORS
    #define ERROR(...) Error(__VA_ARGS__)
#else 
    #define ERROR(...)
#endif

#ifndef DO_NOT_OUTPUT_DEBUG
    #define DEBUG(...) Debug(__VA_ARGS__)
#else
    #define DEBUG(...)
#endif

#ifndef DO_NOT_OUTPUT_INFO
    #define INFO(...)  Info(__VA_ARGS__)
#else
    #define INFO(...)
#endif

void create_logger(const char* file_path);
std::ofstream* get_current_logger();
void close_logger();

template<typename... Args>
void Log(const char* mode, Args&&... args) {
    std::ofstream* log = get_current_logger();

    std::ostringstream oss;

    auto now = std::chrono::system_clock::now();
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    struct tm now_tm;
    localtime_s(&now_tm, &now_time_t);

    oss << "[" << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S") << "] ";
    oss << "[" << mode << "] ";
    (oss << ... << std::forward<Args>(args)) << std::endl;

#ifdef LOGGER_OUTPUT_COUT
    std::cout << oss.str();
#endif
    if (log->is_open()) {
        *log << oss.str();
        log->flush();
    }
}

template<typename... Args>
void Error(Args&&... args) {
    Log("ERROR", std::forward<Args>(args)...);
}

template<typename... Args>
void Debug(Args&&... args) {
    Log("DEBUG", std::forward<Args>(args)...);
}

template<typename... Args>
void Info(Args&&... args) {
    Log("INFO", std::forward<Args>(args)...);
}