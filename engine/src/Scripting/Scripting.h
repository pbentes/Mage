#pragma once

#include <Core/UUID.h>
#include <Scripting/Behaviour.h>
#include <Assets/AssetDatabase.h>

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

            void LoadUserScript(std::string path);
            void LoadLibrary(AssetDatabase* assetDB);

            std::unique_ptr<Behaviour> AttachBehaviourToEntity(UUID64 entityId, std::string script);
            std::unique_ptr<void> LoadPanel();

        private:
            sol::table DeepCopyTable(const sol::table& original);
            bool IsMetatable(sol::table table, sol::table metatable);
            bool TablesAreEqual(sol::table a, sol::table b);

        public:
            sol::state m_Lua;

        private:
            std::unordered_map<std::string, std::string> m_ScriptBehaviour; // Maps a script's path to the behaviour
    };
}
