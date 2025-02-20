#include "input.hpp"
#include "platform/platform.hpp"

Action::Action(std::string name, int binding, unsigned int modifiers) {
    this->binding = binding;
    this->modifiers = modifiers;

    Input::getInstance()->actions[name] = this;
}

Input* Input::instancePtr = nullptr;

Input* Input::getInstance() {
    if (instancePtr == nullptr) {
        if (instancePtr == nullptr) {
            instancePtr = new Input();
        }
    }
    return instancePtr;
}

Action* Input::action(std::string action_name) {
    return actions[action_name];
}

void Input::update() {
    Platform* platform = Platform::getInstance();
    for(auto& action: actions) {
        platform->input_interface->update(action.second);
    }
}
