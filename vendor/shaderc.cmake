cmake_minimum_required(VERSION 3.16)
include(FetchContent)

set(shaderc_root_dir "${CMAKE_SOURCE_DIR}/vendor/shaderc")

FetchContent_Declare(
  shaderc
  GIT_REPOSITORY https://github.com/google/shaderc.git
  GIT_TAG        main
  SOURCE_DIR ${shaderc_root_dir}
)
FetchContent_Populate(shaderc)

FetchContent_Declare(
  SPIRV-Tools
  GIT_REPOSITORY https://github.com/KhronosGroup/SPIRV-Tools.git
  GIT_TAG        main
  SOURCE_DIR ${shaderc_root_dir}/third_party/SPIRV-Tools
)
FetchContent_Populate(SPIRV-Tools)

FetchContent_Declare(
  SPIRV-Headers
  GIT_REPOSITORY https://github.com/KhronosGroup/SPIRV-Headers.git
  GIT_TAG        main
  SOURCE_DIR ${shaderc_root_dir}/third_party/SPIRV-Headers
)
FetchContent_Populate(SPIRV-Headers)

FetchContent_Declare(
  glslang
  GIT_REPOSITORY https://github.com/KhronosGroup/glslang.git
  GIT_TAG        main
  SOURCE_DIR ${shaderc_root_dir}/third_party/glslang
)
FetchContent_Populate(glslang)

add_definitions(-DSHADERC_SKIP_TESTS=true)
set(SHADERC_SKIP_TESTS true)
add_subdirectory(${shaderc_root_dir})
