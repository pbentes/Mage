#pragma once

#include <Core/UUID.h>
#include <Scripting/Behaviour.h>

#include <memory>
#include <vector>

namespace Engine {
    class Scene;

    class Entity {
        public:
            Entity(std::weak_ptr<Scene> scene): m_Scene(scene) {}
            ~Entity() = default;

        private:
            inline static std::string DefaultName = "Unnamed";
            std::string m_SceneName;
            UUID64 m_UUID;

            std::weak_ptr<Scene> m_Scene;
            std::vector<std::shared_ptr<Entity>> m_Children;
            std::weak_ptr<Entity> m_Parent;
            
            std::unordered_map<std::string, std::unique_ptr<Behaviour>> m_Behaviours;

            friend class Scene;
    };
}