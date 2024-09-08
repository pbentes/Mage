#include "Scripting.h"

#include "../Debug/Instrumentor.h"

#include <sol/types.hpp>

namespace Engine {
    Scripting::Scripting(std::shared_ptr<entt::registry> registry) {
        this->m_Lua.open_libraries(sol::lib::base, sol::lib::io, sol::lib::math, sol::lib::table);
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