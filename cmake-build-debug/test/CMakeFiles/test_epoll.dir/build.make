# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/emp/c++/dawnshine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/emp/c++/dawnshine/cmake-build-debug

# Include any dependencies generated for this target.
include test/CMakeFiles/test_epoll.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test_epoll.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test_epoll.dir/flags.make

test/CMakeFiles/test_epoll.dir/test_epoll.cc.o: test/CMakeFiles/test_epoll.dir/flags.make
test/CMakeFiles/test_epoll.dir/test_epoll.cc.o: ../test/test_epoll.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/emp/c++/dawnshine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/test_epoll.dir/test_epoll.cc.o"
	cd /Users/emp/c++/dawnshine/cmake-build-debug/test && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_epoll.dir/test_epoll.cc.o -c /Users/emp/c++/dawnshine/test/test_epoll.cc

test/CMakeFiles/test_epoll.dir/test_epoll.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_epoll.dir/test_epoll.cc.i"
	cd /Users/emp/c++/dawnshine/cmake-build-debug/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/emp/c++/dawnshine/test/test_epoll.cc > CMakeFiles/test_epoll.dir/test_epoll.cc.i

test/CMakeFiles/test_epoll.dir/test_epoll.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_epoll.dir/test_epoll.cc.s"
	cd /Users/emp/c++/dawnshine/cmake-build-debug/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/emp/c++/dawnshine/test/test_epoll.cc -o CMakeFiles/test_epoll.dir/test_epoll.cc.s

# Object files for target test_epoll
test_epoll_OBJECTS = \
"CMakeFiles/test_epoll.dir/test_epoll.cc.o"

# External object files for target test_epoll
test_epoll_EXTERNAL_OBJECTS =

test/test_epoll: test/CMakeFiles/test_epoll.dir/test_epoll.cc.o
test/test_epoll: test/CMakeFiles/test_epoll.dir/build.make
test/test_epoll: test/CMakeFiles/test_epoll.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/emp/c++/dawnshine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_epoll"
	cd /Users/emp/c++/dawnshine/cmake-build-debug/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_epoll.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test_epoll.dir/build: test/test_epoll

.PHONY : test/CMakeFiles/test_epoll.dir/build

test/CMakeFiles/test_epoll.dir/clean:
	cd /Users/emp/c++/dawnshine/cmake-build-debug/test && $(CMAKE_COMMAND) -P CMakeFiles/test_epoll.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/test_epoll.dir/clean

test/CMakeFiles/test_epoll.dir/depend:
	cd /Users/emp/c++/dawnshine/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/emp/c++/dawnshine /Users/emp/c++/dawnshine/test /Users/emp/c++/dawnshine/cmake-build-debug /Users/emp/c++/dawnshine/cmake-build-debug/test /Users/emp/c++/dawnshine/cmake-build-debug/test/CMakeFiles/test_epoll.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/test_epoll.dir/depend
