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
include Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/depend.make

# Include the progress variables for this target.
include Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/progress.make

# Include the compile flags for this target's objects.
include Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/flags.make

Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/ITKIsolatedConnected.o: Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/flags.make
Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/ITKIsolatedConnected.o: /home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins/Source/RegionGrowing/ITKIsolatedConnected.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/ITKIsolatedConnected.o"
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/RegionGrowing && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ITKIsolatedConnected.dir/ITKIsolatedConnected.o -c /home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins/Source/RegionGrowing/ITKIsolatedConnected.cxx

Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/ITKIsolatedConnected.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ITKIsolatedConnected.dir/ITKIsolatedConnected.i"
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/RegionGrowing && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins/Source/RegionGrowing/ITKIsolatedConnected.cxx > CMakeFiles/ITKIsolatedConnected.dir/ITKIsolatedConnected.i

Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/ITKIsolatedConnected.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ITKIsolatedConnected.dir/ITKIsolatedConnected.s"
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/RegionGrowing && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins/Source/RegionGrowing/ITKIsolatedConnected.cxx -o CMakeFiles/ITKIsolatedConnected.dir/ITKIsolatedConnected.s

Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/ITKIsolatedConnected.o.requires:
.PHONY : Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/ITKIsolatedConnected.o.requires

Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/ITKIsolatedConnected.o.provides: Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/ITKIsolatedConnected.o.requires
	$(MAKE) -f Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/build.make Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/ITKIsolatedConnected.o.provides.build
.PHONY : Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/ITKIsolatedConnected.o.provides

Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/ITKIsolatedConnected.o.provides.build: Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/ITKIsolatedConnected.o
.PHONY : Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/ITKIsolatedConnected.o.provides.build

Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/moc_ITKIsolatedConnected.o: Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/flags.make
Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/moc_ITKIsolatedConnected.o: Source/RegionGrowing/moc_ITKIsolatedConnected.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/moc_ITKIsolatedConnected.o"
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/RegionGrowing && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ITKIsolatedConnected.dir/moc_ITKIsolatedConnected.o -c /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/RegionGrowing/moc_ITKIsolatedConnected.cxx

Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/moc_ITKIsolatedConnected.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ITKIsolatedConnected.dir/moc_ITKIsolatedConnected.i"
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/RegionGrowing && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/RegionGrowing/moc_ITKIsolatedConnected.cxx > CMakeFiles/ITKIsolatedConnected.dir/moc_ITKIsolatedConnected.i

Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/moc_ITKIsolatedConnected.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ITKIsolatedConnected.dir/moc_ITKIsolatedConnected.s"
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/RegionGrowing && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/RegionGrowing/moc_ITKIsolatedConnected.cxx -o CMakeFiles/ITKIsolatedConnected.dir/moc_ITKIsolatedConnected.s

Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/moc_ITKIsolatedConnected.o.requires:
.PHONY : Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/moc_ITKIsolatedConnected.o.requires

Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/moc_ITKIsolatedConnected.o.provides: Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/moc_ITKIsolatedConnected.o.requires
	$(MAKE) -f Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/build.make Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/moc_ITKIsolatedConnected.o.provides.build
.PHONY : Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/moc_ITKIsolatedConnected.o.provides

Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/moc_ITKIsolatedConnected.o.provides.build: Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/moc_ITKIsolatedConnected.o
.PHONY : Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/moc_ITKIsolatedConnected.o.provides.build

Source/RegionGrowing/moc_ITKIsolatedConnected.cxx: /home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins/Source/RegionGrowing/ITKIsolatedConnected.h
	$(CMAKE_COMMAND) -E cmake_progress_report /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_ITKIsolatedConnected.cxx"
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/RegionGrowing && /usr/bin/moc-qt4 -I/home/liyun/V3D/v3d_main/basic_c_fun/../common_lib/include -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/Review/Statistics -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/Review -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/gdcm/src -I/home/liyun/ITK/ITK-bin/Utilities/gdcm -I/home/liyun/ITK/ITK-bin/Utilities/vxl/core -I/home/liyun/ITK/ITK-bin/Utilities/vxl/vcl -I/home/liyun/ITK/ITK-bin/Utilities/vxl/v3p/netlib -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/vxl/core -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/vxl/vcl -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/vxl/v3p/netlib -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities -I/home/liyun/ITK/ITK-bin/Utilities -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/itkExtHdrs -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/nifti/znzlib -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/nifti/niftilib -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/expat -I/home/liyun/ITK/ITK-bin/Utilities/expat -I/home/liyun/ITK/ITK-bin/Utilities/DICOMParser -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/DICOMParser -I/home/liyun/ITK/ITK-bin/Utilities/NrrdIO -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/NrrdIO -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/MetaIO -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/SpatialObject -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/Numerics/NeuralNetworks -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/Numerics/FEM -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/IO -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/Numerics -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/Common -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/BasicFilters -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/Algorithms -I/home/liyun/ITK/ITK-bin -I/usr/include/qt4 -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtCore -I/home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins/Source/Common -I/home/liyun/V3D/v3d_main/basic_c_fun -I/home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins -DQT_GUI_LIB -DQT_CORE_LIB -o /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/RegionGrowing/moc_ITKIsolatedConnected.cxx /home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins/Source/RegionGrowing/ITKIsolatedConnected.h

# Object files for target ITKIsolatedConnected
ITKIsolatedConnected_OBJECTS = \
"CMakeFiles/ITKIsolatedConnected.dir/ITKIsolatedConnected.o" \
"CMakeFiles/ITKIsolatedConnected.dir/moc_ITKIsolatedConnected.o"

# External object files for target ITKIsolatedConnected
ITKIsolatedConnected_EXTERNAL_OBJECTS =

bin/libITKIsolatedConnected.so: Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/ITKIsolatedConnected.o
bin/libITKIsolatedConnected.so: Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/moc_ITKIsolatedConnected.o
bin/libITKIsolatedConnected.so: bin/libV3DInterface.a
bin/libITKIsolatedConnected.so: bin/libV3DITKCommon.a
bin/libITKIsolatedConnected.so: /usr/lib/libQtGui.so
bin/libITKIsolatedConnected.so: /usr/lib/libQtCore.so
bin/libITKIsolatedConnected.so: Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/build.make
bin/libITKIsolatedConnected.so: Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../../bin/libITKIsolatedConnected.so"
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/RegionGrowing && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ITKIsolatedConnected.dir/link.txt --verbose=$(VERBOSE)
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/RegionGrowing && /usr/bin/cmake -E copy /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/bin/libITKIsolatedConnected.so /home/liyun/V3D/v3d/plugins/ITK//RegionGrowing/ITKIsolatedConnected/ITKIsolatedConnected.so

# Rule to build all files generated by this target.
Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/build: bin/libITKIsolatedConnected.so
.PHONY : Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/build

Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/requires: Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/ITKIsolatedConnected.o.requires
Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/requires: Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/moc_ITKIsolatedConnected.o.requires
.PHONY : Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/requires

Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/clean:
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/RegionGrowing && $(CMAKE_COMMAND) -P CMakeFiles/ITKIsolatedConnected.dir/cmake_clean.cmake
.PHONY : Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/clean

Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/depend: Source/RegionGrowing/moc_ITKIsolatedConnected.cxx
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins /home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins/Source/RegionGrowing /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/RegionGrowing /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Source/RegionGrowing/CMakeFiles/ITKIsolatedConnected.dir/depend
