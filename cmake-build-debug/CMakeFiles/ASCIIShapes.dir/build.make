# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\pc\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\231.8109.174\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\pc\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\231.8109.174\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\pc\CLionProjects\ASCIIGeometry\ASCIIGeometry

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\pc\CLionProjects\ASCIIGeometry\ASCIIGeometry\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ASCIIShapes.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ASCIIShapes.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ASCIIShapes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ASCIIShapes.dir/flags.make

CMakeFiles/ASCIIShapes.dir/main.cpp.obj: CMakeFiles/ASCIIShapes.dir/flags.make
CMakeFiles/ASCIIShapes.dir/main.cpp.obj: C:/Users/pc/CLionProjects/ASCIIGeometry/ASCIIGeometry/main.cpp
CMakeFiles/ASCIIShapes.dir/main.cpp.obj: CMakeFiles/ASCIIShapes.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pc\CLionProjects\ASCIIGeometry\ASCIIGeometry\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ASCIIShapes.dir/main.cpp.obj"
	C:\Users\pc\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\231.8109.174\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ASCIIShapes.dir/main.cpp.obj -MF CMakeFiles\ASCIIShapes.dir\main.cpp.obj.d -o CMakeFiles\ASCIIShapes.dir\main.cpp.obj -c C:\Users\pc\CLionProjects\ASCIIGeometry\ASCIIGeometry\main.cpp

CMakeFiles/ASCIIShapes.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ASCIIShapes.dir/main.cpp.i"
	C:\Users\pc\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\231.8109.174\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\pc\CLionProjects\ASCIIGeometry\ASCIIGeometry\main.cpp > CMakeFiles\ASCIIShapes.dir\main.cpp.i

CMakeFiles/ASCIIShapes.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ASCIIShapes.dir/main.cpp.s"
	C:\Users\pc\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\231.8109.174\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\pc\CLionProjects\ASCIIGeometry\ASCIIGeometry\main.cpp -o CMakeFiles\ASCIIShapes.dir\main.cpp.s

# Object files for target ASCIIShapes
ASCIIShapes_OBJECTS = \
"CMakeFiles/ASCIIShapes.dir/main.cpp.obj"

# External object files for target ASCIIShapes
ASCIIShapes_EXTERNAL_OBJECTS =

ASCIIShapes.exe: CMakeFiles/ASCIIShapes.dir/main.cpp.obj
ASCIIShapes.exe: CMakeFiles/ASCIIShapes.dir/build.make
ASCIIShapes.exe: CMakeFiles/ASCIIShapes.dir/linkLibs.rsp
ASCIIShapes.exe: CMakeFiles/ASCIIShapes.dir/objects1
ASCIIShapes.exe: CMakeFiles/ASCIIShapes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\pc\CLionProjects\ASCIIGeometry\ASCIIGeometry\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ASCIIShapes.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ASCIIShapes.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ASCIIShapes.dir/build: ASCIIShapes.exe
.PHONY : CMakeFiles/ASCIIShapes.dir/build

CMakeFiles/ASCIIShapes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ASCIIShapes.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ASCIIShapes.dir/clean

CMakeFiles/ASCIIShapes.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\pc\CLionProjects\ASCIIGeometry\ASCIIGeometry C:\Users\pc\CLionProjects\ASCIIGeometry\ASCIIGeometry C:\Users\pc\CLionProjects\ASCIIGeometry\ASCIIGeometry\cmake-build-debug C:\Users\pc\CLionProjects\ASCIIGeometry\ASCIIGeometry\cmake-build-debug C:\Users\pc\CLionProjects\ASCIIGeometry\ASCIIGeometry\cmake-build-debug\CMakeFiles\ASCIIShapes.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ASCIIShapes.dir/depend
