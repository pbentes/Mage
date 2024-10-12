#pragma once

#include <raylib.h>

namespace Engine {
    class Application {
        public:
            Application();
            ~Application();

            void run();
            void CloseApplication();
        
        private:
            bool ApplicationShouldClose = false;
    };
}