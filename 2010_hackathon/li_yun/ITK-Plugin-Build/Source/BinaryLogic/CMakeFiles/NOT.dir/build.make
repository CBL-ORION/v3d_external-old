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
include Source/BinaryLogic/CMakeFiles/NOT.dir/depend.make

# Include the progress variables for this target.
include Source/BinaryLogic/CMakeFiles/NOT.dir/progress.make

# Include the compile flags for this target's objects.
include Source/BinaryLogic/CMakeFiles/NOT.dir/flags.make

Source/BinaryLogic/CMakeFiles/NOT.dir/NOT.o: Source/BinaryLogic/CMakeFiles/NOT.dir/flags.make
Source/BinaryLogic/CMakeFiles/NOT.dir/NOT.o: /home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins/Source/BinaryLogic/NOT.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Source/BinaryLogic/CMakeFiles/NOT.dir/NOT.o"
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/BinaryLogic && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/NOT.dir/NOT.o -c /home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins/Source/BinaryLogic/NOT.cxx

Source/BinaryLogic/CMakeFiles/NOT.dir/NOT.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NOT.dir/NOT.i"
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/BinaryLogic && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins/Source/BinaryLogic/NOT.cxx > CMakeFiles/NOT.dir/NOT.i

Source/BinaryLogic/CMakeFiles/NOT.dir/NOT.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NOT.dir/NOT.s"
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/BinaryLogic && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins/Source/BinaryLogic/NOT.cxx -o CMakeFiles/NOT.dir/NOT.s

Source/BinaryLogic/CMakeFiles/NOT.dir/NOT.o.requires:
.PHONY : Source/BinaryLogic/CMakeFiles/NOT.dir/NOT.o.requires

Source/BinaryLogic/CMakeFiles/NOT.dir/NOT.o.provides: Source/BinaryLogic/CMakeFiles/NOT.dir/NOT.o.requires
	$(MAKE) -f Source/BinaryLogic/CMakeFiles/NOT.dir/build.make Source/BinaryLogic/CMakeFiles/NOT.dir/NOT.o.provides.build
.PHONY : Source/BinaryLogic/CMakeFiles/NOT.dir/NOT.o.provides

Source/BinaryLogic/CMakeFiles/NOT.dir/NOT.o.provides.build: Source/BinaryLogic/CMakeFiles/NOT.dir/NOT.o
.PHONY : Source/BinaryLogic/CMakeFiles/NOT.dir/NOT.o.provides.build

Source/BinaryLogic/CMakeFiles/NOT.dir/moc_NOT.o: Source/BinaryLogic/CMakeFiles/NOT.dir/flags.make
Source/BinaryLogic/CMakeFiles/NOT.dir/moc_NOT.o: Source/BinaryLogic/moc_NOT.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Source/BinaryLogic/CMakeFiles/NOT.dir/moc_NOT.o"
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/BinaryLogic && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/NOT.dir/moc_NOT.o -c /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/BinaryLogic/moc_NOT.cxx

Source/BinaryLogic/CMakeFiles/NOT.dir/moc_NOT.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NOT.dir/moc_NOT.i"
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/BinaryLogic && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/BinaryLogic/moc_NOT.cxx > CMakeFiles/NOT.dir/moc_NOT.i

Source/BinaryLogic/CMakeFiles/NOT.dir/moc_NOT.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NOT.dir/moc_NOT.s"
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/BinaryLogic && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/BinaryLogic/moc_NOT.cxx -o CMakeFiles/NOT.dir/moc_NOT.s

Source/BinaryLogic/CMakeFiles/NOT.dir/moc_NOT.o.requires:
.PHONY : Source/BinaryLogic/CMakeFiles/NOT.dir/moc_NOT.o.requires

Source/BinaryLogic/CMakeFiles/NOT.dir/moc_NOT.o.provides: Source/BinaryLogic/CMakeFiles/NOT.dir/moc_NOT.o.requires
	$(MAKE) -f Source/BinaryLogic/CMakeFiles/NOT.dir/build.make Source/BinaryLogic/CMakeFiles/NOT.dir/moc_NOT.o.provides.build
.PHONY : Source/BinaryLogic/CMakeFiles/NOT.dir/moc_NOT.o.provides

Source/BinaryLogic/CMakeFiles/NOT.dir/moc_NOT.o.provides.build: Source/BinaryLogic/CMakeFiles/NOT.dir/moc_NOT.o
.PHONY : Source/BinaryLogic/CMakeFiles/NOT.dir/moc_NOT.o.provides.build

