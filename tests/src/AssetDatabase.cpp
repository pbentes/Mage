#include "AssetDatabase.h"
#include <Debug/Logger.h>

namespace EngineTests {
    TEST(AssetDatabase, CreateAsset) {

        ERROR("Testing: ", 1, " Testing2: ", 2.0f);

        EXPECT_STRNE("hello", "world");
        EXPECT_EQ(7 * 6, 42);
    }
}