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
include HelloWorld\CMakeFiles\HelloWorld.dir\depend.make

# Include the progress variables for this target.
include HelloWorld\CMakeFiles\HelloWorld.dir\progress.make

# Include the compile flags for this target's objects.
include HelloWorld\CMakeFiles\HelloWorld.dir\flags.make

HelloWorld\CMakeFiles\HelloWorld.dir\HelloWorld.cpp.obj: HelloWorld\CMakeFiles\HelloWorld.dir\flags.make
HelloWorld\CMakeFiles\HelloWorld.dir\HelloWorld.cpp.obj: ..\HelloWorld\HelloWorld.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object HelloWorld/CMakeFiles/HelloWorld.dir/HelloWorld.cpp.obj"
	cd C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build\HelloWorld
	D:\PROGRA~1\MICROS~1.0\VC\bin\cl.exe  @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\HelloWorld.dir\HelloWorld.cpp.obj /FdCMakeFiles\HelloWorld.dir\ /FS -c C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\HelloWorld\HelloWorld.cpp
<<
	cd C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build

HelloWorld\CMakeFiles\HelloWorld.dir\HelloWorld.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HelloWorld.dir/HelloWorld.cpp.i"
	cd C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build\HelloWorld
	D:\PROGRA~1\MICROS~1.0\VC\bin\cl.exe  > CMakeFiles\HelloWorld.dir\HelloWorld.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\HelloWorld\HelloWorld.cpp
<<
	cd C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build

HelloWorld\CMakeFiles\HelloWorld.dir\HelloWorld.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HelloWorld.dir/HelloWorld.cpp.s"
	cd C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build\HelloWorld
	D:\PROGRA~1\MICROS~1.0\VC\bin\cl.exe  @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\HelloWorld.dir\HelloWorld.cpp.s /c C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\HelloWorld\HelloWorld.cpp
<<
	cd C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build

HelloWorld\CMakeFiles\HelloWorld.dir\HelloWorld.cpp.obj.requires:

.PHONY : HelloWorld\CMakeFiles\HelloWorld.dir\HelloWorld.cpp.obj.requires

HelloWorld\CMakeFiles\HelloWorld.dir\HelloWorld.cpp.obj.provides: HelloWorld\CMakeFiles\HelloWorld.dir\HelloWorld.cpp.obj.requires
	$(MAKE) -f HelloWorld\CMakeFiles\HelloWorld.dir\build.make /nologo -$(MAKEFLAGS) HelloWorld\CMakeFiles\HelloWorld.dir\HelloWorld.cpp.obj.provides.build
.PHONY : HelloWorld\CMakeFiles\HelloWorld.dir\HelloWorld.cpp.obj.provides

HelloWorld\CMakeFiles\HelloWorld.dir\HelloWorld.cpp.obj.provides.build: HelloWorld\CMakeFiles\HelloWorld.dir\HelloWorld.cpp.obj


# Object files for target HelloWorld
HelloWorld_OBJECTS = \
"CMakeFiles\HelloWorld.dir\HelloWorld.cpp.obj"

# External object files for target HelloWorld
HelloWorld_EXTERNAL_OBJECTS =

HelloWorld\HelloWorld.exe: HelloWorld\CMakeFiles\HelloWorld.dir\HelloWorld.cpp.obj
HelloWorld\HelloWorld.exe: HelloWorld\CMakeFiles\HelloWorld.dir\build.make
HelloWorld\HelloWorld.exe: Box2D\Box2D.lib
HelloWorld\HelloWorld.exe: HelloWorld\CMakeFiles\HelloWorld.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HelloWorld.exe"
	cd C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build\HelloWorld
	"D:\Program Files (x86)\CMake\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\HelloWorld.dir --manifests  -- D:\PROGRA~1\MICROS~1.0\VC\bin\link.exe /nologo @CMakeFiles\HelloWorld.dir\objects1.rsp @<<
 /out:HelloWorld.exe /implib:HelloWorld.lib /pdb:C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build\HelloWorld\HelloWorld.pdb /version:0.0   /machine:X86 /debug /INCREMENTAL /subsystem:console  ..\Box2D\Box2D.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<
	cd C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build

# Rule to build all files generated by this target.
HelloWorld\CMakeFiles\HelloWorld.dir\build: HelloWorld\HelloWorld.exe

.PHONY : HelloWorld\CMakeFiles\HelloWorld.dir\build

HelloWorld\CMakeFiles\HelloWorld.dir\requires: HelloWorld\CMakeFiles\HelloWorld.dir\HelloWorld.cpp.obj.requires

.PHONY : HelloWorld\CMakeFiles\HelloWorld.dir\requires

HelloWorld\CMakeFiles\HelloWorld.dir\clean:
	cd C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build\HelloWorld
	$(CMAKE_COMMAND) -P CMakeFiles\HelloWorld.dir\cmake_clean.cmake
	cd C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build
.PHONY : HelloWorld\CMakeFiles\HelloWorld.dir\clean

HelloWorld\CMakeFiles\HelloWorld.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\HelloWorld C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build\HelloWorld C:\Users\kalterkrieg\Documents\MEGA\pool-qt\Box2D\Box2D\Build\HelloWorld\CMakeFiles\HelloWorld.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : HelloWorld\CMakeFiles\HelloWorld.dir\depend

