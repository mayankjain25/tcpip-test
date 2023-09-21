cmake_minimum_required(VERSION 3.12)
project(ClientServerTests)

# Locate and configure Google Test
find_package(GTest REQUIRED)

# Add your source files (client.cpp and server.cpp) to a library
add_library(client_server_lib STATIC client.cpp server.cpp)

# Link Google Test to your project library
target_link_libraries(client_server_lib GTest::GTest GTest::Main)

# Add an executable for the client and link to the library
add_executable(client_executable client_main.cpp)
target_link_libraries(client_executable client_server_lib)

# Add an executable for the server and link to the library
add_executable(server_executable server_main.cpp)
target_link_libraries(server_executable client_server_lib)

# Add your test files (test.cpp)
add_executable(client_server_tests test.cpp)

# Link your project library and Google Test to the tests
target_link_libraries(client_server_tests client_server_lib GTest::GTest GTest::Main)

# Enable testing for CTest
enable_testing()

# Add a test target that runs your tests
add_test(NAME client_server_tests COMMAND client_server_tests)
