#include "Scripting.h"

#include "../Debug/Instrumentor.h"

namespace Engine {
    Scripting::Scripting(std::shared_ptr<entt::registry> registry) {
        this->m_Registry = registry;
    }
    Scripting::~Scripting(){}

    void Scripting::init() {}
    void Scripting::update(Scripting::delta_type delta, void*) {
        PROFILE_SCOPE("Scripting Update");
    }
    void Scripting::succeeded() {}
    void Scripting::failed() {}
    void Scripting::aborted() {}
}