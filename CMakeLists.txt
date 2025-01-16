cmake_minimum_required(VERSION 3.30)
set(PROJECT_NAME data_storage)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

include(FetchContent)
FetchContent_Declare(
        gtest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(gtest)

file(GLOB TEST_SOURCES "test/*.cc")
add_executable(runTests ${TEST_SOURCES})
target_include_directories(runTests PRIVATE src)
target_link_libraries(runTests PRIVATE gtest_main)

enable_testing()
add_test(NAME RunAllTests COMMAND runTests)
