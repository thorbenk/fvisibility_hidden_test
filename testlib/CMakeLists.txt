project(testlib VERSION 0.1 LANGUAGES CXX)

add_library(testlib SHARED
    src/testlib_p.cpp
    src/testlib.cpp
    include/testlib.h
)
set_target_properties(testlib PROPERTIES
    CMAKE_CXX_VISIBILITY_PRESET hidden
    CMAKE_VISIBILITY_INLINES_HIDDEN 1
)

include(GenerateExportHeader)
generate_export_header(testlib)

target_include_directories(testlib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    $<INSTALL_INTERFACE:include>
    PRIVATE src
)

