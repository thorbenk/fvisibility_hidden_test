project(fvisibility_hidden_test LANGUAGES CXX)
cmake_minimum_required(VERSION 3.7 FATAL_ERROR)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
set(CMAKE_CXX_STANDARD 14)
if (("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang") OR ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU"))
    add_definitions(-Werror)
endif ()

enable_testing()

add_subdirectory(testlib)
add_subdirectory(app)

