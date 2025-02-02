cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
include(FetchContent)

FetchContent_Declare(
  clay
  GIT_REPOSITORY https://github.com/nicbarker/clay.git
  GIT_TAG "main"
)
FetchContent_Populate(clay)
