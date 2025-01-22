cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

include(FetchContent)

fetchcontent_declare(
  glfw3
  GIT_REPOSITORY https://github.com/glfw/glfw.git
)
fetchcontent_makeavailable(glfw3)

set(glfw3_SOURCE_DIR ${glfw3_SOURCE_DIR} PARENT_SCOPE)
set(glfw3_BINARY_DIR ${glfw3_BINARY_DIR} PARENT_SCOPE)