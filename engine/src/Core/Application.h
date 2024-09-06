#pragma once

#include <raylib.h>
#include <entt/entt.hpp>

#define ENTT_STANDARD_CPP

namespace Engine {
    class Application {
        public:
            Application();
            ~Application();

            void run();
        public:
            entt::basic_scheduler<std::uint64_t> m_Scheduler;
    };
}