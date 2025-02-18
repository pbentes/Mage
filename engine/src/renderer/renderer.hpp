#pragma once

#include "glm/fwd.hpp"

class RendererInterface {
    public:
        virtual void init() = 0;
        virtual void load() = 0;
        virtual void deinit() = 0;

        virtual void clear(glm::vec4 color) = 0;
};
