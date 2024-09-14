#pragma once

#include "../Scene/Entity.h"

#include <entt/entt.hpp>

namespace Engine {
    typedef struct NodeComponent {
        std::size_t children {};
        std::shared_ptr<Entity> first {};
        std::shared_ptr<Entity> prev {};
        std::shared_ptr<Entity> next {};
        std::shared_ptr<Entity> parent {};
    } NodeComponent;
}