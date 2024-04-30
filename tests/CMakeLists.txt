include(CTest)
include(FetchContent)
include(GoogleTest)

FetchContent_Declare(gtest
        QUIET
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.tar.gz
        )

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(gtest)

set(TEST_TARGET ${CMAKE_PROJECT_NAME}_unit_tests)

set(
    SOURCES
    bowlingTest.cpp
)

add_executable(${TEST_TARGET} run_unit_tests.cpp ${SOURCES})

target_include_directories(${TEST_TARGET} PRIVATE
        ${PROJECT_SOURCE_DIR}/includes
        ${PROJECT_SOURCE_DIR}/sources
        )

target_link_libraries(
        ${TEST_TARGET}
        PRIVATE
        -static-libgcc -static-libstdc++
        ${PROJECT_NAME}
        gtest_main
        rt
        gcov
)

gtest_discover_tests(
    ${TEST_TARGET}
    XML_OUTPUT_DIR unit-tests-reports
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
