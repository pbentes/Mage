cmake_minimum_required(VERSION 3.16)
include(FetchContent)

FetchContent_Declare(
  flecs
  GIT_REPOSITORY https://github.com/SanderMertens/flecs.git
)
FetchContent_MakeAvailable(flecs)