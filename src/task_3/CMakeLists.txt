cmake_minimum_required(VERSION 3.20)
project(task_3)

set(CMAKE_CXX_STANDARD 14)

option(BUILD_TESTS "Build tests" ON)

add_subdirectory(src)

add_subdirectory(tools/gtest)

if (BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif ()