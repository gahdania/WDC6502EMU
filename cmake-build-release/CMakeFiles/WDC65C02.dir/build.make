# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /home/david/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/221.5787.29/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/david/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/221.5787.29/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/david/projects/W65C02EMU

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/david/projects/W65C02EMU/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/WDC65C02.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/WDC65C02.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/WDC65C02.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WDC65C02.dir/flags.make

CMakeFiles/WDC65C02.dir/main.cpp.o: CMakeFiles/WDC65C02.dir/flags.make
CMakeFiles/WDC65C02.dir/main.cpp.o: ../main.cpp
CMakeFiles/WDC65C02.dir/main.cpp.o: CMakeFiles/WDC65C02.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/projects/W65C02EMU/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WDC65C02.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WDC65C02.dir/main.cpp.o -MF CMakeFiles/WDC65C02.dir/main.cpp.o.d -o CMakeFiles/WDC65C02.dir/main.cpp.o -c /home/david/projects/W65C02EMU/main.cpp

CMakeFiles/WDC65C02.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WDC65C02.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/projects/W65C02EMU/main.cpp > CMakeFiles/WDC65C02.dir/main.cpp.i

CMakeFiles/WDC65C02.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WDC65C02.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/projects/W65C02EMU/main.cpp -o CMakeFiles/WDC65C02.dir/main.cpp.s

CMakeFiles/WDC65C02.dir/BUS.cpp.o: CMakeFiles/WDC65C02.dir/flags.make
CMakeFiles/WDC65C02.dir/BUS.cpp.o: ../BUS.cpp
CMakeFiles/WDC65C02.dir/BUS.cpp.o: CMakeFiles/WDC65C02.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/projects/W65C02EMU/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/WDC65C02.dir/BUS.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WDC65C02.dir/BUS.cpp.o -MF CMakeFiles/WDC65C02.dir/BUS.cpp.o.d -o CMakeFiles/WDC65C02.dir/BUS.cpp.o -c /home/david/projects/W65C02EMU/BUS.cpp

CMakeFiles/WDC65C02.dir/BUS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WDC65C02.dir/BUS.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/projects/W65C02EMU/BUS.cpp > CMakeFiles/WDC65C02.dir/BUS.cpp.i

CMakeFiles/WDC65C02.dir/BUS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WDC65C02.dir/BUS.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/projects/W65C02EMU/BUS.cpp -o CMakeFiles/WDC65C02.dir/BUS.cpp.s

CMakeFiles/WDC65C02.dir/ROM.cpp.o: CMakeFiles/WDC65C02.dir/flags.make
CMakeFiles/WDC65C02.dir/ROM.cpp.o: ../ROM.cpp
CMakeFiles/WDC65C02.dir/ROM.cpp.o: CMakeFiles/WDC65C02.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/projects/W65C02EMU/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/WDC65C02.dir/ROM.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WDC65C02.dir/ROM.cpp.o -MF CMakeFiles/WDC65C02.dir/ROM.cpp.o.d -o CMakeFiles/WDC65C02.dir/ROM.cpp.o -c /home/david/projects/W65C02EMU/ROM.cpp

CMakeFiles/WDC65C02.dir/ROM.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WDC65C02.dir/ROM.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/projects/W65C02EMU/ROM.cpp > CMakeFiles/WDC65C02.dir/ROM.cpp.i

CMakeFiles/WDC65C02.dir/ROM.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WDC65C02.dir/ROM.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/projects/W65C02EMU/ROM.cpp -o CMakeFiles/WDC65C02.dir/ROM.cpp.s

CMakeFiles/WDC65C02.dir/VIA.cpp.o: CMakeFiles/WDC65C02.dir/flags.make
CMakeFiles/WDC65C02.dir/VIA.cpp.o: ../VIA.cpp
CMakeFiles/WDC65C02.dir/VIA.cpp.o: CMakeFiles/WDC65C02.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/projects/W65C02EMU/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/WDC65C02.dir/VIA.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WDC65C02.dir/VIA.cpp.o -MF CMakeFiles/WDC65C02.dir/VIA.cpp.o.d -o CMakeFiles/WDC65C02.dir/VIA.cpp.o -c /home/david/projects/W65C02EMU/VIA.cpp

CMakeFiles/WDC65C02.dir/VIA.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WDC65C02.dir/VIA.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/projects/W65C02EMU/VIA.cpp > CMakeFiles/WDC65C02.dir/VIA.cpp.i

