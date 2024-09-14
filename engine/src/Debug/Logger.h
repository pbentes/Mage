#pragma once

#include <format>
#include <fstream>
#include <string>

#define ERROR(message) ::Engine::Logger::GetInstance().Error(message)
#define DEBUG(message) ::Engine::Logger::GetInstance().Debug(message)
#define INFO(message)  ::Engine::Logger::GetInstance().Info(message)

namespace Engine {
    class Logger {
        public:
            static Logger& GetInstance() {
                static Logger instance;
                return instance;
            }

            Logger(const Logger&) = delete;
            Logger& operator=(const Logger&) = delete;

            void Error(const std::string message);
            void Debug(const std::string message);
            void Info(const std::string message);

            template<typename... Args>
            static void Assert(bool condition, std::string prefix, std::format_string<Args...> message, Args&&... args);

        private:
            Logger();
            ~Logger();
            void Log(const std::string message, const std::string mode);
            
        private:
            std::ofstream m_OutputStream;
    };

}