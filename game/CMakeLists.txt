cmake_minimum_required(VERSION 3.16)

set(ProjectName "game")
project(${ProjectName})

set(CMAKE_DEBUG_POSTFIX "")

link_directories(
    ${engine_BINARY_DIR}
)

file(GLOB_RECURSE GAME_SRC
    "src/*.cpp"
    "src/*.h"
)

add_executable(${ProjectName} ${GAME_SRC})

add_dependencies(${ProjectName} engine)

target_include_directories( ${ProjectName}
    PUBLIC ${enet_SOURCE_DIR}/include
    PUBLIC ${flecs_SOURCE_DIR}/include
    PUBLIC ${raylib_BINARY_DIR}/raylib/include
    PUBLIC ${engine_SOURCE_DIR}/src
)

target_link_libraries(${ProjectName}
    PUBLIC engine
)