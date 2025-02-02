cmake_minimum_required(VERSION 3.16)
include(FetchContent)

FetchContent_Declare(
  spirvcross
  GIT_REPOSITORY https://github.com/KhronosGroup/SPIRV-Cross.git
  GIT_TAG "main"
)
FetchContent_MakeAvailable(spirvcross)

set(spirvcross_SOURCE_DIR ${spirvcross_SOURCE_DIR} PARENT_SCOPE)
set(spirvcross_BINARY_DIR ${spirvcross_BINARY_DIR} PARENT_SCOPE)
