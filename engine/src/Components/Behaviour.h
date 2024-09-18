#pragma once

#include "sol/types.hpp"
#include <sol/sol.hpp>

namespace Engine {
    typedef struct Behaviour {
        sol::table self;
        struct {
            // Gameplay hooks
            sol::function start { sol::nil };
            sol::function on_destroy { sol::nil };
            sol::function update { sol::nil };
            sol::function late_update { sol::nil };

            // Physics hooks
            sol::function fixed_update { sol::nil };       // TODO: implement upon physics implementation
            sol::function on_trigger_enter { sol::nil };   // TODO: implement upon physics implementation
            sol::function on_trigger_stay { sol::nil };    // TODO: implement upon physics implementation
            sol::function on_trigger_exit { sol::nil };    // TODO: implement upon physics implementation
            sol::function on_collision_enter { sol::nil }; // TODO: implement upon physics implementation
            sol::function on_collision_stay { sol::nil };  // TODO: implement upon physics implementation
            sol::function on_collision_exit { sol::nil };  // TODO: implement upon physics implementation

            // Rendering hooks
            sol::function on_draw_gizmos { sol::nil };
            sol::function on_gui { sol::nil };
        } hooks;
    } Behaviour;

    typedef struct BehaviourListComponent {
        std::vector<Behaviour> behaviours;
    } BehaviourListComponent;
}