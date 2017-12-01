add_executable(main
    src/main.cpp
)

target_link_libraries(main
    testlib
)

add_test(NAME main COMMAND $<TARGET_FILE:main>)
