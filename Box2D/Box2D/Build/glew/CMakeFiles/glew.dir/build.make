# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.4

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files (x86)\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files (x86)\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build

# Include any dependencies generated for this target.
include glew\CMakeFiles\glew.dir\depend.make

# Include the progress variables for this target.
include glew\CMakeFiles\glew.dir\progress.make

# Include the compile flags for this target's objects.
include glew\CMakeFiles\glew.dir\flags.make

glew\CMakeFiles\glew.dir\glew.c.obj: glew\CMakeFiles\glew.dir\flags.make
glew\CMakeFiles\glew.dir\glew.c.obj: ..\glew\glew.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object glew/CMakeFiles/glew.dir/glew.c.obj"
	cd C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build\glew
	D:\PROGRA~1\MICROS~1.0\VC\bin\cl.exe  @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\glew.dir\glew.c.obj /FdCMakeFiles\glew.dir\ /FS -c C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\glew\glew.c
<<
	cd C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build

glew\CMakeFiles\glew.dir\glew.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glew.dir/glew.c.i"
	cd C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build\glew
	D:\PROGRA~1\MICROS~1.0\VC\bin\cl.exe  > CMakeFiles\glew.dir\glew.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\glew\glew.c
<<
	cd C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build

glew\CMakeFiles\glew.dir\glew.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glew.dir/glew.c.s"
	cd C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build\glew
	D:\PROGRA~1\MICROS~1.0\VC\bin\cl.exe  @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\glew.dir\glew.c.s /c C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\glew\glew.c
<<
	cd C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build

glew\CMakeFiles\glew.dir\glew.c.obj.requires:

.PHONY : glew\CMakeFiles\glew.dir\glew.c.obj.requires

glew\CMakeFiles\glew.dir\glew.c.obj.provides: glew\CMakeFiles\glew.dir\glew.c.obj.requires
	$(MAKE) -f glew\CMakeFiles\glew.dir\build.make /nologo -$(MAKEFLAGS) glew\CMakeFiles\glew.dir\glew.c.obj.provides.build
.PHONY : glew\CMakeFiles\glew.dir\glew.c.obj.provides

glew\CMakeFiles\glew.dir\glew.c.obj.provides.build: glew\CMakeFiles\glew.dir\glew.c.obj


# Object files for target glew
glew_OBJECTS = \
"CMakeFiles\glew.dir\glew.c.obj"

# External object files for target glew
glew_EXTERNAL_OBJECTS =

glew\glew.lib: glew\CMakeFiles\glew.dir\glew.c.obj
glew\glew.lib: glew\CMakeFiles\glew.dir\build.make
glew\glew.lib: glew\CMakeFiles\glew.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library glew.lib"
	cd C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build\glew
	$(CMAKE_COMMAND) -P CMakeFiles\glew.dir\cmake_clean_target.cmake
	cd C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build
	cd C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build\glew
	D:\PROGRA~1\MICROS~1.0\VC\bin\link.exe /lib /nologo  /machine:X86 /out:glew.lib @CMakeFiles\glew.dir\objects1.rsp 
	cd C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build

# Rule to build all files generated by this target.
glew\CMakeFiles\glew.dir\build: glew\glew.lib

.PHONY : glew\CMakeFiles\glew.dir\build

glew\CMakeFiles\glew.dir\requires: glew\CMakeFiles\glew.dir\glew.c.obj.requires

.PHONY : glew\CMakeFiles\glew.dir\requires

glew\CMakeFiles\glew.dir\clean:
	cd C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build\glew
	$(CMAKE_COMMAND) -P CMakeFiles\glew.dir\cmake_clean.cmake
	cd C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build
.PHONY : glew\CMakeFiles\glew.dir\clean

glew\CMakeFiles\glew.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\glew C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build\glew C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build\glew\CMakeFiles\glew.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : glew\CMakeFiles\glew.dir\depend

