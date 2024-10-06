cmake_minimum_required(VERSION 3.16)

set(ProjectName "runtime")
project(${ProjectName})

set(CMAKE_DEBUG_POSTFIX "")

link_directories(
    ${engine_BINARY_DIR}
)

file(GLOB_RECURSE RUNTIME_SRC
    "src/*.cpp"
    "src/*.h"
)

add_executable(${ProjectName} ${RUNTIME_SRC})

add_dependencies(${ProjectName} engine)

target_include_directories( ${ProjectName}
    PRIVATE ${enet_SOURCE_DIR}/include
    PRIVATE ${raylib_BINARY_DIR}/raylib/include
    PRIVATE ${raygui_SRC}
    PRIVATE ${engine_SOURCE_DIR}/src
)

target_link_libraries(${ProjectName}
    PUBLIC engine
)