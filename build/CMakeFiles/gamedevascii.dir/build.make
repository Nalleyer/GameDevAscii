# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_SOURCE_DIR = /home/nalleyer_inoru/projects/GameDevAscii

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nalleyer_inoru/projects/GameDevAscii/build

# Include any dependencies generated for this target.
include CMakeFiles/gamedevascii.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gamedevascii.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gamedevascii.dir/flags.make

CMakeFiles/gamedevascii.dir/main.o: CMakeFiles/gamedevascii.dir/flags.make
CMakeFiles/gamedevascii.dir/main.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nalleyer_inoru/projects/GameDevAscii/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/gamedevascii.dir/main.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gamedevascii.dir/main.o   -c /home/nalleyer_inoru/projects/GameDevAscii/main.c

CMakeFiles/gamedevascii.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gamedevascii.dir/main.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nalleyer_inoru/projects/GameDevAscii/main.c > CMakeFiles/gamedevascii.dir/main.i

CMakeFiles/gamedevascii.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gamedevascii.dir/main.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nalleyer_inoru/projects/GameDevAscii/main.c -o CMakeFiles/gamedevascii.dir/main.s

CMakeFiles/gamedevascii.dir/main.o.requires:

.PHONY : CMakeFiles/gamedevascii.dir/main.o.requires

CMakeFiles/gamedevascii.dir/main.o.provides: CMakeFiles/gamedevascii.dir/main.o.requires
	$(MAKE) -f CMakeFiles/gamedevascii.dir/build.make CMakeFiles/gamedevascii.dir/main.o.provides.build
.PHONY : CMakeFiles/gamedevascii.dir/main.o.provides

CMakeFiles/gamedevascii.dir/main.o.provides.build: CMakeFiles/gamedevascii.dir/main.o


# Object files for target gamedevascii
gamedevascii_OBJECTS = \
"CMakeFiles/gamedevascii.dir/main.o"

# External object files for target gamedevascii
gamedevascii_EXTERNAL_OBJECTS =

gamedevascii: CMakeFiles/gamedevascii.dir/main.o
gamedevascii: CMakeFiles/gamedevascii.dir/build.make
gamedevascii: CMakeFiles/gamedevascii.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nalleyer_inoru/projects/GameDevAscii/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable gamedevascii"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gamedevascii.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gamedevascii.dir/build: gamedevascii

.PHONY : CMakeFiles/gamedevascii.dir/build

CMakeFiles/gamedevascii.dir/requires: CMakeFiles/gamedevascii.dir/main.o.requires

.PHONY : CMakeFiles/gamedevascii.dir/requires

CMakeFiles/gamedevascii.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gamedevascii.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gamedevascii.dir/clean

CMakeFiles/gamedevascii.dir/depend:
	cd /home/nalleyer_inoru/projects/GameDevAscii/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nalleyer_inoru/projects/GameDevAscii /home/nalleyer_inoru/projects/GameDevAscii /home/nalleyer_inoru/projects/GameDevAscii/build /home/nalleyer_inoru/projects/GameDevAscii/build /home/nalleyer_inoru/projects/GameDevAscii/build/CMakeFiles/gamedevascii.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gamedevascii.dir/depend
