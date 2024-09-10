#pragma once

#include <sol/sol.hpp>

namespace Engine {
    typedef struct BehaviourComponent {
        sol::table self;
        struct {
            // Gameplay hooks
            sol::function start;
            sol::function on_destroy;
            sol::function update;
            sol::function late_update;

            // Physics hooks
            sol::function fixed_update;       // TODO: implement upon physics implementation
            sol::function on_trigger_enter;   // TODO: implement upon physics implementation
            sol::function on_trigger_stay;    // TODO: implement upon physics implementation
            sol::function on_trigger_exit;    // TODO: implement upon physics implementation
            sol::function on_collision_enter; // TODO: implement upon physics implementation
            sol::function on_collision_stay;  // TODO: implement upon physics implementation
            sol::function on_collision_exit;  // TODO: implement upon physics implementation

            // Rendering hooks
            sol::function on_draw_gizmos;
            sol::function on_gui;
        } hooks;
    } BehaviourComponent;
}