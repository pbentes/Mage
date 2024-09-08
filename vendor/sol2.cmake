cmake_minimum_required(VERSION 3.16)
include(FetchContent)

FetchContent_Declare(
    sol2
    GIT_REPOSITORY https://github.com/ThePhD/sol2.git
    GIT_TAG "develop"
)
FetchContent_MakeAvailable(sol2)

#set(sol2_SOURCE_DIR ${sol2_SOURCE_DIR} PARENT_SCOPE)