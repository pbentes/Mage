#include <gtest/gtest.h>

namespace Engine {
    TEST(Scene, BasicAssertions) {
        EXPECT_STRNE("hello", "world");
        EXPECT_EQ(7 * 6, 42);
    }
}
