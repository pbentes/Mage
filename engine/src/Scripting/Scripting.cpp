#include "Scripting.h"
#include "Debug/Logger.h"
#include "sol/table.hpp"

#include <unordered_set>

namespace Engine {
    Scripting::Scripting() {
        m_Lua.open_libraries(
            sol::lib::base,
            sol::lib::package,
            sol::lib::coroutine,
            sol::lib::string,
            sol::lib::os,
            sol::lib::math,
            sol::lib::table,
            sol::lib::debug,
            sol::lib::bit32,
            sol::lib::utf8
        );
    }

    // This is terrible but I don't know of another way to know what keys were added by a script
    void Scripting::LoadScript(std::string path) {
        sol::table global_before = m_Lua["_G"];
        std::unordered_set<std::string> keys_before;
        global_before.for_each([&](const sol::object& key, const sol::object& value) {
            if (key.is<std::string>()) {
                keys_before.insert(key.as<std::string>());
            }
        });

        sol::protected_function_result result = m_Lua.script_file(path);
        if (!result.valid()) {
            ERROR("Failed to load script");
        }
        
        sol::table global_after = m_Lua["_G"];
        std::unordered_set<std::string> keys_after;
        global_after.for_each([&](const sol::object& key, const sol::object& value) {
            if (key.is<std::string>()) {
                keys_after.insert(key.as<std::string>());
            }
        });

        for (const auto& key : keys_after) {
            if (keys_before.find(key) != keys_before.end()) {
                continue;
            }

            sol::object value = global_after[key];
            if (value.is<sol::table>()) {
                std::cout << "Key '" << key << "' is a table." << std::endl;
            } else {
                std::cout << "Key '" << key << "' is NOT a table." << std::endl;
            }
        }
    }

    sol::table Scripting::DeepCopyTable(const sol::table& original) {
        sol::table copy = m_Lua.create_table();
        for (const auto& kv : original) {
            sol::object key = kv.first;
            sol::object value = kv.second;

            if (value.is<sol::table>()) {
                copy[key] = DeepCopyTable(value.as<sol::table>());
            } else {
                copy[key] = value;
            }
        }
        return copy;
    }
}
