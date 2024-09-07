#include "Scripting.h"

#include <iostream>

namespace Engine {
    Scripting::Scripting() {}
    Scripting::~Scripting(){}

    void Scripting::init() {}
    void Scripting::update(Scripting::delta_type delta, void*) {
        std::cout << "Delta time: " << delta << std::endl;
    }
    void Scripting::succeeded() {}
    void Scripting::failed() {}
    void Scripting::aborted() {}
}