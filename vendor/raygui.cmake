cmake_minimum_required(VERSION 3.16)
include(FetchContent)

FetchContent_Declare(
    raygui
    GIT_REPOSITORY "https://github.com/raysan5/raygui.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(raygui)

set(raygui_SRC ${raygui_SOURCE_DIR}/src PARENT_SCOPE)