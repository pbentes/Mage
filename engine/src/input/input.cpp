#include "input.hpp"
#include "platform/platform.hpp"

Action::Action(std::string name, int binding, unsigned int modifiers) {
    this->name = name;
    this->binding = binding;
    this->modifiers = modifiers;

    Input::getInstance()->actions.push_back(this);
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

void Input::update() {
    Platform* platform = Platform::getInstance();
    for(int i = 0; i < actions.size(); i++) {
        platform->input_interface->update(actions[i]);
    }
}
