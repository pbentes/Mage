cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project("mage")

set(CMAKE_FOLDER Dependencies)
add_subdirectory("vendor")

set(CMAKE_FOLDER /)
add_subdirectory("engine")
add_subdirectory("runtime")
add_subdirectory("tests")

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT "runtime")