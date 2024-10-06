cmake_minimum_required(VERSION 3.16)
enable_testing()

set(ProjectName "tests")
project(${ProjectName})

link_directories(
    ${engine_BINARY_DIR}
)

file(GLOB_RECURSE TEST_SRC
    "src/*.cpp"
    "src/*.h"
)

add_executable(${ProjectName} ${TEST_SRC})
add_dependencies(${ProjectName} engine)

target_include_directories( ${ProjectName}
    PRIVATE ${enet_SOURCE_DIR}/include
    #PRIVATE ${entt_SRC}/single_include
    PRIVATE ${raylib_BINARY_DIR}/raylib/include
    PRIVATE ${raygui_SRC}
    PRIVATE ${engine_SOURCE_DIR}/src
    PRIVATE ${googletest_SOURCE_DIR}/googletest/include
)

target_link_libraries(${ProjectName}
    PUBLIC engine
    PUBLIC GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${ProjectName})