# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/wc/Downloads/clion-2018.3.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/wc/Downloads/clion-2018.3.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wc/CLionProjects/QG-Server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wc/CLionProjects/QG-Server/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/QG_Server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/QG_Server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/QG_Server.dir/flags.make

CMakeFiles/QG_Server.dir/src/core/http_parser.cc.o: CMakeFiles/QG_Server.dir/flags.make
CMakeFiles/QG_Server.dir/src/core/http_parser.cc.o: ../src/core/http_parser.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wc/CLionProjects/QG-Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/QG_Server.dir/src/core/http_parser.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QG_Server.dir/src/core/http_parser.cc.o -c /home/wc/CLionProjects/QG-Server/src/core/http_parser.cc

CMakeFiles/QG_Server.dir/src/core/http_parser.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QG_Server.dir/src/core/http_parser.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wc/CLionProjects/QG-Server/src/core/http_parser.cc > CMakeFiles/QG_Server.dir/src/core/http_parser.cc.i

CMakeFiles/QG_Server.dir/src/core/http_parser.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QG_Server.dir/src/core/http_parser.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wc/CLionProjects/QG-Server/src/core/http_parser.cc -o CMakeFiles/QG_Server.dir/src/core/http_parser.cc.s

CMakeFiles/QG_Server.dir/src/core/http_data.cc.o: CMakeFiles/QG_Server.dir/flags.make
CMakeFiles/QG_Server.dir/src/core/http_data.cc.o: ../src/core/http_data.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wc/CLionProjects/QG-Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/QG_Server.dir/src/core/http_data.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QG_Server.dir/src/core/http_data.cc.o -c /home/wc/CLionProjects/QG-Server/src/core/http_data.cc

CMakeFiles/QG_Server.dir/src/core/http_data.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QG_Server.dir/src/core/http_data.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wc/CLionProjects/QG-Server/src/core/http_data.cc > CMakeFiles/QG_Server.dir/src/core/http_data.cc.i

CMakeFiles/QG_Server.dir/src/core/http_data.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QG_Server.dir/src/core/http_data.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wc/CLionProjects/QG-Server/src/core/http_data.cc -o CMakeFiles/QG_Server.dir/src/core/http_data.cc.s

CMakeFiles/QG_Server.dir/src/test/test_http_paser.cc.o: CMakeFiles/QG_Server.dir/flags.make
CMakeFiles/QG_Server.dir/src/test/test_http_paser.cc.o: ../src/test/test_http_paser.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wc/CLionProjects/QG-Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/QG_Server.dir/src/test/test_http_paser.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QG_Server.dir/src/test/test_http_paser.cc.o -c /home/wc/CLionProjects/QG-Server/src/test/test_http_paser.cc

CMakeFiles/QG_Server.dir/src/test/test_http_paser.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QG_Server.dir/src/test/test_http_paser.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wc/CLionProjects/QG-Server/src/test/test_http_paser.cc > CMakeFiles/QG_Server.dir/src/test/test_http_paser.cc.i

CMakeFiles/QG_Server.dir/src/test/test_http_paser.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QG_Server.dir/src/test/test_http_paser.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wc/CLionProjects/QG-Server/src/test/test_http_paser.cc -o CMakeFiles/QG_Server.dir/src/test/test_http_paser.cc.s

CMakeFiles/QG_Server.dir/src/core/event_loop.cpp.o: CMakeFiles/QG_Server.dir/flags.make
CMakeFiles/QG_Server.dir/src/core/event_loop.cpp.o: ../src/core/event_loop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wc/CLionProjects/QG-Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/QG_Server.dir/src/core/event_loop.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QG_Server.dir/src/core/event_loop.cpp.o -c /home/wc/CLionProjects/QG-Server/src/core/event_loop.cpp

CMakeFiles/QG_Server.dir/src/core/event_loop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QG_Server.dir/src/core/event_loop.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wc/CLionProjects/QG-Server/src/core/event_loop.cpp > CMakeFiles/QG_Server.dir/src/core/event_loop.cpp.i

CMakeFiles/QG_Server.dir/src/core/event_loop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QG_Server.dir/src/core/event_loop.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wc/CLionProjects/QG-Server/src/core/event_loop.cpp -o CMakeFiles/QG_Server.dir/src/core/event_loop.cpp.s

