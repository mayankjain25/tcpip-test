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
CMAKE_SOURCE_DIR = /home/mayank/Desktop/tcpip-ge/gt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mayank/Desktop/tcpip-ge/gt/build

# Include any dependencies generated for this target.
include CMakeFiles/client_executable.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/client_executable.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client_executable.dir/flags.make

CMakeFiles/client_executable.dir/client_main.cpp.o: CMakeFiles/client_executable.dir/flags.make
CMakeFiles/client_executable.dir/client_main.cpp.o: ../client_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mayank/Desktop/tcpip-ge/gt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/client_executable.dir/client_main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client_executable.dir/client_main.cpp.o -c /home/mayank/Desktop/tcpip-ge/gt/client_main.cpp

CMakeFiles/client_executable.dir/client_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client_executable.dir/client_main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mayank/Desktop/tcpip-ge/gt/client_main.cpp > CMakeFiles/client_executable.dir/client_main.cpp.i

CMakeFiles/client_executable.dir/client_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client_executable.dir/client_main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mayank/Desktop/tcpip-ge/gt/client_main.cpp -o CMakeFiles/client_executable.dir/client_main.cpp.s

# Object files for target client_executable
client_executable_OBJECTS = \
"CMakeFiles/client_executable.dir/client_main.cpp.o"

# External object files for target client_executable
client_executable_EXTERNAL_OBJECTS =

client_executable: CMakeFiles/client_executable.dir/client_main.cpp.o
client_executable: CMakeFiles/client_executable.dir/build.make
client_executable: libclient_server_lib.a
client_executable: /usr/lib/x86_64-linux-gnu/libgtest_main.a
client_executable: /usr/lib/x86_64-linux-gnu/libgtest.a
client_executable: CMakeFiles/client_executable.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mayank/Desktop/tcpip-ge/gt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable client_executable"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client_executable.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client_executable.dir/build: client_executable

.PHONY : CMakeFiles/client_executable.dir/build

CMakeFiles/client_executable.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client_executable.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client_executable.dir/clean

CMakeFiles/client_executable.dir/depend:
	cd /home/mayank/Desktop/tcpip-ge/gt/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mayank/Desktop/tcpip-ge/gt /home/mayank/Desktop/tcpip-ge/gt /home/mayank/Desktop/tcpip-ge/gt/build /home/mayank/Desktop/tcpip-ge/gt/build /home/mayank/Desktop/tcpip-ge/gt/build/CMakeFiles/client_executable.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/client_executable.dir/depend

