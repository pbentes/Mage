#pragma once

#include "../Scene/Entity.h"

#include <entt/entt.hpp>

namespace Engine {
    typedef struct NodeComponent {
        std::size_t children{};
        Entity* first {};
        Entity* prev {};
        Entity* next {};
        Entity* parent {};
    } NodeComponent;
}