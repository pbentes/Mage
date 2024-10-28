#include "Core/UUID.h"
#include <gtest/gtest.h>

#include <Scripting/Behaviour.h>
#include <Scripting/Scripting.h>

namespace EngineTests {
    TEST(Behaviour, CreateBehaviour) {
        Engine::AssetDatabase asset_db(std::vector<std::string> {"C:\\Users\\Pedro Bentes\\Desktop\\Mage\\tests\\project"});
        Engine::Scripting scripting;

        scripting.LoadLibrary(&asset_db);
        scripting.LoadUserScript("C:\\Users\\Pedro Bentes\\Desktop\\Mage\\tests\\project\\assets\\scenes\\script.lua");

        uint64_t entity = 1;
        uint64_t entity2 = 3;

        // 1_Player
        std::unique_ptr<Engine::Behaviour> bhvr = scripting.AttachBehaviourToEntity(Engine::UUID64(entity), "C:\\Users\\Pedro Bentes\\Desktop\\Mage\\tests\\project\\assets\\scenes\\script.lua");
        std::unique_ptr<Engine::Behaviour> bhvr2 = scripting.AttachBehaviourToEntity(Engine::UUID64(entity2), "C:\\Users\\Pedro Bentes\\Desktop\\Mage\\tests\\project\\assets\\scenes\\script.lua");

        bhvr->update(1);
        bhvr->update(1);
        bhvr2->update(1);

        sol::table test = scripting.m_Lua.get<sol::table>("_1_Player");
        int testi = test.get<int>("j");

        std::cout << "Test: " << testi << std::endl;
        
        /*EXPECT_EQ(10, behaviour.self.get<int>("j"));

        behaviour.update(0.0f);

        EXPECT_EQ(11, behaviour.self.get<int>("j"));

        EXPECT_STREQ("Behaviour", behaviour.self.get<const char*>("class"));*/
    }
}