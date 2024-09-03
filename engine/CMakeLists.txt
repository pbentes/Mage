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

if(MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

add_library(${ProjectName} STATIC ${ENGINE_SRC})

add_dependencies(${ProjectName} enet raylib Jolt)

target_include_directories( ${ProjectName}
    PUBLIC ${enet_SOURCE_DIR}/include
    PUBLIC ${entt_SOURCE_DIR}/single_include/entt
    PUBLIC ${raylib_BINARY_DIR}/raylib/include
    PUBLIC ${raygui_SRC}
    PUBLIC ${JoltPhysics_SOURCE_DIR}/..
)

target_link_libraries(${ProjectName}
    PUBLIC enet
    PUBLIC raylib
    PUBLIC Jolt
)