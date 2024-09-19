#include <gtest/gtest.h>

#include <Scene/Scene.h>
#include <Scene/Entity.h>

#include <Components/UUID.h>
#include <Components/Transform.h>
#include <Components/Tag.h>
#include <Components/Node.h>

namespace EngineTests {
    TEST(Scene, CreateNewScene) {
        // Arrange
        Engine::Scene scene("test scene", false);

        EXPECT_STRNE("hello", "world");
        EXPECT_EQ(7 * 6, 42);
    }

    TEST(Scene, CreateNewEntityInScene) {
        EXPECT_STRNE("hello", "world");
        EXPECT_EQ(7 * 6, 42);
    }

    TEST(Scene, CreateSceneHierarchy) {
        EXPECT_STRNE("hello", "world");
        EXPECT_EQ(7 * 6, 42);
    }

    TEST(Scene, GetParent) {
        EXPECT_STRNE("hello", "world");
        EXPECT_EQ(7 * 6, 42);
    }

    TEST(Scene, GetChildren) {
        EXPECT_STRNE("hello", "world");
        EXPECT_EQ(7 * 6, 42);
    }
}
