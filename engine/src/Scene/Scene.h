#pragma once

#include "Entity.h"

#include "../Core/UUID.h"

#include <cstdint>
#include <entt/entt.hpp>

namespace Engine {
    class Scene {
        public:
            Scene(const std::string& name, bool isEditorScene, bool initalize);
            ~Scene();

            Entity CreateEntity(const std::string& name = "");
            Entity CreateChildEntity(Entity parent, const std::string& name = "");
            void SubmitToDestroyEntity(Entity entity);
		    void DestroyEntity(Entity entity, bool excludeChildren = false, bool first = true);
        
        private:
            template<typename Fn>
            void SubmitPostUpdateFunc(Fn&& func)
            {
                m_PostUpdateQueue.emplace_back(func);
            }
            
        public:
            const std::string& m_Name;
            bool m_IsEditorScene;
            entt::entity m_SceneEntity = entt::null;
            entt::registry m_Registry;
            std::unordered_map<uint64_t, Entity> m_EntityMap;
            
        private:
            UUID64 m_SceneID;
            std::vector<std::function<void()>> m_PostUpdateQueue;

            friend class Entity;
    };
}