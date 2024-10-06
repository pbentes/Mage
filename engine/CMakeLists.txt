cmake_minimum_required(VERSION 3.16)

set(ProjectName "engine")
project(${ProjectName})

set(CMAKE_DEBUG_POSTFIX "")

link_directories(
    ${enet_BINARY_DIR}
    ${flecs_BINARY_DIR}
    ${raylib_BINARY_DIR}/raylib
    ${lua_BINARY_DIR}
    ${efsw_BINARY_DIR}
    ${sqlite3_BINARY_DIR}
)

file(GLOB_RECURSE ENGINE_SRC
    "src/*.cpp"
    "src/*.h"
)

add_library(${ProjectName} STATIC ${ENGINE_SRC})

add_dependencies(${ProjectName} enet raylib lua Jolt)

target_include_directories( ${ProjectName}
    PUBLIC ${enet_SOURCE_DIR}/include
    #PUBLIC ${entt_SRC}/single_include
    PUBLIC ${raylib_BINARY_DIR}/raylib/include
    PUBLIC ${raygui_SRC}
    PUBLIC ${lua_SOURCE_DIR}
    PUBLIC ${sol2_SOURCE_DIR}/include
    PUBLIC ${efsw_SOURCE_DIR}/include
    PUBLIC ${sqlite3_SOURCE_DIR}
    PUBLIC ${JoltPhysics_SOURCE_DIR}/..
    PUBLIC ${engine_SOURCE_DIR}/src
)

target_link_libraries(${ProjectName}
    PUBLIC enet
    PUBLIC raylib
    PUBLIC lua
    PUBLIC efsw
    PUBLIC sqlite3
    PUBLIC Jolt
)