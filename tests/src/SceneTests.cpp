#include <gtest/gtest.h>

namespace EngineTests {
    TEST(Scene, CreateNewScene) {
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
