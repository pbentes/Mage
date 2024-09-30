#include "Behaviour.h"
#include "Debug/Logger.h"

namespace Engine {
    Behaviour::Behaviour(sol::state& lua_state, const std::string& script_path) {
        sol::load_result script = lua_state.load_file(script_path);
        if (!script.valid()) {
            sol::error err = script;
            ERROR(err.what());
            return;
        }

        self = script();

        // Setup Lifecycle Hooks
        hooks.start = self["start"];
        hooks.update = self["update"];
        hooks.late_update = self["late_update"];
        hooks.on_destroy = self["on_destroy"];
        hooks.on_enable = self["on_enable"];
        hooks.on_disable = self["on_disable"];

        // Setup Physics Hooks
        hooks.fixed_update = self["fixed_update"];
        hooks.on_trigger_enter = self["on_trigger_enter"];
        hooks.on_trigger_stay = self["on_trigger_stay"];
        hooks.on_trigger_exit = self["on_trigger_exit"];
        hooks.on_collision_enter = self["on_collision_enter"];
        hooks.on_collision_stay = self["on_collision_stay"];
        hooks.on_collision_exit = self["on_collision_exit"];

        // Setup Rendering Hooks
        hooks.on_draw_gizmos = self["on_draw_gizmos"];
        hooks.on_gui = self["on_gui"];
    }

    Behaviour::~Behaviour() {
        on_destroy();
    }

    // Lifecycle Hooks
    void Behaviour::start() {
        if (hooks.start.valid()) {
            hooks.start(self);
        }
    }

    void Behaviour::update(float delta) {
        if (hooks.update.valid()) {
            hooks.update(self, delta);
        }
    }

    void Behaviour::late_update(float delta) {
        if (hooks.late_update.valid()) {
            hooks.late_update(self, delta);
        }
    }

    void Behaviour::on_destroy() {
        if (hooks.on_destroy.valid()) {
            hooks.on_destroy(self);
        }
    }

    void Behaviour::on_enable() {
        if (hooks.on_enable.valid()) {
            hooks.on_enable(self);
        }
    }

    void Behaviour::on_disable() {
        if (hooks.on_disable.valid()) {
            hooks.on_disable(self);
        }
    }

    // Physics Hooks
    void Behaviour::fixed_update(float delta) {
        if (hooks.fixed_update.valid()) {
            hooks.fixed_update(self, delta);
        }
    }

    void Behaviour::on_trigger_enter() {
        if (hooks.on_trigger_enter.valid()) {
            hooks.on_trigger_enter(self);
        }
    }

    void Behaviour::on_trigger_stay() {
        if (hooks.on_trigger_stay.valid()) {
            hooks.on_trigger_stay(self);
        }
    }

    void Behaviour::on_trigger_exit() {
        if (hooks.on_trigger_exit.valid()) {
            hooks.on_trigger_exit(self);
        }
    }

    void Behaviour::on_collision_enter() {
        if (hooks.on_collision_enter.valid()) {
            hooks.on_collision_enter(self);
        }
    }

    void Behaviour::on_collision_stay() {
        if (hooks.on_collision_stay.valid()) {
            hooks.on_collision_stay(self);
        }
    }

    void Behaviour::on_collision_exit() {
        if (hooks.on_collision_exit.valid()) {
            hooks.on_collision_exit(self);
        }
    }

    // Rendering Hooks
    void Behaviour::on_draw_gizmos() {
        if (hooks.on_draw_gizmos.valid()) {
            hooks.on_draw_gizmos(self);
        }
    }

    void Behaviour::on_gui() {
        if (hooks.on_gui.valid()) {
            hooks.on_gui(self);
        }
    }
}