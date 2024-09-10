#pragma once

namespace Engine {
    typedef struct Camera2DComponent {
        float rotation;
        float zoom;
    } Camera2DComponent;

    typedef struct Camera3DComponent {
        float fov;
        enum {
            perspective,
            orthographic
        } projection { perspective };
    } Camera3DComponent;
}