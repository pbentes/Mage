cmake_minimum_required(VERSION 3.16)
include(FetchContent)

FetchContent_Declare(
  chai
  GIT_REPOSITORY https://github.com/ChaiScript/ChaiScript.git
)
FetchContent_MakeAvailable(chai)