# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/cox/Documents/GitHub/FKCpp/Py

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/cox/Documents/GitHub/FKCpp/Py/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Py.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Py.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Py.dir/flags.make

CMakeFiles/Py.dir/main.cpp.o: CMakeFiles/Py.dir/flags.make
CMakeFiles/Py.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cox/Documents/GitHub/FKCpp/Py/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Py.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Py.dir/main.cpp.o -c /Users/cox/Documents/GitHub/FKCpp/Py/main.cpp

CMakeFiles/Py.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Py.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cox/Documents/GitHub/FKCpp/Py/main.cpp > CMakeFiles/Py.dir/main.cpp.i

CMakeFiles/Py.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Py.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cox/Documents/GitHub/FKCpp/Py/main.cpp -o CMakeFiles/Py.dir/main.cpp.s

# Object files for target Py
Py_OBJECTS = \
"CMakeFiles/Py.dir/main.cpp.o"

# External object files for target Py
Py_EXTERNAL_OBJECTS =

Py: CMakeFiles/Py.dir/main.cpp.o
Py: CMakeFiles/Py.dir/build.make
Py: CMakeFiles/Py.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/cox/Documents/GitHub/FKCpp/Py/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Py"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Py.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Py.dir/build: Py

.PHONY : CMakeFiles/Py.dir/build

CMakeFiles/Py.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Py.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Py.dir/clean

CMakeFiles/Py.dir/depend:
	cd /Users/cox/Documents/GitHub/FKCpp/Py/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/cox/Documents/GitHub/FKCpp/Py /Users/cox/Documents/GitHub/FKCpp/Py /Users/cox/Documents/GitHub/FKCpp/Py/cmake-build-debug /Users/cox/Documents/GitHub/FKCpp/Py/cmake-build-debug /Users/cox/Documents/GitHub/FKCpp/Py/cmake-build-debug/CMakeFiles/Py.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Py.dir/depend
