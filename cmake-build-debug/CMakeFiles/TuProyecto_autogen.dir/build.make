# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/296/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /snap/clion/296/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/gabonm7/CLionProjects/proyecto 2/Tank_Attack"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/gabonm7/CLionProjects/proyecto 2/Tank_Attack/cmake-build-debug"

# Utility rule file for TuProyecto_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/TuProyecto_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TuProyecto_autogen.dir/progress.make

CMakeFiles/TuProyecto_autogen: TuProyecto_autogen/timestamp

TuProyecto_autogen/timestamp: /usr/lib/qt5/bin/moc
TuProyecto_autogen/timestamp: CMakeFiles/TuProyecto_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir="/home/gabonm7/CLionProjects/proyecto 2/Tank_Attack/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target TuProyecto"
	/snap/clion/296/bin/cmake/linux/x64/bin/cmake -E cmake_autogen "/home/gabonm7/CLionProjects/proyecto 2/Tank_Attack/cmake-build-debug/CMakeFiles/TuProyecto_autogen.dir/AutogenInfo.json" Debug
	/snap/clion/296/bin/cmake/linux/x64/bin/cmake -E touch "/home/gabonm7/CLionProjects/proyecto 2/Tank_Attack/cmake-build-debug/TuProyecto_autogen/timestamp"

TuProyecto_autogen: CMakeFiles/TuProyecto_autogen
TuProyecto_autogen: TuProyecto_autogen/timestamp
TuProyecto_autogen: CMakeFiles/TuProyecto_autogen.dir/build.make
.PHONY : TuProyecto_autogen

# Rule to build all files generated by this target.
CMakeFiles/TuProyecto_autogen.dir/build: TuProyecto_autogen
.PHONY : CMakeFiles/TuProyecto_autogen.dir/build

CMakeFiles/TuProyecto_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TuProyecto_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TuProyecto_autogen.dir/clean

CMakeFiles/TuProyecto_autogen.dir/depend:
	cd "/home/gabonm7/CLionProjects/proyecto 2/Tank_Attack/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/gabonm7/CLionProjects/proyecto 2/Tank_Attack" "/home/gabonm7/CLionProjects/proyecto 2/Tank_Attack" "/home/gabonm7/CLionProjects/proyecto 2/Tank_Attack/cmake-build-debug" "/home/gabonm7/CLionProjects/proyecto 2/Tank_Attack/cmake-build-debug" "/home/gabonm7/CLionProjects/proyecto 2/Tank_Attack/cmake-build-debug/CMakeFiles/TuProyecto_autogen.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/TuProyecto_autogen.dir/depend
