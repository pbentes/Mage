#pragma once

#include <Scene/Entity.h>
#include <Scene/Scene.h>

#include <memory>

namespace Engine {
    template<typename ...Components>
    void AddComponentsToEntity(std::shared_ptr<Entity> entity, const Components&... components ) {
        int componentIndex = 0;
        ([&]
        {
            entity->AddComponent<Components>(components[componentIndex]);
            ++componentIndex;
        } (), ...);
    }

    // Create a new root entity with the components passed in the template
    template<typename ...Components>
    std::shared_ptr<Entity> Scene::CreateEntity(const std::string& name, const Components&... components) {
        std::shared_ptr<Entity> newEntity = CreateEntity(name);
        AddComponentsToEntity<Components...>(newEntity, components...);
    }

    // Create a new entity within the scene tree with the components passed in the template
    template<typename ...Components>
    std::shared_ptr<Entity> Scene::CreateEntity(std::shared_ptr<Entity> parent, const std::string& name, const Components&... components) {
        std::shared_ptr<Entity> newEntity = CreateEntity(parent, name);
        AddComponentsToEntity<Components...>(newEntity, components...);
    }
}