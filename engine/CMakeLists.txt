cmake_minimum_required(VERSION 3.16)

set(ProjectName "engine")
project(${ProjectName})

set(CMAKE_DEBUG_POSTFIX "")

link_directories(
    ${enet_BINARY_DIR}
    ${flecs_BINARY_DIR}
    ${raylib_BINARY_DIR}/raylib
    ${lua_BINARY_DIR}
)

file(GLOB_RECURSE ENGINE_SRC
    "src/*.cpp"
    "src/*.h"
)

add_executable(${ProjectName} ${ENGINE_SRC})

add_dependencies(${ProjectName} enet raylib lua Jolt)

target_include_directories( ${ProjectName}
    PRIVATE ${enet_SOURCE_DIR}/include
    PRIVATE ${raylib_BINARY_DIR}/raylib/include
    PRIVATE ${raygui_SRC}
    PRIVATE ${luajit_SOURCE_DIR}
    PRIVATE ${sol2_SOURCE_DIR}/include
    PRIVATE ${JoltPhysics_SOURCE_DIR}/..
    PRIVATE ${engine_SOURCE_DIR}/src
    PRIVATE ${toml11_SOURCE_DIR}
)

target_link_libraries(${ProjectName}
    PRIVATE enet
    PRIVATE raylib
    PRIVATE lua
    PRIVATE Jolt
)