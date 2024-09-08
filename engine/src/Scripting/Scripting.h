#pragma once

#include <entt/entt.hpp>
#include <sol/sol.hpp>

#include <memory>

namespace Engine {
    class Scripting: public entt::process<Scripting, std::double_t> {
        public:
            using delta_type = std::double_t;

            Scripting(std::shared_ptr<entt::registry> registry);
            ~Scripting();

            void init();
            void update(delta_type delta, void*);
            void succeeded();
            void failed();
            void aborted();
        private:
            sol::state m_Lua;
            std::shared_ptr<entt::registry> m_Registry;
    };

    class ScriptingBehaviour {
        public:
            using delta_type = std::double_t;

            ScriptingBehaviour() = default;
            ~ScriptingBehaviour() = default;

            virtual void init() = 0; // Called when adding the script to the scripting process
            virtual void exit() = 0; // Called when removing the script to the scripting process
            virtual void update(delta_type delta_time) = 0; // Called every frame before rendering starts
            virtual void late_update(delta_type delta_time) = 0; // Called every frame after rendering ends
            virtual void fixed_update(delta_type delta_time) = 0; // Called every physics frame before processing physics
            virtual void fixed_late_update(delta_type delta_time) = 0; // Called every physics frame after processing physics
            virtual void on_gui(delta_type delta_time) = 0; // Called every frame, used to draw gui elements
    };
}