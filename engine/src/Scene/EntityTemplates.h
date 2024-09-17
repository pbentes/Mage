#pragma once

#include "Entity.h"
#include "Scene/Scene.h"

namespace Engine {
    template<typename T, typename... Args>
	T& Entity::AddComponent(Args&&... args) {
        return m_Scene->m_Registry.emplace<T>(m_EntityHandle, std::forward<Args>(args)...);
    }

    template<typename T>
	T& Entity::GetComponent() {
        return m_Scene->m_Registry.get<T>(m_EntityHandle);
    }

    template<typename T>
	const T& Entity::GetComponent() const {
        return m_Scene->m_Registry.get<T>(m_EntityHandle);
    }

    template<typename... T>
    bool Entity::HasComponent() {
        return m_Scene->m_Registry.all_of<T...>(m_EntityHandle);
    }

    template<typename... T>
    bool Entity::HasComponent() const {
        return m_Scene->m_Registry.all_of<T...>(m_EntityHandle);
    }

    template<typename...T>
    bool Entity::HasAny() {
        return m_Scene->m_Registry.any_of<T...>(m_EntityHandle);
    }

    template<typename...T>
    bool Entity::HasAny() const {
        return m_Scene->m_Registry.any_of<T...>(m_EntityHandle);
    }

    template<typename T>
    void Entity::RemoveComponent() {
        m_Scene->m_Registry.remove<T>(m_EntityHandle);
    }

    template<typename T>
    void Entity::RemoveComponentIfExists() {
        if (!HasComponent<T>())
            return;
        m_Scene->m_Registry.remove<T>(m_EntityHandle);
    }
}