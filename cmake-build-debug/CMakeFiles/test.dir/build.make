# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_SOURCE_DIR = /Users/deniztohumcu/Desktop/DCS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/deniztohumcu/Desktop/DCS/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/main.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/deniztohumcu/Desktop/DCS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/main.cpp.o -c /Users/deniztohumcu/Desktop/DCS/main.cpp

CMakeFiles/test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/deniztohumcu/Desktop/DCS/main.cpp > CMakeFiles/test.dir/main.cpp.i

CMakeFiles/test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/deniztohumcu/Desktop/DCS/main.cpp -o CMakeFiles/test.dir/main.cpp.s

CMakeFiles/test.dir/libraries/logicgates/logicgates.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/libraries/logicgates/logicgates.cpp.o: ../libraries/logicgates/logicgates.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/deniztohumcu/Desktop/DCS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test.dir/libraries/logicgates/logicgates.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/libraries/logicgates/logicgates.cpp.o -c /Users/deniztohumcu/Desktop/DCS/libraries/logicgates/logicgates.cpp

CMakeFiles/test.dir/libraries/logicgates/logicgates.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/libraries/logicgates/logicgates.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/deniztohumcu/Desktop/DCS/libraries/logicgates/logicgates.cpp > CMakeFiles/test.dir/libraries/logicgates/logicgates.cpp.i

CMakeFiles/test.dir/libraries/logicgates/logicgates.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/libraries/logicgates/logicgates.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/deniztohumcu/Desktop/DCS/libraries/logicgates/logicgates.cpp -o CMakeFiles/test.dir/libraries/logicgates/logicgates.cpp.s

CMakeFiles/test.dir/libraries/logicgates/logicgates_test.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/libraries/logicgates/logicgates_test.cpp.o: ../libraries/logicgates/logicgates_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/deniztohumcu/Desktop/DCS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test.dir/libraries/logicgates/logicgates_test.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/libraries/logicgates/logicgates_test.cpp.o -c /Users/deniztohumcu/Desktop/DCS/libraries/logicgates/logicgates_test.cpp

CMakeFiles/test.dir/libraries/logicgates/logicgates_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/libraries/logicgates/logicgates_test.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/deniztohumcu/Desktop/DCS/libraries/logicgates/logicgates_test.cpp > CMakeFiles/test.dir/libraries/logicgates/logicgates_test.cpp.i

CMakeFiles/test.dir/libraries/logicgates/logicgates_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/libraries/logicgates/logicgates_test.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/deniztohumcu/Desktop/DCS/libraries/logicgates/logicgates_test.cpp -o CMakeFiles/test.dir/libraries/logicgates/logicgates_test.cpp.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/main.cpp.o" \
"CMakeFiles/test.dir/libraries/logicgates/logicgates.cpp.o" \
"CMakeFiles/test.dir/libraries/logicgates/logicgates_test.cpp.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

test: CMakeFiles/test.dir/main.cpp.o
test: CMakeFiles/test.dir/libraries/logicgates/logicgates.cpp.o
test: CMakeFiles/test.dir/libraries/logicgates/logicgates_test.cpp.o
test: CMakeFiles/test.dir/build.make
test: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/deniztohumcu/Desktop/DCS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: test

.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	cd /Users/deniztohumcu/Desktop/DCS/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/deniztohumcu/Desktop/DCS /Users/deniztohumcu/Desktop/DCS /Users/deniztohumcu/Desktop/DCS/cmake-build-debug /Users/deniztohumcu/Desktop/DCS/cmake-build-debug /Users/deniztohumcu/Desktop/DCS/cmake-build-debug/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test.dir/depend

