#include "../interfaces/input.hpp"

#include "../debug/logger.hpp"
#include "Arena.hpp"
#include "toml/value.hpp"

#include <Map.hpp>
#include <string>

Map* action_map = nullptr;
InputAPI api;

void initialize(InputAPI input_api) {
    action_map =  mapCreate();
    api = input_api;
}

void input_update() {
    for(int i = 0; i < MAP_BUCKETS; i++) {
        if(action_map->buckets[i].key == nullptr)
            continue;
        
        MapElement* element = &action_map->buckets[i];
        do {
            api.update((Action*)element->value);
        } while(element->next != nullptr);
    }
}

void shutdown() {
    if(action_map == nullptr) {
        ERROR("Input system has not been initialized.");
        return;
    }
    mapDestroy(action_map);
}

void register_action(const unsigned char* action_name, int key, unsigned int modifiers) {
    if(action_map == nullptr) {
        ERROR("Input system has not been initialized.");
        return;
    }

    Action* action = (Action*)arenaAlloc(action_map->arena, sizeof(Action));

    action->name = (const char*)action_name;
    action->binding = key;
    action->modifiers = modifiers;

    mapSet(action_map, action_name, action);
}

void unregister_action(const unsigned char* action_name) {
    if(action_map == nullptr) {
        ERROR("Input system has not been initialized.");
        return;
    }
    
    // Unregister action doesn't free the memory until the map is destroyed or cleared
    // This is intentional
    mapRemove(action_map, action_name);
}

bool is_action_pressed(const unsigned char* action_name) {
    if(action_map == nullptr) {
        ERROR("Input system has not been initialized.");
        return false;
    }

    Action* action = (Action*)mapGet(action_map, action_name);
    if(action == nullptr) {
        ERROR("Action (", action_name, ") does not exist");
        return false;
    }
    return action->is_pressed;
}

bool is_action_just_pressed(const unsigned char* action_name) {
    if(action_map == nullptr) {
        ERROR("Input system has not been initialized.");
        return false;
    }

    Action* action = (Action*)mapGet(action_map, action_name);
    if(action == nullptr) {
        ERROR("Action (", action_name, ") does not exist");
        return false;
    }
    return action->just_pressed;
}

bool is_action_just_released(const unsigned char* action_name) {
    if(action_map == nullptr) {
        ERROR("Input system has not been initialized.");
        return false;
    }

    Action* action = (Action*)mapGet(action_map, action_name);
    if(action == nullptr) {
        ERROR("Action (", action_name, ") does not exist");
        return false;
    }
    return action->just_released;
}

void rebind_action(const unsigned char* action_name, int key, unsigned int modifiers) {
    if(action_map == nullptr) {
        ERROR("Input system has not been initialized.");
        return;
    }

    Action* action = (Action*)mapGet(action_map, action_name);
    if(action == nullptr) {
        ERROR("Action (", action_name, ") does not exist");
        return;
    }

    action->binding = key;
    action->modifiers = modifiers;
}

toml::value serialize_action_map() {
    toml::value output(toml::table{
        {"input_actions", toml::array{}},
    });

    auto& input_actions_array = output.at("input_actions");

    for(int i = 0; i < MAP_BUCKETS; i++) {
        if(action_map->buckets[i].key == nullptr)
            continue;
        
        MapElement* element = &action_map->buckets[i];
        do {
            toml::value v1(toml::table{ {"action_name", element->key}, {"key", ((Action*)element->value)->binding}, {"modifiers", ((Action*)element->value)->modifiers} });
            input_actions_array.push_back(std::move(v1));
        } while(element->next != nullptr);
    }
    return output;
}

void deserialize_action_map(toml::array input_actions_array) {
    for(int i = 0; i < input_actions_array.size(); i++) {
        toml::value t = input_actions_array[i];
        if(!t.is_table())
            continue;

        std::string action_name = t.as_table().at("action_name").as_string();
        int key = t.as_table().at("key").as_integer();
        unsigned int modifiers = t.as_table().at("modifiers").as_integer();

        register_action((const unsigned char*)action_name.c_str(), key, modifiers);
    }
}
