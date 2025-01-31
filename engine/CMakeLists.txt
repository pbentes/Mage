cmake_minimum_required(VERSION 3.16)

set(ProjectName "engine")
project(${ProjectName})

set(CMAKE_DEBUG_POSTFIX "")

link_directories(
    ${enet_BINARY_DIR}
    ${flecs_BINARY_DIR}
    ${lua_BINARY_DIR}
    ${efsw_BINARY_DIR}
    ${sqlite3_BINARY_DIR}
    ${glfw3_BINARY_DIR}/src
    ${glm_BINARY_DIR}/glm
    ${glad_BINARY_DIR}
    ${imgui_BINARY_DIR}
)

file(GLOB_RECURSE ENGINE_SRC
    "src/*.cpp"
    "src/*.h"
)

add_library(${ProjectName} STATIC ${ENGINE_SRC})

target_include_directories( ${ProjectName}
    PUBLIC ${arena_SOURCE_DIR}
    PUBLIC ${enet_SOURCE_DIR}/include
    PUBLIC ${entt_SRC}/single_include
    PUBLIC ${lua_SOURCE_DIR}
    PUBLIC ${sol2_SOURCE_DIR}/include
    PUBLIC ${efsw_SOURCE_DIR}/include
    PUBLIC ${sqlite3_SOURCE_DIR}
    PUBLIC ${JoltPhysics_SOURCE_DIR}/..
    PUBLIC ${imgui_SOURCE_DIR}
    PUBLIC ${imgui_SOURCE_DIR}/backends
    PUBLIC ${glfw_SOURCE_DIR}/include
    PUBLIC ${glad_BINARY_DIR}/gladsources/glad/include
    PUBLIC ${glm_SOURCE_DIR}
    PUBLIC ${engine_SOURCE_DIR}/src
    PUBLIC ${toml11_SOURCE_DIR}
)

target_link_libraries(${ProjectName}
    PUBLIC enet
    PUBLIC lua
    PUBLIC efsw
    PUBLIC sqlite3
    PUBLIC glad
    PUBLIC glm
    PUBLIC glfw3
    PUBLIC imgui
    PUBLIC Jolt
)
