#pragma once

#include <cmath>

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
            entt::basic_scheduler<std::double_t> m_Scheduler;
    };
}