# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build

# Include any dependencies generated for this target.
include Source/Arithmetic/CMakeFiles/Subtract.dir/depend.make

# Include the progress variables for this target.
include Source/Arithmetic/CMakeFiles/Subtract.dir/progress.make

# Include the compile flags for this target's objects.
include Source/Arithmetic/CMakeFiles/Subtract.dir/flags.make

Source/Arithmetic/CMakeFiles/Subtract.dir/Subtract.o: Source/Arithmetic/CMakeFiles/Subtract.dir/flags.make
Source/Arithmetic/CMakeFiles/Subtract.dir/Subtract.o: /home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins/Source/Arithmetic/Subtract.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Source/Arithmetic/CMakeFiles/Subtract.dir/Subtract.o"
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/Arithmetic && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Subtract.dir/Subtract.o -c /home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins/Source/Arithmetic/Subtract.cxx

Source/Arithmetic/CMakeFiles/Subtract.dir/Subtract.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Subtract.dir/Subtract.i"
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/Arithmetic && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins/Source/Arithmetic/Subtract.cxx > CMakeFiles/Subtract.dir/Subtract.i

Source/Arithmetic/CMakeFiles/Subtract.dir/Subtract.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Subtract.dir/Subtract.s"
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/Arithmetic && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins/Source/Arithmetic/Subtract.cxx -o CMakeFiles/Subtract.dir/Subtract.s

Source/Arithmetic/CMakeFiles/Subtract.dir/Subtract.o.requires:
.PHONY : Source/Arithmetic/CMakeFiles/Subtract.dir/Subtract.o.requires

Source/Arithmetic/CMakeFiles/Subtract.dir/Subtract.o.provides: Source/Arithmetic/CMakeFiles/Subtract.dir/Subtract.o.requires
	$(MAKE) -f Source/Arithmetic/CMakeFiles/Subtract.dir/build.make Source/Arithmetic/CMakeFiles/Subtract.dir/Subtract.o.provides.build
.PHONY : Source/Arithmetic/CMakeFiles/Subtract.dir/Subtract.o.provides

Source/Arithmetic/CMakeFiles/Subtract.dir/Subtract.o.provides.build: Source/Arithmetic/CMakeFiles/Subtract.dir/Subtract.o
.PHONY : Source/Arithmetic/CMakeFiles/Subtract.dir/Subtract.o.provides.build

Source/Arithmetic/CMakeFiles/Subtract.dir/moc_Subtract.o: Source/Arithmetic/CMakeFiles/Subtract.dir/flags.make
Source/Arithmetic/CMakeFiles/Subtract.dir/moc_Subtract.o: Source/Arithmetic/moc_Subtract.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Source/Arithmetic/CMakeFiles/Subtract.dir/moc_Subtract.o"
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/Arithmetic && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Subtract.dir/moc_Subtract.o -c /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/Arithmetic/moc_Subtract.cxx

Source/Arithmetic/CMakeFiles/Subtract.dir/moc_Subtract.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Subtract.dir/moc_Subtract.i"
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/Arithmetic && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/Arithmetic/moc_Subtract.cxx > CMakeFiles/Subtract.dir/moc_Subtract.i

Source/Arithmetic/CMakeFiles/Subtract.dir/moc_Subtract.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Subtract.dir/moc_Subtract.s"
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/Arithmetic && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/Arithmetic/moc_Subtract.cxx -o CMakeFiles/Subtract.dir/moc_Subtract.s

Source/Arithmetic/CMakeFiles/Subtract.dir/moc_Subtract.o.requires:
.PHONY : Source/Arithmetic/CMakeFiles/Subtract.dir/moc_Subtract.o.requires

Source/Arithmetic/CMakeFiles/Subtract.dir/moc_Subtract.o.provides: Source/Arithmetic/CMakeFiles/Subtract.dir/moc_Subtract.o.requires
	$(MAKE) -f Source/Arithmetic/CMakeFiles/Subtract.dir/build.make Source/Arithmetic/CMakeFiles/Subtract.dir/moc_Subtract.o.provides.build
.PHONY : Source/Arithmetic/CMakeFiles/Subtract.dir/moc_Subtract.o.provides

Source/Arithmetic/CMakeFiles/Subtract.dir/moc_Subtract.o.provides.build: Source/Arithmetic/CMakeFiles/Subtract.dir/moc_Subtract.o
.PHONY : Source/Arithmetic/CMakeFiles/Subtract.dir/moc_Subtract.o.provides.build

