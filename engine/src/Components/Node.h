#pragma once

#include <entt/entt.hpp>

namespace Engine {
    typedef struct NodeComponent {
        std::size_t children{};
        entt::entity first{entt::null};
        entt::entity prev{entt::null};
        entt::entity next{entt::null};
        entt::entity parent{entt::null};
    } NodeComponent;
}