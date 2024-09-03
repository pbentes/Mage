#pragma once

#include <chrono>
#include <fstream>
#include <string>

#define PROFILING 1
#if PROFILING
#define PROFILE_SCOPE(name) InstrumentationTimer timer##__LINE__(name)
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCSIG__) InstrumentationTimer timer##__LINE__(name)
#else
#define PROFILE_SCOPE(name)
#define PROFILE_FUNCTION()
#endif

namespace Engine {
    struct ProfileResult
    {
        std::string Name;
        long long Start, End;
        uint32_t ThreadID;
    };

    struct InstrumentationSession
    {
        std::string Name;
    };

    class Instrumentor
    {
        private:
            InstrumentationSession* m_CurrentSession;
            std::ofstream m_OutputStream;
            int m_ProfileCount;
        public:
            Instrumentor();

            void BeginSession(const std::string& name, const std::string& filepath = "results.json");
            void EndSession();
            void WriteProfile(const ProfileResult& result);
            void WriteHeader();
            void WriteFooter();
            static Instrumentor& Get();
    };

    class InstrumentationTimer
    {
        public:
            InstrumentationTimer(const char* name);
            ~InstrumentationTimer();
            void Stop();
        private:
            const char* m_Name;
            std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
            bool m_Stopped;
    };
}