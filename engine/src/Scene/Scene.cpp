#include "Scene.h"
#include "Core/UUID.h"
#include "Scene/Entity.h"

#include <Components/UUID.h>
#include <Components/Transform.h>
#include <Components/Tag.h>
#include <Components/Node.h>
#include <Components/SceneComponent.h>

#include <memory>

namespace Engine {
    Scene::Scene(const std::string& name, bool initalize) {}
    Scene::~Scene(){}

    void Scene::Initialize() {}

    std::shared_ptr<Entity> Scene::CreateEntity(const std::string& name) {
        Entity newEntity(std::make_shared<Scene>(this));

        newEntity.AddComponent<TagComponent>( TagComponent { .tag =  name } );
        newEntity.AddComponent<UUIDComponent>( UUIDComponent { .id = UUID64() } );

        m_RootNodes.push_back(std::make_shared<Entity>(newEntity));
        return std::make_shared<Entity>(newEntity);
    }

    std::shared_ptr<Entity> Scene::CreateEntity(std::shared_ptr<Entity> parent, const std::string& name) {
        Entity newEntity(std::make_shared<Scene>(this));

        newEntity.AddComponent<TagComponent>(name);
        newEntity.AddComponent<UUIDComponent>();

        parent->m_Children.push_back(std::make_shared<Entity>(newEntity));
        return std::make_shared<Entity>(newEntity);
    }
}