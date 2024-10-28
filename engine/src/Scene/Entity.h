#pragma once

#include <Core/UUID.h>
#include <Scripting/Behaviour.h>

#include <memory>
#include <vector>

namespace Engine {
    class Entity {
        public:
            Entity() = default;
            ~Entity() = default;

            UUID64 GetUUID() const { return m_UUID; }
            bool IsScene() const { return m_IsScene; }

            void IterateChildren();
            void GetRelativeEntity(std::string path);
            sol::table GetComponent(std::string component);

            void OnInit();
            void OnDestroy();
        private:
            inline static std::string DefaultName = "Unnamed";
            UUID64 m_UUID;
            bool m_IsScene;

            std::vector<std::shared_ptr<Entity>> m_Children;
            std::weak_ptr<Entity> m_Parent;
            
            std::unordered_map<std::string, std::unique_ptr<Behaviour>> m_Behaviours;
    };
}