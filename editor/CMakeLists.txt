cmake_minimum_required(VERSION 3.16)

set(ProjectName "editor")
project(${ProjectName})

set(CMAKE_DEBUG_POSTFIX "")

link_directories(
    ${engine_BINARY_DIR}
)

file(GLOB_RECURSE EDITOR_SRC
    "src/*.cpp"
    "src/*.h"
)

add_executable(${ProjectName} ${EDITOR_SRC})

add_dependencies(${ProjectName} engine)

target_include_directories( ${ProjectName}
    PRIVATE ${enet_SOURCE_DIR}/include
    PRIVATE ${entt_SRC}/single_include
    PRIVATE ${engine_SOURCE_DIR}/src
)

target_link_libraries(${ProjectName}
    PUBLIC engine
)