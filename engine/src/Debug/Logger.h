#pragma once

#include <chrono>
#include <format>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#define LOGGER_OUTPUT_COUT

//#define DO_NOT_OUTPUT_ERRORS
//#define DO_NOT_OUTPUT_DEBUG
//#define DO_NOT_OUTPUT_INFO

#ifndef DO_NOT_OUTPUT_ERRORS
    #define ERROR(...) ::Engine::Logger::GetInstance().Error(__VA_ARGS__)
#else 
    #define ERROR(...)
#endif

#ifndef DO_NOT_OUTPUT_DEBUG
    #define DEBUG(...) ::Engine::Logger::GetInstance().Debug(__VA_ARGS__)
#else
    #define DEBUG(...)
#endif

#ifndef DO_NOT_OUTPUT_INFO
    #define INFO(...)  ::Engine::Logger::GetInstance().Info(__VA_ARGS__)
#else
    #define INFO(...)
#endif

#ifndef NDEBUG
    #define ENABLE_ASSERTS
#endif

#ifdef ENABLE_ASSERTS
    #define ENGINE_ASSERT(condition, ...) ::Engine::Logger::GetInstance().Assert(condition, "ENGINE_ASSERTION_FAILED", ##__VA_ARGS__)
    #define ASSERT(condition, ...) ::Engine::Logger::GetInstance().Assert(condition, "ASSERTION_FAILED", ##__VA_ARGS__)
#else
    #define ENGINE_ASSERT(condition, ...) ((void)0)
    #define ASSERT(condition, ...) ((void)0)
#endif

namespace Engine {
    class Logger {
        public:
            static Logger& GetInstance() {
                static Logger instance;
                return instance;
            }

            Logger(const Logger&) = delete;
            Logger& operator=(const Logger&) = delete;

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

            template<typename... Args>
            static void Assert(bool condition, std::string prefix, std::format_string<Args...> message, Args&&... args) {
                if (!condition) {
                    ERROR(prefix + ": " + std::format(message, std::forward<Args>(args)...));
                }
            }

        private:
            Logger();
            ~Logger();
            template<typename... Args>
            void Log(const std::string& mode, Args&&... args) {
                std::ostringstream oss;

                auto now = std::chrono::system_clock::now();
                std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
                struct tm now_tm;
                localtime_s(&now_tm, &now_time_t);

                
                oss << "[" << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S") << "] ";
                oss << "[" << mode << "] ";
                (oss << ... << std::forward<Args>(args)) << std::endl;

                m_OutputStream << oss.str();
#ifdef LOGGER_OUTPUT_COUT
                std::cout      << oss.str();
#endif
                m_OutputStream.flush(); 
            }

        private:
            std::ofstream m_OutputStream;
    };

}