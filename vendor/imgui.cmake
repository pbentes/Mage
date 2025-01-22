cmake_minimum_required(VERSION 3.16)
include(FetchContent)

FetchContent_Declare(
  imgui
  GIT_REPOSITORY https://github.com/ocornut/imgui.git
  GIT_TAG        origin/docking
  SOURCE_DIR ${CMAKE_SOURCE_DIR}/vendor/imgui
)
FetchContent_Populate(imgui)

file(WRITE ${CMAKE_SOURCE_DIR}/vendor/imgui/CMakeLists.txt [[
cmake_minimum_required(VERSION 3.11)
project(imgui)

link_directories(
    "${CMAKE_SOURCE_DIR}/build/_deps/glfw3-build/src/Debug"
)

file(GLOB_RECURSE IMGUI_SRC
    "imconfig.h"
    "imgui_demo.cpp"
    "imgui_draw.cpp"
    "imgui_internal.h"
    "imgui_tables.cpp"
    "imgui_widgets.cpp"
    "imgui.cpp"
    "imgui.h"
    "imstb_rectpack.h"
    "imstb_textedit.h"
    "imstb_truetype.h"

    "backends/imgui_impl_glfw.cpp"
    "backends/imgui_impl_glfw.h"

    "backends/imgui_impl_opengl3_loader.h"
    "backends/imgui_impl_opengl3.cpp"
    "backends/imgui_impl_opengl3.h"
)

add_library(imgui STATIC ${IMGUI_SRC})

add_dependencies(imgui glfw)

target_include_directories(imgui 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${glfw3_SOURCE_DIR}/include
)

target_link_libraries(imgui
    PUBLIC glfw3dll
)
]])

add_subdirectory(${CMAKE_SOURCE_DIR}/vendor/imgui)
