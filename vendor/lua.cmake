cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
include(FetchContent)

FetchContent_Declare(
  lua
  GIT_REPOSITORY https://github.com/lua/lua.git
  GIT_TAG        origin/v5.4
  SOURCE_DIR ${CMAKE_SOURCE_DIR}/vendor/lua
)

FetchContent_Populate(lua)

# Create a custom CMakeLists.txt for lua
file(WRITE ${lua_SOURCE_DIR}/CMakeLists.txt [[
cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

set(LUA_SRC
    "lapi.c"
    "lcode.c"
    "lctype.c"
    "ldebug.c"
    "ldo.c"
    "ldump.c"
    "lfunc.c"
    "lgc.c"
    "llex.c"
    "lmem.c"
    "lobject.c"
    "lopcodes.c"
    "lparser.c"
    "lstate.c"
    "lstring.c"
    "ltable.c"
    "ltm.c"
    "lundump.c"
    "lvm.c"
    "lzio.c"
    "lauxlib.c"
    "lbaselib.c"
    "lcorolib.c"
    "ldblib.c"
    "liolib.c"
    "lmathlib.c"
    "loadlib.c"
    "loslib.c"
    "lstrlib.c"
    "ltablib.c"
    "lutf8lib.c"
    "linit.c"
    "lapi.c"
    "lcode.c"
    "lctype.c"
    "ldebug.c"
    "ldo.c"
    "ldump.c"
    "lfunc.c"
    "lgc.c"
    "llex.c"
    "lmem.c"
    "lobject.c"
    "lopcodes.c"
    "lparser.c"
    "lstate.c"
    "lstring.c"
    "ltable.c"
    "ltm.c"
    "lundump.c"
    "lvm.c"
    "lzio.c"
    "lauxlib.c"
    "lbaselib.c"
    "lcorolib.c"
    "ldblib.c"
    "liolib.c"
    "lmathlib.c"
    "loadlib.c"
    "loslib.c"
    "lstrlib.c"
    "ltablib.c"
    "lutf8lib.c"
    "linit.c"
)

add_library(lua STATIC ${LUA_SRC})

target_include_directories(lua
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)
]])

set(CMAKE_DEBUG_POSTFIX "")
add_subdirectory(${lua_SOURCE_DIR})

set(lua_SOURCE_DIR ${lua_SOURCE_DIR} PARENT_SCOPE)