CMakeFiles/QG_Server.dir/src/core/reactor.cpp.o: CMakeFiles/QG_Server.dir/flags.make
CMakeFiles/QG_Server.dir/src/core/reactor.cpp.o: ../src/core/reactor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wc/CLionProjects/QG-Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/QG_Server.dir/src/core/reactor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QG_Server.dir/src/core/reactor.cpp.o -c /home/wc/CLionProjects/QG-Server/src/core/reactor.cpp

CMakeFiles/QG_Server.dir/src/core/reactor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QG_Server.dir/src/core/reactor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wc/CLionProjects/QG-Server/src/core/reactor.cpp > CMakeFiles/QG_Server.dir/src/core/reactor.cpp.i

CMakeFiles/QG_Server.dir/src/core/reactor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QG_Server.dir/src/core/reactor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wc/CLionProjects/QG-Server/src/core/reactor.cpp -o CMakeFiles/QG_Server.dir/src/core/reactor.cpp.s

CMakeFiles/QG_Server.dir/src/core/sync_event_demultiplexer.cpp.o: CMakeFiles/QG_Server.dir/flags.make
CMakeFiles/QG_Server.dir/src/core/sync_event_demultiplexer.cpp.o: ../src/core/sync_event_demultiplexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wc/CLionProjects/QG-Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/QG_Server.dir/src/core/sync_event_demultiplexer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QG_Server.dir/src/core/sync_event_demultiplexer.cpp.o -c /home/wc/CLionProjects/QG-Server/src/core/sync_event_demultiplexer.cpp

CMakeFiles/QG_Server.dir/src/core/sync_event_demultiplexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QG_Server.dir/src/core/sync_event_demultiplexer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wc/CLionProjects/QG-Server/src/core/sync_event_demultiplexer.cpp > CMakeFiles/QG_Server.dir/src/core/sync_event_demultiplexer.cpp.i

CMakeFiles/QG_Server.dir/src/core/sync_event_demultiplexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QG_Server.dir/src/core/sync_event_demultiplexer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wc/CLionProjects/QG-Server/src/core/sync_event_demultiplexer.cpp -o CMakeFiles/QG_Server.dir/src/core/sync_event_demultiplexer.cpp.s

# Object files for target QG_Server
QG_Server_OBJECTS = \
"CMakeFiles/QG_Server.dir/src/core/http_parser.cc.o" \
"CMakeFiles/QG_Server.dir/src/core/http_data.cc.o" \
"CMakeFiles/QG_Server.dir/src/test/test_http_paser.cc.o" \
"CMakeFiles/QG_Server.dir/src/core/event_loop.cpp.o" \
"CMakeFiles/QG_Server.dir/src/core/reactor.cpp.o" \
"CMakeFiles/QG_Server.dir/src/core/sync_event_demultiplexer.cpp.o"

# External object files for target QG_Server
QG_Server_EXTERNAL_OBJECTS =

QG_Server: CMakeFiles/QG_Server.dir/src/core/http_parser.cc.o
QG_Server: CMakeFiles/QG_Server.dir/src/core/http_data.cc.o
QG_Server: CMakeFiles/QG_Server.dir/src/test/test_http_paser.cc.o
QG_Server: CMakeFiles/QG_Server.dir/src/core/event_loop.cpp.o
QG_Server: CMakeFiles/QG_Server.dir/src/core/reactor.cpp.o
QG_Server: CMakeFiles/QG_Server.dir/src/core/sync_event_demultiplexer.cpp.o
QG_Server: CMakeFiles/QG_Server.dir/build.make
QG_Server: CMakeFiles/QG_Server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wc/CLionProjects/QG-Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable QG_Server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/QG_Server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/QG_Server.dir/build: QG_Server

.PHONY : CMakeFiles/QG_Server.dir/build

CMakeFiles/QG_Server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/QG_Server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/QG_Server.dir/clean

CMakeFiles/QG_Server.dir/depend:
	cd /home/wc/CLionProjects/QG-Server/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wc/CLionProjects/QG-Server /home/wc/CLionProjects/QG-Server /home/wc/CLionProjects/QG-Server/cmake-build-debug /home/wc/CLionProjects/QG-Server/cmake-build-debug /home/wc/CLionProjects/QG-Server/cmake-build-debug/CMakeFiles/QG_Server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/QG_Server.dir/depend

