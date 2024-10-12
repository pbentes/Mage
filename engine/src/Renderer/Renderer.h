#pragma once

#include <Core/Application.h>

#include <raylib.h>

namespace Engine {
    class Renderer {
        public:
            Renderer(Application* app);
            ~Renderer() = default;

            void init();
            void update(float delta);
        private:
            Application* m_App;
            RenderTexture2D m_RenderTexture;
    };
}