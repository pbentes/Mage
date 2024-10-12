#include <gtest/gtest.h>

#include <Scripting/Behaviour.h>
#include <Scripting/Scripting.h>

namespace EngineTests {
    TEST(Behaviour, CreateBehaviour) {
        Engine::Scripting scripting;

        scripting.LoadScript("C:\\Users\\Pedro Bentes\\Desktop\\Mage\\tests\\project\\library\\behaviour.lua");
        scripting.LoadScript("C:\\Users\\Pedro Bentes\\Desktop\\Mage\\tests\\project\\assets\\scenes\\script.lua");

        /*EXPECT_EQ(10, behaviour.self.get<int>("j"));

        behaviour.update(0.0f);

        EXPECT_EQ(11, behaviour.self.get<int>("j"));

        EXPECT_STREQ("Behaviour", behaviour.self.get<const char*>("class"));*/
    }
}