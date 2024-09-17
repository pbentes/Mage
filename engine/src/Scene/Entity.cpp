#include "Entity.h"

#include "../Components/Node.h"
#include "Scene.h"
#include <cstddef>
#include <memory>

namespace Engine {
    bool Entity::IsValid() const { 
        return (m_EntityHandle != entt::null) && m_Scene && m_Scene->m_Registry.valid(m_EntityHandle); 
    }
    
    std::shared_ptr<Entity> Entity::GetParent() {
        if(auto parent = GetComponent<NodeComponent>().parent.lock()) {
            return parent;
        }
        return NULL;
    }

    std::vector<std::shared_ptr<Entity>> Entity::GetChildren() {
        std::vector<std::shared_ptr<Entity>> children;
        NodeComponent selfNode = this->GetComponent<NodeComponent>();

        if (selfNode.children == 0)
            return children;
        
        std::shared_ptr<Entity> currentEntity = selfNode.first.lock();
        NodeComponent currentChildNode = selfNode.first.lock()->GetComponent<NodeComponent>();
        while (currentChildNode.next.lock()) {
            children.push_back(currentEntity);

            currentEntity = currentChildNode.next.lock();
            currentChildNode = currentEntity->GetComponent<NodeComponent>();
        }

        return children;
    }

    //void Entity::RemoveChild(std::shared_ptr<Entity> child) {
    //
    //}

    void Entity::MoveNode(std::shared_ptr<Entity> parent, std::shared_ptr<Entity> previousSibling) {
        NodeComponent thisNodeComponent = GetComponent<NodeComponent>();
        if (IsDescendentOf(parent) != 1) {
            return;
        }
    }

    int Entity::IsAncestorOf(std::shared_ptr<Entity> node) { return false; }

    int Entity::IsDescendentOf(std::shared_ptr<Entity> node) { return true; }
    
	Entity::operator bool() const { 
        return IsValid(); 
    }
}