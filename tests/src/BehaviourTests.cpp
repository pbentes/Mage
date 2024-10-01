#include "Debug/Logger.h"
#include "sol/table.hpp"
#include "sol/types.hpp"
#include <gtest/gtest.h>

#include <Scripting/Behaviour.h>
#include <string>

namespace EngineTests {
    struct Behaviour {
        std::string Class = "Behaviour";
    };

    TEST(Behaviour, CreateBehaviour) {
        sol::state lua;
        lua.open_libraries(
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

        lua.script_file("C:\\Users\\Pedro Bentes\\Desktop\\Mage\\tests\\project\\library\\behaviour.lua");

        sol::table tbl = lua["Behaviour"];
        INFO(tbl.get<const char*>("class"));

        Engine::Behaviour behaviour(lua, "C:\\Users\\Pedro Bentes\\Desktop\\Mage\\tests\\project\\assets\\scenes\\script.lua");

        EXPECT_EQ(10, behaviour.self.get<int>("j"));

        behaviour.update(0.0f);

        EXPECT_EQ(11, behaviour.self.get<int>("j"));

        EXPECT_STREQ("Behaviour", behaviour.self.get<const char*>("class"));
    }
}