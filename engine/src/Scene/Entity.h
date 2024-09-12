#pragma once

#include "../Components/Tag.h"

#include <entt/entt.hpp>

namespace Engine {
    class Scene;

    class Entity {
        public:
            Entity() = default;
            Entity(entt::entity handle, Scene* scene): m_EntityHandle(handle), m_Scene(scene) {}
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

            operator uint32_t () const { return (uint32_t)m_EntityHandle; }
            operator entt::entity () const { return m_EntityHandle; }
            operator bool () const;

        private:
            entt::entity m_EntityHandle { entt::null };
            Scene* m_Scene = nullptr;
            inline static std::string DefaultName = "Unnamed";
    };
}