CMakeFiles/WDC65C02.dir/VIA.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WDC65C02.dir/VIA.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/projects/W65C02EMU/VIA.cpp -o CMakeFiles/WDC65C02.dir/VIA.cpp.s

CMakeFiles/WDC65C02.dir/ACIA.cpp.o: CMakeFiles/WDC65C02.dir/flags.make
CMakeFiles/WDC65C02.dir/ACIA.cpp.o: ../ACIA.cpp
CMakeFiles/WDC65C02.dir/ACIA.cpp.o: CMakeFiles/WDC65C02.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/projects/W65C02EMU/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/WDC65C02.dir/ACIA.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WDC65C02.dir/ACIA.cpp.o -MF CMakeFiles/WDC65C02.dir/ACIA.cpp.o.d -o CMakeFiles/WDC65C02.dir/ACIA.cpp.o -c /home/david/projects/W65C02EMU/ACIA.cpp

CMakeFiles/WDC65C02.dir/ACIA.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WDC65C02.dir/ACIA.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/projects/W65C02EMU/ACIA.cpp > CMakeFiles/WDC65C02.dir/ACIA.cpp.i

CMakeFiles/WDC65C02.dir/ACIA.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WDC65C02.dir/ACIA.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/projects/W65C02EMU/ACIA.cpp -o CMakeFiles/WDC65C02.dir/ACIA.cpp.s

CMakeFiles/WDC65C02.dir/CPU.cpp.o: CMakeFiles/WDC65C02.dir/flags.make
CMakeFiles/WDC65C02.dir/CPU.cpp.o: ../CPU.cpp
CMakeFiles/WDC65C02.dir/CPU.cpp.o: CMakeFiles/WDC65C02.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/projects/W65C02EMU/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/WDC65C02.dir/CPU.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WDC65C02.dir/CPU.cpp.o -MF CMakeFiles/WDC65C02.dir/CPU.cpp.o.d -o CMakeFiles/WDC65C02.dir/CPU.cpp.o -c /home/david/projects/W65C02EMU/CPU.cpp

CMakeFiles/WDC65C02.dir/CPU.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WDC65C02.dir/CPU.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/projects/W65C02EMU/CPU.cpp > CMakeFiles/WDC65C02.dir/CPU.cpp.i

CMakeFiles/WDC65C02.dir/CPU.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WDC65C02.dir/CPU.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/projects/W65C02EMU/CPU.cpp -o CMakeFiles/WDC65C02.dir/CPU.cpp.s

# Object files for target WDC65C02
WDC65C02_OBJECTS = \
"CMakeFiles/WDC65C02.dir/main.cpp.o" \
"CMakeFiles/WDC65C02.dir/BUS.cpp.o" \
"CMakeFiles/WDC65C02.dir/ROM.cpp.o" \
"CMakeFiles/WDC65C02.dir/VIA.cpp.o" \
"CMakeFiles/WDC65C02.dir/ACIA.cpp.o" \
"CMakeFiles/WDC65C02.dir/CPU.cpp.o"

# External object files for target WDC65C02
WDC65C02_EXTERNAL_OBJECTS =

WDC65C02: CMakeFiles/WDC65C02.dir/main.cpp.o
WDC65C02: CMakeFiles/WDC65C02.dir/BUS.cpp.o
WDC65C02: CMakeFiles/WDC65C02.dir/ROM.cpp.o
WDC65C02: CMakeFiles/WDC65C02.dir/VIA.cpp.o
WDC65C02: CMakeFiles/WDC65C02.dir/ACIA.cpp.o
WDC65C02: CMakeFiles/WDC65C02.dir/CPU.cpp.o
WDC65C02: CMakeFiles/WDC65C02.dir/build.make
WDC65C02: CMakeFiles/WDC65C02.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/david/projects/W65C02EMU/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable WDC65C02"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WDC65C02.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WDC65C02.dir/build: WDC65C02
.PHONY : CMakeFiles/WDC65C02.dir/build

CMakeFiles/WDC65C02.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WDC65C02.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WDC65C02.dir/clean

CMakeFiles/WDC65C02.dir/depend:
	cd /home/david/projects/W65C02EMU/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/david/projects/W65C02EMU /home/david/projects/W65C02EMU /home/david/projects/W65C02EMU/cmake-build-release /home/david/projects/W65C02EMU/cmake-build-release /home/david/projects/W65C02EMU/cmake-build-release/CMakeFiles/WDC65C02.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/WDC65C02.dir/depend
