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
include CMakeFiles/dawnshine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dawnshine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dawnshine.dir/flags.make

CMakeFiles/dawnshine.dir/src/net_addr.cc.o: CMakeFiles/dawnshine.dir/flags.make
CMakeFiles/dawnshine.dir/src/net_addr.cc.o: ../src/net_addr.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/emp/c++/dawnshine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dawnshine.dir/src/net_addr.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dawnshine.dir/src/net_addr.cc.o -c /Users/emp/c++/dawnshine/src/net_addr.cc

CMakeFiles/dawnshine.dir/src/net_addr.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dawnshine.dir/src/net_addr.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/emp/c++/dawnshine/src/net_addr.cc > CMakeFiles/dawnshine.dir/src/net_addr.cc.i

CMakeFiles/dawnshine.dir/src/net_addr.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dawnshine.dir/src/net_addr.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/emp/c++/dawnshine/src/net_addr.cc -o CMakeFiles/dawnshine.dir/src/net_addr.cc.s

CMakeFiles/dawnshine.dir/library.cpp.o: CMakeFiles/dawnshine.dir/flags.make
CMakeFiles/dawnshine.dir/library.cpp.o: ../library.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/emp/c++/dawnshine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/dawnshine.dir/library.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dawnshine.dir/library.cpp.o -c /Users/emp/c++/dawnshine/library.cpp

CMakeFiles/dawnshine.dir/library.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dawnshine.dir/library.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/emp/c++/dawnshine/library.cpp > CMakeFiles/dawnshine.dir/library.cpp.i

CMakeFiles/dawnshine.dir/library.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dawnshine.dir/library.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/emp/c++/dawnshine/library.cpp -o CMakeFiles/dawnshine.dir/library.cpp.s

CMakeFiles/dawnshine.dir/src/reactor.cc.o: CMakeFiles/dawnshine.dir/flags.make
CMakeFiles/dawnshine.dir/src/reactor.cc.o: ../src/reactor.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/emp/c++/dawnshine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/dawnshine.dir/src/reactor.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dawnshine.dir/src/reactor.cc.o -c /Users/emp/c++/dawnshine/src/reactor.cc

CMakeFiles/dawnshine.dir/src/reactor.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dawnshine.dir/src/reactor.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/emp/c++/dawnshine/src/reactor.cc > CMakeFiles/dawnshine.dir/src/reactor.cc.i

CMakeFiles/dawnshine.dir/src/reactor.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dawnshine.dir/src/reactor.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/emp/c++/dawnshine/src/reactor.cc -o CMakeFiles/dawnshine.dir/src/reactor.cc.s

CMakeFiles/dawnshine.dir/test/test_aio.cc.o: CMakeFiles/dawnshine.dir/flags.make
CMakeFiles/dawnshine.dir/test/test_aio.cc.o: ../test/test_aio.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/emp/c++/dawnshine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/dawnshine.dir/test/test_aio.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dawnshine.dir/test/test_aio.cc.o -c /Users/emp/c++/dawnshine/test/test_aio.cc

CMakeFiles/dawnshine.dir/test/test_aio.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dawnshine.dir/test/test_aio.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/emp/c++/dawnshine/test/test_aio.cc > CMakeFiles/dawnshine.dir/test/test_aio.cc.i

CMakeFiles/dawnshine.dir/test/test_aio.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dawnshine.dir/test/test_aio.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/emp/c++/dawnshine/test/test_aio.cc -o CMakeFiles/dawnshine.dir/test/test_aio.cc.s

# Object files for target dawnshine
dawnshine_OBJECTS = \
"CMakeFiles/dawnshine.dir/src/net_addr.cc.o" \
"CMakeFiles/dawnshine.dir/library.cpp.o" \
"CMakeFiles/dawnshine.dir/src/reactor.cc.o" \
"CMakeFiles/dawnshine.dir/test/test_aio.cc.o"

# External object files for target dawnshine
dawnshine_EXTERNAL_OBJECTS =

libdawnshine.a: CMakeFiles/dawnshine.dir/src/net_addr.cc.o
libdawnshine.a: CMakeFiles/dawnshine.dir/library.cpp.o
libdawnshine.a: CMakeFiles/dawnshine.dir/src/reactor.cc.o
libdawnshine.a: CMakeFiles/dawnshine.dir/test/test_aio.cc.o
libdawnshine.a: CMakeFiles/dawnshine.dir/build.make
libdawnshine.a: CMakeFiles/dawnshine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/emp/c++/dawnshine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libdawnshine.a"
	$(CMAKE_COMMAND) -P CMakeFiles/dawnshine.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dawnshine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dawnshine.dir/build: libdawnshine.a

.PHONY : CMakeFiles/dawnshine.dir/build

CMakeFiles/dawnshine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dawnshine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dawnshine.dir/clean

CMakeFiles/dawnshine.dir/depend:
	cd /Users/emp/c++/dawnshine/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/emp/c++/dawnshine /Users/emp/c++/dawnshine /Users/emp/c++/dawnshine/cmake-build-debug /Users/emp/c++/dawnshine/cmake-build-debug /Users/emp/c++/dawnshine/cmake-build-debug/CMakeFiles/dawnshine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dawnshine.dir/depend

