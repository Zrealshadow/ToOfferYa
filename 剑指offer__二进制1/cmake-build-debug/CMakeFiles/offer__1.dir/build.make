# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_SOURCE_DIR = /Users/e1ixir/CLionProjects/剑指offer__二进制1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/e1ixir/CLionProjects/剑指offer__二进制1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/offer__1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/offer__1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/offer__1.dir/flags.make

CMakeFiles/offer__1.dir/main.cpp.o: CMakeFiles/offer__1.dir/flags.make
CMakeFiles/offer__1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/e1ixir/CLionProjects/剑指offer__二进制1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/offer__1.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/offer__1.dir/main.cpp.o -c /Users/e1ixir/CLionProjects/剑指offer__二进制1/main.cpp

CMakeFiles/offer__1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/offer__1.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/e1ixir/CLionProjects/剑指offer__二进制1/main.cpp > CMakeFiles/offer__1.dir/main.cpp.i

CMakeFiles/offer__1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/offer__1.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/e1ixir/CLionProjects/剑指offer__二进制1/main.cpp -o CMakeFiles/offer__1.dir/main.cpp.s

# Object files for target offer__1
offer__1_OBJECTS = \
"CMakeFiles/offer__1.dir/main.cpp.o"

# External object files for target offer__1
offer__1_EXTERNAL_OBJECTS =

offer__1: CMakeFiles/offer__1.dir/main.cpp.o
offer__1: CMakeFiles/offer__1.dir/build.make
offer__1: CMakeFiles/offer__1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/e1ixir/CLionProjects/剑指offer__二进制1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable offer__1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/offer__1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/offer__1.dir/build: offer__1

.PHONY : CMakeFiles/offer__1.dir/build

CMakeFiles/offer__1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/offer__1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/offer__1.dir/clean

CMakeFiles/offer__1.dir/depend:
	cd /Users/e1ixir/CLionProjects/剑指offer__二进制1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/e1ixir/CLionProjects/剑指offer__二进制1 /Users/e1ixir/CLionProjects/剑指offer__二进制1 /Users/e1ixir/CLionProjects/剑指offer__二进制1/cmake-build-debug /Users/e1ixir/CLionProjects/剑指offer__二进制1/cmake-build-debug /Users/e1ixir/CLionProjects/剑指offer__二进制1/cmake-build-debug/CMakeFiles/offer__1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/offer__1.dir/depend

