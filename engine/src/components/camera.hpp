#pragma once

#include "../core/serializable.hpp"
#include "../scene/components.hpp"

#include "glm/ext/matrix_float4x4.hpp"

enum Projection {
    perspective = 0,
    orthographic = 1,
};

class Camera: Serializable, Component {
    public:
        glm::mat4 project();
    public:
        Projection projection = Projection::perspective;

        // Perspective
        float fov = 75.0f;
        float aspect_ratio;

        // Orthographic
        float size;

        // Shared
        float near_plane = 0.1f;
        float far_plane = 1000.0f;
};
