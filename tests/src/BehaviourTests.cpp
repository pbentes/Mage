#include <gtest/gtest.h>

#include <Scripting/Behaviour.h>

namespace EngineTests {
    TEST(Behaviour, CreateBehaviour) {
        sol::state lua;
        Engine::Behaviour behaviour(lua, "C:\\Users\\Pedro Bentes\\Desktop\\Mage\\tests\\project\\scenes\\script.lua");

        EXPECT_EQ(10, behaviour.self.get<int>("j"));

        behaviour.update(0.0f);

        EXPECT_EQ(11, behaviour.self.get<int>("j"));
    }
}