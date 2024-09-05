cmake_minimum_required(VERSION 3.16)
include(FetchContent)

FetchContent_Declare(
    entt
    GIT_REPOSITORY https://github.com/skypjack/entt.git
)
FetchContent_MakeAvailable(entt)

set(entt_SRC ${entt_SOURCE_DIR} PARENT_SCOPE)