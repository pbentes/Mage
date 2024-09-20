#pragma once

#include <Components/Tag.h>
#include <Components/UUID.h>

#include <entt/entt.hpp>

#include <memory>
#include <vector>

namespace Engine {
    class Scene;

    class Entity {
        public:
            Entity(std::weak_ptr<Scene> scene): m_Scene(scene) {}
            ~Entity() = default;
            
            template<typename T, typename... Args>
		    T& AddComponent(Args&&... args);

            template<typename T>
            T& GetComponent();

            template<typename T>
            const T& GetComponent() const;

            template<typename... T>
            bool HasComponent();

            template<typename... T>
            bool HasComponent() const;

            template<typename...T>
            bool HasAny();

            template<typename...T>
            bool HasAny() const;

            template<typename T>
            void RemoveComponent();

            template<typename T>
            void RemoveComponentIfExists();

            std::string& Name() { return HasComponent<TagComponent>() ? GetComponent<TagComponent>().tag : DefaultName; }
            const std::string& Name() const { return HasComponent<TagComponent>() ? GetComponent<TagComponent>().tag : DefaultName; }
            bool IsValid() const;
            UUID64 GetUUID() const { return GetComponent<UUIDComponent>().id; }

            std::shared_ptr<Entity> GetParent();
            std::vector<std::shared_ptr<Entity>> GetChildren();

            // Operators
            operator uint32_t () const { return (uint32_t)m_EntityHandle; }
            operator entt::entity () const { return m_EntityHandle; }
            operator UUID64 () const { return GetUUID(); };
            operator bool () const;
            
        private:
            entt::entity m_EntityHandle { entt::null };
            std::weak_ptr<Scene> m_Scene;
            std::vector<std::shared_ptr<Entity>> m_Children;
            std::weak_ptr<Entity> m_Parent;
            inline static std::string DefaultName = "Unnamed";

            friend class Scene;
    };
}