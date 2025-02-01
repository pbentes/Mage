cmake_minimum_required(VERSION 3.16)
include(FetchContent)

FetchContent_Declare(
  spirvcross
  GIT_REPOSITORY https://github.com/KhronosGroup/SPIRV-Cross.git
  GIT_TAG "main"
)
FetchContent_MakeAvailable(spirvcross)
