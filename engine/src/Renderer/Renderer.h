#pragma once

#include <entt/entt.hpp>
#include <raylib.h>

namespace Engine {
    class Renderer: public entt::process<Renderer, std::double_t> {
        public:
            using delta_type = std::double_t;

            Renderer();
            ~Renderer();

            void init();
            void update(delta_type delta, void*);
            void succeeded();
            void failed();
            void aborted();
        public:
            RenderTexture2D m_RenderTexture;
    };
}