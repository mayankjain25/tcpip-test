# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mayank/Desktop/tcpip-ge

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mayank/Desktop/tcpip-ge/build

# Include any dependencies generated for this target.
include CMakeFiles/socket_example.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/socket_example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/socket_example.dir/flags.make

CMakeFiles/socket_example.dir/server_1.cpp.o: CMakeFiles/socket_example.dir/flags.make
CMakeFiles/socket_example.dir/server_1.cpp.o: ../server_1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mayank/Desktop/tcpip-ge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/socket_example.dir/server_1.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/socket_example.dir/server_1.cpp.o -c /home/mayank/Desktop/tcpip-ge/server_1.cpp

CMakeFiles/socket_example.dir/server_1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/socket_example.dir/server_1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mayank/Desktop/tcpip-ge/server_1.cpp > CMakeFiles/socket_example.dir/server_1.cpp.i

CMakeFiles/socket_example.dir/server_1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/socket_example.dir/server_1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mayank/Desktop/tcpip-ge/server_1.cpp -o CMakeFiles/socket_example.dir/server_1.cpp.s

CMakeFiles/socket_example.dir/test1.cpp.o: CMakeFiles/socket_example.dir/flags.make
CMakeFiles/socket_example.dir/test1.cpp.o: ../test1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mayank/Desktop/tcpip-ge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/socket_example.dir/test1.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/socket_example.dir/test1.cpp.o -c /home/mayank/Desktop/tcpip-ge/test1.cpp

CMakeFiles/socket_example.dir/test1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/socket_example.dir/test1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mayank/Desktop/tcpip-ge/test1.cpp > CMakeFiles/socket_example.dir/test1.cpp.i

CMakeFiles/socket_example.dir/test1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/socket_example.dir/test1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mayank/Desktop/tcpip-ge/test1.cpp -o CMakeFiles/socket_example.dir/test1.cpp.s

# Object files for target socket_example
socket_example_OBJECTS = \
"CMakeFiles/socket_example.dir/server_1.cpp.o" \
"CMakeFiles/socket_example.dir/test1.cpp.o"

# External object files for target socket_example
socket_example_EXTERNAL_OBJECTS =

socket_example: CMakeFiles/socket_example.dir/server_1.cpp.o
socket_example: CMakeFiles/socket_example.dir/test1.cpp.o
socket_example: CMakeFiles/socket_example.dir/build.make
socket_example: /usr/lib/x86_64-linux-gnu/libgtest_main.a
socket_example: /usr/lib/x86_64-linux-gnu/libgtest.a
socket_example: CMakeFiles/socket_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mayank/Desktop/tcpip-ge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable socket_example"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/socket_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/socket_example.dir/build: socket_example

.PHONY : CMakeFiles/socket_example.dir/build

CMakeFiles/socket_example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/socket_example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/socket_example.dir/clean

CMakeFiles/socket_example.dir/depend:
	cd /home/mayank/Desktop/tcpip-ge/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mayank/Desktop/tcpip-ge /home/mayank/Desktop/tcpip-ge /home/mayank/Desktop/tcpip-ge/build /home/mayank/Desktop/tcpip-ge/build /home/mayank/Desktop/tcpip-ge/build/CMakeFiles/socket_example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/socket_example.dir/depend

