cmake_minimum_required(VERSION 3.16)

set(ProjectName "engine")
project(${ProjectName})

set(CMAKE_DEBUG_POSTFIX "")

link_directories(
    ${enet_BINARY_DIR}
    ${flecs_BINARY_DIR}
    ${raylib_BINARY_DIR}/raylib
)

file(GLOB_RECURSE ENGINE_SRC
    "src/*.cpp"
    "src/*.h"
)

add_library(${ProjectName} STATIC ${ENGINE_SRC})

add_dependencies(${ProjectName} enet flecs raylib)

target_include_directories( ${ProjectName}
    PUBLIC ${enet_SOURCE_DIR}/include
    PUBLIC ${flecs_SOURCE_DIR}/include
    PUBLIC ${raylib_BINARY_DIR}/raylib/include
    PUBLIC ${raygui_SRC}
)

target_link_libraries(${ProjectName}
    PUBLIC flecs_static
    PUBLIC enet
    PUBLIC raylib
)