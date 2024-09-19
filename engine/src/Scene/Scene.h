#pragma once

#include "Entity.h"

#include <Core/UUID.h>

#include <entt/entt.hpp>

#include <functional>
#include <memory>

namespace Engine {
    class Scene {
        public:
            Scene(const std::string& name, bool initalize);
            ~Scene();

            // Initialize the scene
            void Initialize();

            // Create a new root entity
            Entity CreateEntity(const std::string& name = "");

            // Create a new entity within the scene tree
            Entity CreateEntity(Entity parent, const std::string& name = "");

            // Move an entity in the scene tree to a certain index of the children list of the parent
            void MoveEntity(Entity entity, Entity parent, int index);

            // Destroy entity
		    void DestroyEntity(Entity entity, bool excludeChildren = false, bool destroyNow = false);

            // Find all entities with a given name
            std::vector<std::shared_ptr<Entity>> FindEntitiesByName(const std::string& name);

            // Find an entity with a given UUID
            std::shared_ptr<Entity> GetEntityByUUID(UUID64 uuid);

            // Execute func for every entity descending from root
            void TraverseEntities(std::shared_ptr<Entity> root, std::function<void(std::shared_ptr<Entity>)> func);

            // Execute func for every entity in the scene
            void TraverseEntities(std::function<void(std::shared_ptr<Entity>)> func);

            // Get the entity ID
            UUID64 GetUUID() const { return m_SceneID; }

            // Cast scene to UUID64
            operator UUID64 () const { return GetUUID(); };
            
        public:
            entt::registry m_Registry;
            std::vector<std::shared_ptr<Entity>> rootNodes;

        private:
            UUID64 m_SceneID;
            std::string m_Name;
            bool m_IsEditorScene;

            friend class Entity;
    };
}