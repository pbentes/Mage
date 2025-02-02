cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

include(FetchContent)

FetchContent_Declare(
    glad_src
    GIT_REPOSITORY https://github.com/Dav1dde/glad.git
    GIT_TAG        glad2
    GIT_PROGRESS   TRUE
)
FetchContent_Populate(glad_src)

if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()
add_subdirectory("${glad_src_SOURCE_DIR}/cmake" glad_cmake)

glad_add_library(glad REPRODUCIBLE LOADER API gl:core=3.3)
