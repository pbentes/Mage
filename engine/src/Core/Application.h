#pragma once

#include <raylib.h>

namespace Engine {
    class Application {
        public:
            Application(const char* window_title);
            ~Application();

            void run();
        public:
            RenderTexture2D m_RenderTexture;
    };
}