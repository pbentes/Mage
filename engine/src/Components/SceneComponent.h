#pragma once

#include "../Core/UUID.h"

namespace Engine {
    // The scene component is used to embedd scenes within one another
    typedef struct SceneComponent {
        UUID64 SceneID;
    } SceneComponent;
} 