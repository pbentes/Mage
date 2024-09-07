#pragma once

#include <entt/entt.hpp>

namespace Engine {
    class Scripting: public entt::process<Scripting, std::double_t> {
        public:
            using delta_type = std::double_t;

            Scripting();
            ~Scripting();

            void init();
            void update(delta_type delta, void*);
            void succeeded();
            void failed();
            void aborted();
    };
}