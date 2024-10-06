#pragma once

#include <sol/sol.hpp>

namespace Engine {
    class Behaviour {
        public:
            Behaviour(sol::state& lua_state, const std::string& script_path);
            ~Behaviour();

            // Lifecycle Hooks
            void start();
            void update(float delta);
            void late_update(float delta);
            void on_destroy();
            void on_enable();
            void on_disable();

            // Physics Hooks
            void fixed_update(float delta);
            void on_trigger_enter();
            void on_trigger_stay();
            void on_trigger_exit();
            void on_collision_enter();
            void on_collision_stay();
            void on_collision_exit();

            // Rendering Hooks
            void on_draw_gizmos();
            void on_gui();

        public:
            sol::table self;
            std::string script_path;
            
        private:
            struct {
                // Lifecycle Hooks
                sol::function start { sol::nil };
                sol::function update { sol::nil };
                sol::function late_update { sol::nil };
                sol::function on_destroy { sol::nil };
                sol::function on_enable { sol::nil };
                sol::function on_disable { sol::nil };

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
    };
}