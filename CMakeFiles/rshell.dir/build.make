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
CMAKE_COMMAND = /usr/bin/cmake3

# The command to remove a file.
RM = /usr/bin/cmake3 -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/csmajs/msain003/spring-2019-assignment-the-null-terminators

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/csmajs/msain003/spring-2019-assignment-the-null-terminators

# Include any dependencies generated for this target.
include CMakeFiles/rshell.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rshell.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rshell.dir/flags.make

CMakeFiles/rshell.dir/src/main.cpp.o: CMakeFiles/rshell.dir/flags.make
CMakeFiles/rshell.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/csmajs/msain003/spring-2019-assignment-the-null-terminators/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rshell.dir/src/main.cpp.o"
	/opt/rh/devtoolset-6/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rshell.dir/src/main.cpp.o -c /home/csmajs/msain003/spring-2019-assignment-the-null-terminators/src/main.cpp

CMakeFiles/rshell.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rshell.dir/src/main.cpp.i"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/csmajs/msain003/spring-2019-assignment-the-null-terminators/src/main.cpp > CMakeFiles/rshell.dir/src/main.cpp.i

CMakeFiles/rshell.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rshell.dir/src/main.cpp.s"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/csmajs/msain003/spring-2019-assignment-the-null-terminators/src/main.cpp -o CMakeFiles/rshell.dir/src/main.cpp.s

# Object files for target rshell
rshell_OBJECTS = \
"CMakeFiles/rshell.dir/src/main.cpp.o"

# External object files for target rshell
rshell_EXTERNAL_OBJECTS =

rshell: CMakeFiles/rshell.dir/src/main.cpp.o
rshell: CMakeFiles/rshell.dir/build.make
rshell: CMakeFiles/rshell.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/csmajs/msain003/spring-2019-assignment-the-null-terminators/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rshell"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rshell.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rshell.dir/build: rshell

.PHONY : CMakeFiles/rshell.dir/build

CMakeFiles/rshell.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rshell.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rshell.dir/clean

CMakeFiles/rshell.dir/depend:
	cd /home/csmajs/msain003/spring-2019-assignment-the-null-terminators && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/csmajs/msain003/spring-2019-assignment-the-null-terminators /home/csmajs/msain003/spring-2019-assignment-the-null-terminators /home/csmajs/msain003/spring-2019-assignment-the-null-terminators /home/csmajs/msain003/spring-2019-assignment-the-null-terminators /home/csmajs/msain003/spring-2019-assignment-the-null-terminators/CMakeFiles/rshell.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rshell.dir/depend

