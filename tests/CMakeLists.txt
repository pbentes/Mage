cmake_minimum_required(VERSION 3.16)
enable_testing()

set(ProjectName "tests")
project(${ProjectName})

link_directories(
    ${engine_BINARY_DIR}
    ${enet_BINARY_DIR}
    ${flecs_BINARY_DIR}
    ${lua_BINARY_DIR}
    ${efsw_BINARY_DIR}
    ${sqlite3_BINARY_DIR}
    ${glfw3_BINARY_DIR}/src
    ${imgui_BINARY_DIR}
)

file(GLOB_RECURSE TEST_SRC
    "src/*.cpp"
    "src/*.h"
)

add_executable(${ProjectName} ${TEST_SRC})
add_dependencies(${ProjectName} engine)

target_include_directories( ${ProjectName}
    PRIVATE ${enet_SOURCE_DIR}/include
    PRIVATE ${entt_SRC}/single_include
    PRIVATE ${engine_SOURCE_DIR}/src
    PRIVATE ${googletest_SOURCE_DIR}/googletest/include
)

target_link_libraries(${ProjectName}
    PUBLIC engine
    PUBLIC GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${ProjectName})
