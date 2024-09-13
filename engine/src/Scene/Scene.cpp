#include "Scene.h"

#include "../Components/Node.h"
#include "../Components/SceneComponent.h"
#include "../Components/Tag.h"
#include "../Components/Transform.h"
#include "../Components/UUID.h"
#include "Entity.h"

#include <cstddef>
#include <cstdint>

namespace Engine {
    std::unordered_map<uint64_t, Scene*> s_ActiveScenes;

    Scene::Scene(const std::string& name, bool isEditorScene, bool initalize): m_Name(name), m_IsEditorScene(isEditorScene) {
        m_SceneEntity = m_Registry.create();
        m_Registry.emplace<SceneComponent>(m_SceneEntity, m_SceneID);
        s_ActiveScenes[m_SceneID] = this;

        if (!initalize)
			return;
    }
    
    Scene::~Scene() {
        m_Registry.clear();
        s_ActiveScenes.erase(this->m_SceneID);
    }

    Entity Scene::CreateEntity(const std::string& name) {
        return CreateChildEntity({}, name);
    }

    Entity Scene::CreateChildEntity(Entity parent, const std::string& name) {
        auto entity = Entity{ m_Registry.create(), this };
        entity.AddComponent<TransformComponent>();

        if (!name.empty())
			entity.AddComponent<TagComponent>(name);

        auto& node = entity.AddComponent<NodeComponent>();
        if (parent) {
            // Add new node to the scene tree
            node.parent = parent;
            NodeComponent& parentNode = parent.GetComponent<NodeComponent>();
            parentNode.children++;
            node.next = parentNode.first;
            parentNode.first = entity;
        }
        
        auto& idComponent = entity.AddComponent<UUIDComponent>();

        m_EntityMap[idComponent.id] = entity;

        return entity;
    }

    void Scene::SubmitToDestroyEntity(Entity entity) {
        bool isValid = m_Registry.valid((entt::entity)entity);
        if (!isValid)
		{
            return;
        }

        SubmitPostUpdateFunc([entity]() {
            entity.m_Scene->DestroyEntity(entity);
        });
    }

    void Scene::DestroyEntity(Entity entity, bool excludeChildren, bool first) {
        if (!entity)
			return;

        NodeComponent& node = entity.GetComponent<NodeComponent>();

        if (!excludeChildren) {
            // Recursively delete all children
            for (size_t i = 0; i < node.children; i++) {
                Entity childToDestroy = node.first;
                node.first = childToDestroy.GetComponent<NodeComponent>().next;
                DestroyEntity(childToDestroy, excludeChildren, false);
            }
        } else {
            // Reparent all children
            Entity currentChild = node.first;
            for (size_t i = 0; i < node.children; i++) {
                NodeComponent currentChildNode = currentChild.GetComponent<NodeComponent>();

                currentChildNode.parent = node.parent;
                node.parent.GetComponent<NodeComponent>().children++;
                currentChild = currentChildNode.next;
            }
        }

        // TODO: Call OnDestroy on the behaviours here

        UUID64 id = entity.GetUUID();

        m_Registry.destroy(entity);
        m_EntityMap.erase(id);
    }
}