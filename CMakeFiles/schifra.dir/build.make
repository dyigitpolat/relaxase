# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /opt/cmake-3.18.4-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.18.4-Linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ayan/relaxase

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ayan/relaxase

# Utility rule file for schifra.

# Include the progress variables for this target.
include CMakeFiles/schifra.dir/progress.make

CMakeFiles/schifra: CMakeFiles/schifra-complete


CMakeFiles/schifra-complete: schifra/src/schifra-stamp/schifra-install
CMakeFiles/schifra-complete: schifra/src/schifra-stamp/schifra-mkdir
CMakeFiles/schifra-complete: schifra/src/schifra-stamp/schifra-download
CMakeFiles/schifra-complete: schifra/src/schifra-stamp/schifra-update
CMakeFiles/schifra-complete: schifra/src/schifra-stamp/schifra-patch
CMakeFiles/schifra-complete: schifra/src/schifra-stamp/schifra-configure
CMakeFiles/schifra-complete: schifra/src/schifra-stamp/schifra-build
CMakeFiles/schifra-complete: schifra/src/schifra-stamp/schifra-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ayan/relaxase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'schifra'"
	/opt/cmake-3.18.4-Linux-x86_64/bin/cmake -E make_directory /home/ayan/relaxase/CMakeFiles
	/opt/cmake-3.18.4-Linux-x86_64/bin/cmake -E touch /home/ayan/relaxase/CMakeFiles/schifra-complete
	/opt/cmake-3.18.4-Linux-x86_64/bin/cmake -E touch /home/ayan/relaxase/schifra/src/schifra-stamp/schifra-done

schifra/src/schifra-stamp/schifra-install: schifra/src/schifra-stamp/schifra-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ayan/relaxase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Performing install step for 'schifra'"
	cd /home/ayan/relaxase/schifra/src/schifra-build && make install PREFIX=/home/ayan/relaxase/schifra
	cd /home/ayan/relaxase/schifra/src/schifra-build && /opt/cmake-3.18.4-Linux-x86_64/bin/cmake -E touch /home/ayan/relaxase/schifra/src/schifra-stamp/schifra-install

schifra/src/schifra-stamp/schifra-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ayan/relaxase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Creating directories for 'schifra'"
	/opt/cmake-3.18.4-Linux-x86_64/bin/cmake -E make_directory /home/ayan/relaxase/schifra/src/schifra
	/opt/cmake-3.18.4-Linux-x86_64/bin/cmake -E make_directory /home/ayan/relaxase/schifra/src/schifra-build
	/opt/cmake-3.18.4-Linux-x86_64/bin/cmake -E make_directory /home/ayan/relaxase/schifra
	/opt/cmake-3.18.4-Linux-x86_64/bin/cmake -E make_directory /home/ayan/relaxase/schifra/tmp
	/opt/cmake-3.18.4-Linux-x86_64/bin/cmake -E make_directory /home/ayan/relaxase/schifra/src/schifra-stamp
	/opt/cmake-3.18.4-Linux-x86_64/bin/cmake -E make_directory /home/ayan/relaxase/schifra/src
	/opt/cmake-3.18.4-Linux-x86_64/bin/cmake -E make_directory /home/ayan/relaxase/schifra/src/schifra-stamp
	/opt/cmake-3.18.4-Linux-x86_64/bin/cmake -E touch /home/ayan/relaxase/schifra/src/schifra-stamp/schifra-mkdir

schifra/src/schifra-stamp/schifra-download: schifra/src/schifra-stamp/schifra-urlinfo.txt
schifra/src/schifra-stamp/schifra-download: schifra/src/schifra-stamp/schifra-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ayan/relaxase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (download, verify and extract) for 'schifra'"
	cd /home/ayan/relaxase/schifra/src && /opt/cmake-3.18.4-Linux-x86_64/bin/cmake -P /home/ayan/relaxase/schifra/src/schifra-stamp/download-schifra.cmake
	cd /home/ayan/relaxase/schifra/src && /opt/cmake-3.18.4-Linux-x86_64/bin/cmake -P /home/ayan/relaxase/schifra/src/schifra-stamp/verify-schifra.cmake
	cd /home/ayan/relaxase/schifra/src && /opt/cmake-3.18.4-Linux-x86_64/bin/cmake -P /home/ayan/relaxase/schifra/src/schifra-stamp/extract-schifra.cmake
	cd /home/ayan/relaxase/schifra/src && /opt/cmake-3.18.4-Linux-x86_64/bin/cmake -E touch /home/ayan/relaxase/schifra/src/schifra-stamp/schifra-download

schifra/src/schifra-stamp/schifra-update: schifra/src/schifra-stamp/schifra-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ayan/relaxase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No update step for 'schifra'"
	/opt/cmake-3.18.4-Linux-x86_64/bin/cmake -E echo_append
	/opt/cmake-3.18.4-Linux-x86_64/bin/cmake -E touch /home/ayan/relaxase/schifra/src/schifra-stamp/schifra-update

schifra/src/schifra-stamp/schifra-patch: schifra/src/schifra-stamp/schifra-update
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ayan/relaxase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "No patch step for 'schifra'"
	/opt/cmake-3.18.4-Linux-x86_64/bin/cmake -E echo_append
	/opt/cmake-3.18.4-Linux-x86_64/bin/cmake -E touch /home/ayan/relaxase/schifra/src/schifra-stamp/schifra-patch

schifra/src/schifra-stamp/schifra-configure: schifra/tmp/schifra-cfgcmd.txt
schifra/src/schifra-stamp/schifra-configure: schifra/src/schifra-stamp/schifra-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ayan/relaxase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No configure step for 'schifra'"
	cd /home/ayan/relaxase/schifra/src/schifra-build && /opt/cmake-3.18.4-Linux-x86_64/bin/cmake -E echo_append
	cd /home/ayan/relaxase/schifra/src/schifra-build && /opt/cmake-3.18.4-Linux-x86_64/bin/cmake -E touch /home/ayan/relaxase/schifra/src/schifra-stamp/schifra-configure

schifra/src/schifra-stamp/schifra-build: schifra/src/schifra-stamp/schifra-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ayan/relaxase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Performing build step for 'schifra'"
	cd /home/ayan/relaxase/schifra/src/schifra-build && make
	cd /home/ayan/relaxase/schifra/src/schifra-build && /opt/cmake-3.18.4-Linux-x86_64/bin/cmake -E touch /home/ayan/relaxase/schifra/src/schifra-stamp/schifra-build

schifra: CMakeFiles/schifra
schifra: CMakeFiles/schifra-complete
schifra: schifra/src/schifra-stamp/schifra-install
schifra: schifra/src/schifra-stamp/schifra-mkdir
schifra: schifra/src/schifra-stamp/schifra-download
schifra: schifra/src/schifra-stamp/schifra-update
schifra: schifra/src/schifra-stamp/schifra-patch
schifra: schifra/src/schifra-stamp/schifra-configure
schifra: schifra/src/schifra-stamp/schifra-build
schifra: CMakeFiles/schifra.dir/build.make

.PHONY : schifra

# Rule to build all files generated by this target.
CMakeFiles/schifra.dir/build: schifra

.PHONY : CMakeFiles/schifra.dir/build

CMakeFiles/schifra.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/schifra.dir/cmake_clean.cmake
.PHONY : CMakeFiles/schifra.dir/clean

CMakeFiles/schifra.dir/depend:
	cd /home/ayan/relaxase && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ayan/relaxase /home/ayan/relaxase /home/ayan/relaxase /home/ayan/relaxase /home/ayan/relaxase/CMakeFiles/schifra.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/schifra.dir/depend

