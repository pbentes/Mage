#pragma once

#include "../Scene/Entity.h"

#include <entt/entt.hpp>
#include <memory>

namespace Engine {
    typedef struct NodeComponent {
        std::shared_ptr<Entity> self;
        std::size_t children {};
        std::weak_ptr<Entity> first {};
        std::weak_ptr<Entity> prev {};
        std::weak_ptr<Entity> next {};
        std::weak_ptr<Entity> parent {};
    } NodeComponent;
}