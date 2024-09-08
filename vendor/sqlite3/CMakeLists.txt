PROJECT(sqlite3)
cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

include_directories(${CMAKE_SOURCE_DIR}/src)
add_library(sqlite3 STATIC sqlite3.c sqlite3.h sqlite3ext.h)

add_definitions(-DSQLITE_ENABLE_RTREE)
add_definitions(-DSQLITE_ENABLE_FTS4)
add_definitions(-DSQLITE_ENABLE_FTS5)
add_definitions(-DSQLITE_ENABLE_JSON1)
add_definitions(-DSQLITE_ENABLE_RBU)
add_definitions(-DSQLITE_ENABLE_STAT4)