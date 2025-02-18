#pragma once

#include "glm/fwd.hpp"
#include "renderer/renderer.hpp"

class OpenGl33: RendererInterface {
    public:
        void init() override;
        void load() override;
        void deinit() override;

        void clear(glm::vec4 color) override;
};
