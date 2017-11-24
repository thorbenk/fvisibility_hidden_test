project(testlib VERSION 0.1 LANGUAGES CXX)

add_library(testlib SHARED
    src/testlib_p.cpp
    src/testlib.cpp
    include/testlib.h
)

include(GenerateExportHeader)
generate_export_header(testlib)

target_include_directories(testlib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    $<INSTALL_INTERFACE:include>
    PRIVATE src
)

