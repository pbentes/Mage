#pragma once

namespace Engine {
    class Application {
        public:
            Application(const char* window_title);
            ~Application();

            void run();
    };
}