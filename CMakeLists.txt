cmake_minimum_required(VERSION 3.20)
project(leetcode CXX)
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip)
FetchContent_MakeAvailable(googletest)

include_directories(${PROJECT_SOURCE_DIR}/include)
enable_testing()
file(GLOB SOLUTIONS problems/*.cpp)
add_executable(tests ${SOLUTIONS})
target_link_libraries(tests GTest::gmock_main)
include(GoogleTest)
gtest_discover_tests(tests)
