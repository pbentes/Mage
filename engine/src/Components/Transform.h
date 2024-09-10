#pragma once

#include <raylib.h>

namespace Engine {
    typedef struct TransformComponent {
        Vector3 position;
        Quaternion rotation;
        Vector3 scale;
        Vector3 origin;
    } TransformComponent;
}