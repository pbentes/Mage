#pragma once

#include "sol/forward.hpp"
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
}