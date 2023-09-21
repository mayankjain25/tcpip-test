cmake_minimum_required(VERSION 3.16)
project(socket_programming)

# Locate and configure Google Test
find_package(GTest REQUIRED)

# Add your source files and the test file
add_executable(socket_example server_1.cpp test1.cpp)

# Link Google Test and your project
target_link_libraries(socket_example GTest::GTest GTest::Main)

# Enable testing for CTest
enable_testing()

# Add a test target that runs your tests
add_test(NAME socket_example_test COMMAND socket_example)