cmake_minimum_required(VERSION 3.16)
include(FetchContent)

include(raylib.cmake)
include(raygui.cmake)
include(enet.cmake)
include(entt.cmake)
include(lua.cmake)
include(sol2.cmake)
#include(jolt.cmake)
include(efsw.cmake)

add_subdirectory(sqlite3)

include(google_test.cmake)