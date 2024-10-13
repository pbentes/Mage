#include "Scripting.h"

#include "Core/UUID.h"
#include "Debug/Logger.h"
#include "Scripting/Behaviour.h"

#include "sol/optional_implementation.hpp"
#include "sol/table.hpp"

#include <memory>
#include <string>
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
    void Scripting::LoadUserScript(std::string path) {
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

        sol::optional<sol::table> BehaviourBaseOptional = m_Lua.get<sol::optional<sol::table>>("Behaviour");
        if (!BehaviourBaseOptional)
            INFO("Loading user script but behaviour base table is not loaded");

        for (const auto& key : keys_after) {
            if (keys_before.find(key) != keys_before.end()) {
                continue;
            }

            sol::object value = global_after[key];
            if (value.is<sol::table>()) {
                std::cout << "Key '" << key << "' is a table." << std::endl;

                if (!BehaviourBaseOptional)
                    continue;

                if (IsMetatable(m_Lua.get<sol::table>(key), BehaviourBaseOptional.value())) {
                    m_ScriptBehaviour[path] = key;
                }
            } else {
                std::cout << "Key '" << key << "' is NOT a table." << std::endl;
            }
        }
    }

    void Scripting::LoadLibrary(std::string path) {
        sol::protected_function_result result = m_Lua.script_file(path);
        if (!result.valid()) {
            ERROR("Failed to load script");
        }
    }

    std::unique_ptr<Behaviour> Scripting::AttachBehaviourToEntity(UUID64 entityId, std::string script) {
        auto key = m_ScriptBehaviour.find(script);
        if (key == m_ScriptBehaviour.end()) {
            ERROR("Specified Script \"", script, "\" doesn't contain a behaviour.");
            return NULL;
        }

        std::string newKey = "Entity" + std::to_string(entityId.m_UUID) + "_" + key->second;
        m_Lua[newKey] = DeepCopyTable(m_Lua.get<sol::table>(key->second));

        sol::table tbl = m_Lua.get<sol::table>(newKey);
        Behaviour bhvr(tbl);

        return std::make_unique<Behaviour>(bhvr);
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

    bool Scripting::TablesAreEqual(sol::table a, sol::table b) {
        const void* a_ptr = a.pointer();
        const void* b_ptr = b.pointer();
        return a_ptr == b_ptr;
    }

    bool Scripting::IsMetatable(sol::table table, sol::table metatable) {
        sol::optional<sol::table> opt_index = table.get<sol::optional<sol::table>>("__index");
        if (!opt_index)
            return false;

        sol::table index = opt_index.value();

        return TablesAreEqual(index, metatable);
    }
}
