cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

include(FetchContent)

FetchContent_Declare(
    glad_src
    GIT_REPOSITORY https://github.com/Dav1dde/glad.git
    GIT_TAG        glad2
    GIT_PROGRESS   TRUE
)

FetchContent_Populate(glad_src)

add_subdirectory("${glad_src_SOURCE_DIR}/cmake" glad_cmake)

glad_add_library(glad REPRODUCIBLE LOADER API gl:core=3.3)