cmake_minimum_required(VERSION 3.16)

set(ProjectName "editor")
project(${ProjectName})

set(CMAKE_DEBUG_POSTFIX "")

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

file(GLOB_RECURSE EDITOR_SRC
    "src/*.cpp"
    "src/*.h"
)

add_executable(${ProjectName} ${EDITOR_SRC})

add_dependencies(${ProjectName} engine)

target_include_directories( ${ProjectName}
    PUBLIC ${engine_SOURCE_DIR}/src
)

target_link_libraries(${ProjectName}
    PUBLIC engine
)