Source/BinaryLogic/moc_NOT.cxx: /home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins/Source/BinaryLogic/NOT.h
	$(CMAKE_COMMAND) -E cmake_progress_report /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_NOT.cxx"
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/BinaryLogic && /usr/bin/moc-qt4 -I/home/liyun/V3D/v3d_main/basic_c_fun/../common_lib/include -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/Review/Statistics -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/Review -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/gdcm/src -I/home/liyun/ITK/ITK-bin/Utilities/gdcm -I/home/liyun/ITK/ITK-bin/Utilities/vxl/core -I/home/liyun/ITK/ITK-bin/Utilities/vxl/vcl -I/home/liyun/ITK/ITK-bin/Utilities/vxl/v3p/netlib -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/vxl/core -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/vxl/vcl -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/vxl/v3p/netlib -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities -I/home/liyun/ITK/ITK-bin/Utilities -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/itkExtHdrs -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/nifti/znzlib -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/nifti/niftilib -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/expat -I/home/liyun/ITK/ITK-bin/Utilities/expat -I/home/liyun/ITK/ITK-bin/Utilities/DICOMParser -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/DICOMParser -I/home/liyun/ITK/ITK-bin/Utilities/NrrdIO -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/NrrdIO -I/home/liyun/ITK/InsightToolkit-3.20.0/Utilities/MetaIO -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/SpatialObject -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/Numerics/NeuralNetworks -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/Numerics/FEM -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/IO -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/Numerics -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/Common -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/BasicFilters -I/home/liyun/ITK/InsightToolkit-3.20.0/Code/Algorithms -I/home/liyun/ITK/ITK-bin -I/usr/include/qt4 -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtCore -I/home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins/Source/Common -I/home/liyun/V3D/v3d_main/basic_c_fun -I/home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins -DQT_GUI_LIB -DQT_CORE_LIB -o /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/BinaryLogic/moc_NOT.cxx /home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins/Source/BinaryLogic/NOT.h

# Object files for target NOT
NOT_OBJECTS = \
"CMakeFiles/NOT.dir/NOT.o" \
"CMakeFiles/NOT.dir/moc_NOT.o"

# External object files for target NOT
NOT_EXTERNAL_OBJECTS =

bin/libNOT.so: Source/BinaryLogic/CMakeFiles/NOT.dir/NOT.o
bin/libNOT.so: Source/BinaryLogic/CMakeFiles/NOT.dir/moc_NOT.o
bin/libNOT.so: bin/libV3DInterface.a
bin/libNOT.so: /usr/lib/libQtGui.so
bin/libNOT.so: /usr/lib/libQtCore.so
bin/libNOT.so: bin/libV3DInterface.a
bin/libNOT.so: /usr/lib/libQtGui.so
bin/libNOT.so: /usr/lib/libQtCore.so
bin/libNOT.so: Source/BinaryLogic/CMakeFiles/NOT.dir/build.make
bin/libNOT.so: Source/BinaryLogic/CMakeFiles/NOT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../../bin/libNOT.so"
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/BinaryLogic && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NOT.dir/link.txt --verbose=$(VERBOSE)
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/BinaryLogic && /usr/bin/cmake -E copy /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/bin/libNOT.so /home/liyun/V3D/v3d/plugins/ITK//BinaryLogic/NOT/NOT.so

# Rule to build all files generated by this target.
Source/BinaryLogic/CMakeFiles/NOT.dir/build: bin/libNOT.so
.PHONY : Source/BinaryLogic/CMakeFiles/NOT.dir/build

Source/BinaryLogic/CMakeFiles/NOT.dir/requires: Source/BinaryLogic/CMakeFiles/NOT.dir/NOT.o.requires
Source/BinaryLogic/CMakeFiles/NOT.dir/requires: Source/BinaryLogic/CMakeFiles/NOT.dir/moc_NOT.o.requires
.PHONY : Source/BinaryLogic/CMakeFiles/NOT.dir/requires

Source/BinaryLogic/CMakeFiles/NOT.dir/clean:
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/BinaryLogic && $(CMAKE_COMMAND) -P CMakeFiles/NOT.dir/cmake_clean.cmake
.PHONY : Source/BinaryLogic/CMakeFiles/NOT.dir/clean

Source/BinaryLogic/CMakeFiles/NOT.dir/depend: Source/BinaryLogic/moc_NOT.cxx
	cd /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins /home/liyun/V3D/2010_hackathon/li_yun/ITK-V3D-Plugins/Source/BinaryLogic /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/BinaryLogic /home/liyun/V3D/2010_hackathon/li_yun/ITK-Plugin-Build/Source/BinaryLogic/CMakeFiles/NOT.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Source/BinaryLogic/CMakeFiles/NOT.dir/depend