Source/Arithmetic/moc_Subtract.cxx: /home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins/Source/Arithmetic/Subtract.h
	$(CMAKE_COMMAND) -E cmake_progress_report /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_Subtract.cxx"
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/Arithmetic && /usr/bin/moc-qt4 -I/home/liyun/V3D/v3d_main/basic_c_fun/../common_lib/include -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/Review/Statistics -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/Review -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/gdcm/src -I/home/liyun/ITK/ITK-bin/Utilities/gdcm -I/home/liyun/ITK/ITK-bin/Utilities/vxl/core -I/home/liyun/ITK/ITK-bin/Utilities/vxl/vcl -I/home/liyun/ITK/ITK-bin/Utilities/vxl/v3p/netlib -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/vxl/core -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/vxl/vcl -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/vxl/v3p/netlib -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities -I/home/liyun/ITK/ITK-bin/Utilities -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/itkExtHdrs -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/nifti/znzlib -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/nifti/niftilib -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/expat -I/home/liyun/ITK/ITK-bin/Utilities/expat -I/home/liyun/ITK/ITK-bin/Utilities/DICOMParser -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/DICOMParser -I/home/liyun/ITK/ITK-bin/Utilities/NrrdIO -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/NrrdIO -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/MetaIO -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/SpatialObject -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/Numerics/NeuralNetworks -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/Numerics/FEM -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/IO -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/Numerics -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/Common -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/BasicFilters -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/Algorithms -I/home/liyun/ITK/ITK-bin -I/usr/include/qt4 -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtCore -I/home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins/Source/Common -I/home/liyun/V3D/v3d_main/basic_c_fun -I/home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins -DQT_GUI_LIB -DQT_CORE_LIB -o /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/Arithmetic/moc_Subtract.cxx /home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins/Source/Arithmetic/Subtract.h

# Object files for target Subtract
Subtract_OBJECTS = \
"CMakeFiles/Subtract.dir/Subtract.o" \
"CMakeFiles/Subtract.dir/moc_Subtract.o"

# External object files for target Subtract
Subtract_EXTERNAL_OBJECTS =

bin/libSubtract.so: Source/Arithmetic/CMakeFiles/Subtract.dir/Subtract.o
bin/libSubtract.so: Source/Arithmetic/CMakeFiles/Subtract.dir/moc_Subtract.o
bin/libSubtract.so: bin/libV3DInterface.a
bin/libSubtract.so: bin/libV3DITKCommon.a
bin/libSubtract.so: /usr/lib/libQtGui.so
bin/libSubtract.so: /usr/lib/libQtCore.so
bin/libSubtract.so: Source/Arithmetic/CMakeFiles/Subtract.dir/build.make
bin/libSubtract.so: Source/Arithmetic/CMakeFiles/Subtract.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../../bin/libSubtract.so"
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/Arithmetic && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Subtract.dir/link.txt --verbose=$(VERBOSE)
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/Arithmetic && /usr/bin/cmake -E copy /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/bin/libSubtract.so /home/liyun/V3D/v3d/plugins/ITK//Arithmetic/Subtract/Subtract.so

# Rule to build all files generated by this target.
Source/Arithmetic/CMakeFiles/Subtract.dir/build: bin/libSubtract.so
.PHONY : Source/Arithmetic/CMakeFiles/Subtract.dir/build

Source/Arithmetic/CMakeFiles/Subtract.dir/requires: Source/Arithmetic/CMakeFiles/Subtract.dir/Subtract.o.requires
Source/Arithmetic/CMakeFiles/Subtract.dir/requires: Source/Arithmetic/CMakeFiles/Subtract.dir/moc_Subtract.o.requires
.PHONY : Source/Arithmetic/CMakeFiles/Subtract.dir/requires

Source/Arithmetic/CMakeFiles/Subtract.dir/clean:
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/Arithmetic && $(CMAKE_COMMAND) -P CMakeFiles/Subtract.dir/cmake_clean.cmake
.PHONY : Source/Arithmetic/CMakeFiles/Subtract.dir/clean

Source/Arithmetic/CMakeFiles/Subtract.dir/depend: Source/Arithmetic/moc_Subtract.cxx
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins /home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins/Source/Arithmetic /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/Arithmetic /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/Arithmetic/CMakeFiles/Subtract.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Source/Arithmetic/CMakeFiles/Subtract.dir/depend

