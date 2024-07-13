cmake_minimum_required(VERSION 3.10)

project(Assignment4)

set(CMAKE_CXX_STANDARD 17)

# Grab googletest dependency
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        e2239ee6043f73722e7aa812a459f54a28552929 # release-1.11.0
)

FetchContent_MakeAvailable(googletest)

# Build regular `main` executable
add_executable(main main.cpp)

# Build `main_test` executable that runs the tests
# Define `TESTING` to prevent `main` function being generated
add_executable(main_test main_test.cpp)
target_compile_definitions(main_test PUBLIC TESTING)
target_link_libraries(main_test gtest_main)

# Let googletest enumerate the available tests for CTest
include(GoogleTest)
gtest_discover_tests(main_test)