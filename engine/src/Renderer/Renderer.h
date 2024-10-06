#pragma once

#include <raylib.h>

namespace Engine {
    class Renderer {
        public:
            Renderer() = default;
            ~Renderer() = default;

            void init();
            void update(float delta);
            void succeeded();
            void failed();
            void aborted();
        private:
            RenderTexture2D m_RenderTexture;
    };
}