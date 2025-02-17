#pragma once

#include "core/uuid.hpp"

#include "../scripting/behaviour.hpp"

#include <map>
#include <memory>
#include <string>
#include <vector>

class Entity {
    public:
        Entity();
        ~Entity();

        std::shared_ptr<Behaviour> get_component(std::string component);
        std::shared_ptr<Entity> get_parent();
        std::vector<std::shared_ptr<Entity>> get_parentchildren();
        std::shared_ptr<Entity> get_entity(std::string entity_path);

    private:
        Uuid64 uuid;
        std::map<std::string, Behaviour> behaviours;

        std::shared_ptr<Entity> parent;
        std::vector<std::shared_ptr<Entity>> children;
};
