cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

include(FetchContent)

fetchcontent_declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
)
if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()
fetchcontent_makeavailable(glm)
