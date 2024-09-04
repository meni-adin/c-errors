set(TARGET_NAME errors_test)

include(GoogleTest)

set(TARGET_SOURCES
    "errors_test.cpp"
)

add_executable(${TARGET_NAME}
    ${TARGET_SOURCES}
)

target_link_libraries(${TARGET_NAME}
    GTest::gmock
    errors
)

gtest_discover_tests(${TARGET_NAME})
