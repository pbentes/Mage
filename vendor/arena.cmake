cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
include(FetchContent)

FetchContent_Declare(
  arena
  GIT_REPOSITORY https://github.com/pbentes/Arena.git
  GIT_TAG "main"
)
FetchContent_Populate(arena)

set(arena_SOURCE_DIR ${arena_SOURCE_DIR} PARENT_SCOPE)
