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
CMAKE_SOURCE_DIR = /home/naveen/Desktop/challenge

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/naveen/Desktop/challenge/build

# Include any dependencies generated for this target.
include app/CMakeFiles/candidate_solution.dir/depend.make

# Include the progress variables for this target.
include app/CMakeFiles/candidate_solution.dir/progress.make

# Include the compile flags for this target's objects.
include app/CMakeFiles/candidate_solution.dir/flags.make

app/CMakeFiles/candidate_solution.dir/main.cpp.o: app/CMakeFiles/candidate_solution.dir/flags.make
app/CMakeFiles/candidate_solution.dir/main.cpp.o: ../app/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/naveen/Desktop/challenge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object app/CMakeFiles/candidate_solution.dir/main.cpp.o"
	cd /home/naveen/Desktop/challenge/build/app && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/candidate_solution.dir/main.cpp.o -c /home/naveen/Desktop/challenge/app/main.cpp

app/CMakeFiles/candidate_solution.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/candidate_solution.dir/main.cpp.i"
	cd /home/naveen/Desktop/challenge/build/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/naveen/Desktop/challenge/app/main.cpp > CMakeFiles/candidate_solution.dir/main.cpp.i

app/CMakeFiles/candidate_solution.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/candidate_solution.dir/main.cpp.s"
	cd /home/naveen/Desktop/challenge/build/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/naveen/Desktop/challenge/app/main.cpp -o CMakeFiles/candidate_solution.dir/main.cpp.s

app/CMakeFiles/candidate_solution.dir/__/include/network.cpp.o: app/CMakeFiles/candidate_solution.dir/flags.make
app/CMakeFiles/candidate_solution.dir/__/include/network.cpp.o: ../include/network.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/naveen/Desktop/challenge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object app/CMakeFiles/candidate_solution.dir/__/include/network.cpp.o"
	cd /home/naveen/Desktop/challenge/build/app && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/candidate_solution.dir/__/include/network.cpp.o -c /home/naveen/Desktop/challenge/include/network.cpp

app/CMakeFiles/candidate_solution.dir/__/include/network.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/candidate_solution.dir/__/include/network.cpp.i"
	cd /home/naveen/Desktop/challenge/build/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/naveen/Desktop/challenge/include/network.cpp > CMakeFiles/candidate_solution.dir/__/include/network.cpp.i

app/CMakeFiles/candidate_solution.dir/__/include/network.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/candidate_solution.dir/__/include/network.cpp.s"
	cd /home/naveen/Desktop/challenge/build/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/naveen/Desktop/challenge/include/network.cpp -o CMakeFiles/candidate_solution.dir/__/include/network.cpp.s

# Object files for target candidate_solution
candidate_solution_OBJECTS = \
"CMakeFiles/candidate_solution.dir/main.cpp.o" \
"CMakeFiles/candidate_solution.dir/__/include/network.cpp.o"

# External object files for target candidate_solution
candidate_solution_EXTERNAL_OBJECTS =

app/candidate_solution: app/CMakeFiles/candidate_solution.dir/main.cpp.o
app/candidate_solution: app/CMakeFiles/candidate_solution.dir/__/include/network.cpp.o
app/candidate_solution: app/CMakeFiles/candidate_solution.dir/build.make
app/candidate_solution: /usr/lib/x86_64-linux-gnu/libpython3.8.so
app/candidate_solution: app/CMakeFiles/candidate_solution.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/naveen/Desktop/challenge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable candidate_solution"
	cd /home/naveen/Desktop/challenge/build/app && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/candidate_solution.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
app/CMakeFiles/candidate_solution.dir/build: app/candidate_solution

.PHONY : app/CMakeFiles/candidate_solution.dir/build

app/CMakeFiles/candidate_solution.dir/clean:
	cd /home/naveen/Desktop/challenge/build/app && $(CMAKE_COMMAND) -P CMakeFiles/candidate_solution.dir/cmake_clean.cmake
.PHONY : app/CMakeFiles/candidate_solution.dir/clean

app/CMakeFiles/candidate_solution.dir/depend:
	cd /home/naveen/Desktop/challenge/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/naveen/Desktop/challenge /home/naveen/Desktop/challenge/app /home/naveen/Desktop/challenge/build /home/naveen/Desktop/challenge/build/app /home/naveen/Desktop/challenge/build/app/CMakeFiles/candidate_solution.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : app/CMakeFiles/candidate_solution.dir/depend
