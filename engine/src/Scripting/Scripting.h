#pragma once

#include <Core/UUID.h>
#include <Scripting/Behaviour.h>

#include <sol/sol.hpp>
#include "sol/table.hpp"

#include <memory>
#include <string>
#include <unordered_map>

namespace Engine {
    class Scripting {
        public:
            Scripting();
            ~Scripting() = default;

            void LoadScript(std::string path);

            std::unique_ptr<Behaviour> LoadBehaviour(UUID64 entityId, sol::table behaviour);
            std::unique_ptr<void> LoadPanel();

        private:
            sol::table DeepCopyTable(const sol::table& original);

        private:
            sol::state m_Lua;
            std::unordered_map<std::string, std::vector<std::string>> m_ScriptKeys; // Maps a script's path to the top level keys in that script (Tables, Variables, Functions)
    };
}
