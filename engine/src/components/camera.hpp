#pragma once

#include <scene/components.hpp>

#include "glm/ext/matrix_float4x4.hpp"

enum Projection {
    perspective,
    orthographic,
};

class Camera: Component {
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
