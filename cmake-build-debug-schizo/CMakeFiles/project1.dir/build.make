# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /tmp/tmp.LSKQsAtbMT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.LSKQsAtbMT/cmake-build-debug-schizo

# Include any dependencies generated for this target.
include CMakeFiles/project1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/project1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project1.dir/flags.make

CMakeFiles/project1.dir/main.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.LSKQsAtbMT/cmake-build-debug-schizo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project1.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/main.cpp.o -c /tmp/tmp.LSKQsAtbMT/main.cpp

CMakeFiles/project1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.LSKQsAtbMT/main.cpp > CMakeFiles/project1.dir/main.cpp.i

CMakeFiles/project1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.LSKQsAtbMT/main.cpp -o CMakeFiles/project1.dir/main.cpp.s

CMakeFiles/project1.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/project1.dir/main.cpp.o.requires

CMakeFiles/project1.dir/main.cpp.o.provides: CMakeFiles/project1.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/project1.dir/build.make CMakeFiles/project1.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/project1.dir/main.cpp.o.provides

CMakeFiles/project1.dir/main.cpp.o.provides.build: CMakeFiles/project1.dir/main.cpp.o


CMakeFiles/project1.dir/Lexer.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/Lexer.cpp.o: ../Lexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.LSKQsAtbMT/cmake-build-debug-schizo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project1.dir/Lexer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/Lexer.cpp.o -c /tmp/tmp.LSKQsAtbMT/Lexer.cpp

CMakeFiles/project1.dir/Lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/Lexer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.LSKQsAtbMT/Lexer.cpp > CMakeFiles/project1.dir/Lexer.cpp.i

CMakeFiles/project1.dir/Lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/Lexer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.LSKQsAtbMT/Lexer.cpp -o CMakeFiles/project1.dir/Lexer.cpp.s

CMakeFiles/project1.dir/Lexer.cpp.o.requires:

.PHONY : CMakeFiles/project1.dir/Lexer.cpp.o.requires

CMakeFiles/project1.dir/Lexer.cpp.o.provides: CMakeFiles/project1.dir/Lexer.cpp.o.requires
	$(MAKE) -f CMakeFiles/project1.dir/build.make CMakeFiles/project1.dir/Lexer.cpp.o.provides.build
.PHONY : CMakeFiles/project1.dir/Lexer.cpp.o.provides

CMakeFiles/project1.dir/Lexer.cpp.o.provides.build: CMakeFiles/project1.dir/Lexer.cpp.o


CMakeFiles/project1.dir/Token.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/Token.cpp.o: ../Token.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.LSKQsAtbMT/cmake-build-debug-schizo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/project1.dir/Token.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/Token.cpp.o -c /tmp/tmp.LSKQsAtbMT/Token.cpp

CMakeFiles/project1.dir/Token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/Token.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.LSKQsAtbMT/Token.cpp > CMakeFiles/project1.dir/Token.cpp.i

CMakeFiles/project1.dir/Token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/Token.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.LSKQsAtbMT/Token.cpp -o CMakeFiles/project1.dir/Token.cpp.s

CMakeFiles/project1.dir/Token.cpp.o.requires:

.PHONY : CMakeFiles/project1.dir/Token.cpp.o.requires

CMakeFiles/project1.dir/Token.cpp.o.provides: CMakeFiles/project1.dir/Token.cpp.o.requires
	$(MAKE) -f CMakeFiles/project1.dir/build.make CMakeFiles/project1.dir/Token.cpp.o.provides.build
.PHONY : CMakeFiles/project1.dir/Token.cpp.o.provides

CMakeFiles/project1.dir/Token.cpp.o.provides.build: CMakeFiles/project1.dir/Token.cpp.o


CMakeFiles/project1.dir/Automaton.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/Automaton.cpp.o: ../Automaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.LSKQsAtbMT/cmake-build-debug-schizo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/project1.dir/Automaton.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/Automaton.cpp.o -c /tmp/tmp.LSKQsAtbMT/Automaton.cpp

CMakeFiles/project1.dir/Automaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/Automaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.LSKQsAtbMT/Automaton.cpp > CMakeFiles/project1.dir/Automaton.cpp.i

CMakeFiles/project1.dir/Automaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/Automaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.LSKQsAtbMT/Automaton.cpp -o CMakeFiles/project1.dir/Automaton.cpp.s

CMakeFiles/project1.dir/Automaton.cpp.o.requires:

.PHONY : CMakeFiles/project1.dir/Automaton.cpp.o.requires

CMakeFiles/project1.dir/Automaton.cpp.o.provides: CMakeFiles/project1.dir/Automaton.cpp.o.requires
	$(MAKE) -f CMakeFiles/project1.dir/build.make CMakeFiles/project1.dir/Automaton.cpp.o.provides.build
.PHONY : CMakeFiles/project1.dir/Automaton.cpp.o.provides

CMakeFiles/project1.dir/Automaton.cpp.o.provides.build: CMakeFiles/project1.dir/Automaton.cpp.o


CMakeFiles/project1.dir/MatcherAutomaton.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/MatcherAutomaton.cpp.o: ../MatcherAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.LSKQsAtbMT/cmake-build-debug-schizo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/project1.dir/MatcherAutomaton.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/MatcherAutomaton.cpp.o -c /tmp/tmp.LSKQsAtbMT/MatcherAutomaton.cpp

CMakeFiles/project1.dir/MatcherAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/MatcherAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.LSKQsAtbMT/MatcherAutomaton.cpp > CMakeFiles/project1.dir/MatcherAutomaton.cpp.i

CMakeFiles/project1.dir/MatcherAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/MatcherAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.LSKQsAtbMT/MatcherAutomaton.cpp -o CMakeFiles/project1.dir/MatcherAutomaton.cpp.s

CMakeFiles/project1.dir/MatcherAutomaton.cpp.o.requires:

.PHONY : CMakeFiles/project1.dir/MatcherAutomaton.cpp.o.requires

CMakeFiles/project1.dir/MatcherAutomaton.cpp.o.provides: CMakeFiles/project1.dir/MatcherAutomaton.cpp.o.requires
	$(MAKE) -f CMakeFiles/project1.dir/build.make CMakeFiles/project1.dir/MatcherAutomaton.cpp.o.provides.build
.PHONY : CMakeFiles/project1.dir/MatcherAutomaton.cpp.o.provides

CMakeFiles/project1.dir/MatcherAutomaton.cpp.o.provides.build: CMakeFiles/project1.dir/MatcherAutomaton.cpp.o


CMakeFiles/project1.dir/NewLineAutomaton.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/NewLineAutomaton.cpp.o: ../NewLineAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.LSKQsAtbMT/cmake-build-debug-schizo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/project1.dir/NewLineAutomaton.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/NewLineAutomaton.cpp.o -c /tmp/tmp.LSKQsAtbMT/NewLineAutomaton.cpp

CMakeFiles/project1.dir/NewLineAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/NewLineAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.LSKQsAtbMT/NewLineAutomaton.cpp > CMakeFiles/project1.dir/NewLineAutomaton.cpp.i

CMakeFiles/project1.dir/NewLineAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/NewLineAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.LSKQsAtbMT/NewLineAutomaton.cpp -o CMakeFiles/project1.dir/NewLineAutomaton.cpp.s

CMakeFiles/project1.dir/NewLineAutomaton.cpp.o.requires:

.PHONY : CMakeFiles/project1.dir/NewLineAutomaton.cpp.o.requires

CMakeFiles/project1.dir/NewLineAutomaton.cpp.o.provides: CMakeFiles/project1.dir/NewLineAutomaton.cpp.o.requires
	$(MAKE) -f CMakeFiles/project1.dir/build.make CMakeFiles/project1.dir/NewLineAutomaton.cpp.o.provides.build
.PHONY : CMakeFiles/project1.dir/NewLineAutomaton.cpp.o.provides

CMakeFiles/project1.dir/NewLineAutomaton.cpp.o.provides.build: CMakeFiles/project1.dir/NewLineAutomaton.cpp.o


CMakeFiles/project1.dir/CommentAutomaton.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/CommentAutomaton.cpp.o: ../CommentAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.LSKQsAtbMT/cmake-build-debug-schizo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/project1.dir/CommentAutomaton.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/CommentAutomaton.cpp.o -c /tmp/tmp.LSKQsAtbMT/CommentAutomaton.cpp

CMakeFiles/project1.dir/CommentAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/CommentAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.LSKQsAtbMT/CommentAutomaton.cpp > CMakeFiles/project1.dir/CommentAutomaton.cpp.i

CMakeFiles/project1.dir/CommentAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/CommentAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.LSKQsAtbMT/CommentAutomaton.cpp -o CMakeFiles/project1.dir/CommentAutomaton.cpp.s

CMakeFiles/project1.dir/CommentAutomaton.cpp.o.requires:

.PHONY : CMakeFiles/project1.dir/CommentAutomaton.cpp.o.requires

CMakeFiles/project1.dir/CommentAutomaton.cpp.o.provides: CMakeFiles/project1.dir/CommentAutomaton.cpp.o.requires
	$(MAKE) -f CMakeFiles/project1.dir/build.make CMakeFiles/project1.dir/CommentAutomaton.cpp.o.provides.build
.PHONY : CMakeFiles/project1.dir/CommentAutomaton.cpp.o.provides

CMakeFiles/project1.dir/CommentAutomaton.cpp.o.provides.build: CMakeFiles/project1.dir/CommentAutomaton.cpp.o


CMakeFiles/project1.dir/EndOfFileAutomaton.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/EndOfFileAutomaton.cpp.o: ../EndOfFileAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.LSKQsAtbMT/cmake-build-debug-schizo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/project1.dir/EndOfFileAutomaton.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/EndOfFileAutomaton.cpp.o -c /tmp/tmp.LSKQsAtbMT/EndOfFileAutomaton.cpp

CMakeFiles/project1.dir/EndOfFileAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/EndOfFileAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.LSKQsAtbMT/EndOfFileAutomaton.cpp > CMakeFiles/project1.dir/EndOfFileAutomaton.cpp.i

CMakeFiles/project1.dir/EndOfFileAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/EndOfFileAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.LSKQsAtbMT/EndOfFileAutomaton.cpp -o CMakeFiles/project1.dir/EndOfFileAutomaton.cpp.s

CMakeFiles/project1.dir/EndOfFileAutomaton.cpp.o.requires:

.PHONY : CMakeFiles/project1.dir/EndOfFileAutomaton.cpp.o.requires

CMakeFiles/project1.dir/EndOfFileAutomaton.cpp.o.provides: CMakeFiles/project1.dir/EndOfFileAutomaton.cpp.o.requires
	$(MAKE) -f CMakeFiles/project1.dir/build.make CMakeFiles/project1.dir/EndOfFileAutomaton.cpp.o.provides.build
.PHONY : CMakeFiles/project1.dir/EndOfFileAutomaton.cpp.o.provides

CMakeFiles/project1.dir/EndOfFileAutomaton.cpp.o.provides.build: CMakeFiles/project1.dir/EndOfFileAutomaton.cpp.o


CMakeFiles/project1.dir/StringAutomaton.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/StringAutomaton.cpp.o: ../StringAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.LSKQsAtbMT/cmake-build-debug-schizo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/project1.dir/StringAutomaton.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/StringAutomaton.cpp.o -c /tmp/tmp.LSKQsAtbMT/StringAutomaton.cpp

CMakeFiles/project1.dir/StringAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/StringAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.LSKQsAtbMT/StringAutomaton.cpp > CMakeFiles/project1.dir/StringAutomaton.cpp.i

CMakeFiles/project1.dir/StringAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/StringAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.LSKQsAtbMT/StringAutomaton.cpp -o CMakeFiles/project1.dir/StringAutomaton.cpp.s

CMakeFiles/project1.dir/StringAutomaton.cpp.o.requires:

.PHONY : CMakeFiles/project1.dir/StringAutomaton.cpp.o.requires

CMakeFiles/project1.dir/StringAutomaton.cpp.o.provides: CMakeFiles/project1.dir/StringAutomaton.cpp.o.requires
	$(MAKE) -f CMakeFiles/project1.dir/build.make CMakeFiles/project1.dir/StringAutomaton.cpp.o.provides.build
.PHONY : CMakeFiles/project1.dir/StringAutomaton.cpp.o.provides

CMakeFiles/project1.dir/StringAutomaton.cpp.o.provides.build: CMakeFiles/project1.dir/StringAutomaton.cpp.o


CMakeFiles/project1.dir/BlockCommentAutomaton.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/BlockCommentAutomaton.cpp.o: ../BlockCommentAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.LSKQsAtbMT/cmake-build-debug-schizo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/project1.dir/BlockCommentAutomaton.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/BlockCommentAutomaton.cpp.o -c /tmp/tmp.LSKQsAtbMT/BlockCommentAutomaton.cpp

CMakeFiles/project1.dir/BlockCommentAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/BlockCommentAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.LSKQsAtbMT/BlockCommentAutomaton.cpp > CMakeFiles/project1.dir/BlockCommentAutomaton.cpp.i

CMakeFiles/project1.dir/BlockCommentAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/BlockCommentAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.LSKQsAtbMT/BlockCommentAutomaton.cpp -o CMakeFiles/project1.dir/BlockCommentAutomaton.cpp.s

CMakeFiles/project1.dir/BlockCommentAutomaton.cpp.o.requires:

.PHONY : CMakeFiles/project1.dir/BlockCommentAutomaton.cpp.o.requires

CMakeFiles/project1.dir/BlockCommentAutomaton.cpp.o.provides: CMakeFiles/project1.dir/BlockCommentAutomaton.cpp.o.requires
	$(MAKE) -f CMakeFiles/project1.dir/build.make CMakeFiles/project1.dir/BlockCommentAutomaton.cpp.o.provides.build
.PHONY : CMakeFiles/project1.dir/BlockCommentAutomaton.cpp.o.provides

CMakeFiles/project1.dir/BlockCommentAutomaton.cpp.o.provides.build: CMakeFiles/project1.dir/BlockCommentAutomaton.cpp.o


CMakeFiles/project1.dir/IDAutomaton.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/IDAutomaton.cpp.o: ../IDAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.LSKQsAtbMT/cmake-build-debug-schizo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/project1.dir/IDAutomaton.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/IDAutomaton.cpp.o -c /tmp/tmp.LSKQsAtbMT/IDAutomaton.cpp

CMakeFiles/project1.dir/IDAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/IDAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.LSKQsAtbMT/IDAutomaton.cpp > CMakeFiles/project1.dir/IDAutomaton.cpp.i

CMakeFiles/project1.dir/IDAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/IDAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.LSKQsAtbMT/IDAutomaton.cpp -o CMakeFiles/project1.dir/IDAutomaton.cpp.s

CMakeFiles/project1.dir/IDAutomaton.cpp.o.requires:

.PHONY : CMakeFiles/project1.dir/IDAutomaton.cpp.o.requires

CMakeFiles/project1.dir/IDAutomaton.cpp.o.provides: CMakeFiles/project1.dir/IDAutomaton.cpp.o.requires
	$(MAKE) -f CMakeFiles/project1.dir/build.make CMakeFiles/project1.dir/IDAutomaton.cpp.o.provides.build
.PHONY : CMakeFiles/project1.dir/IDAutomaton.cpp.o.provides

CMakeFiles/project1.dir/IDAutomaton.cpp.o.provides.build: CMakeFiles/project1.dir/IDAutomaton.cpp.o


CMakeFiles/project1.dir/UndefinedAutomata.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/UndefinedAutomata.cpp.o: ../UndefinedAutomata.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.LSKQsAtbMT/cmake-build-debug-schizo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/project1.dir/UndefinedAutomata.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/UndefinedAutomata.cpp.o -c /tmp/tmp.LSKQsAtbMT/UndefinedAutomata.cpp

CMakeFiles/project1.dir/UndefinedAutomata.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/UndefinedAutomata.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.LSKQsAtbMT/UndefinedAutomata.cpp > CMakeFiles/project1.dir/UndefinedAutomata.cpp.i

CMakeFiles/project1.dir/UndefinedAutomata.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/UndefinedAutomata.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.LSKQsAtbMT/UndefinedAutomata.cpp -o CMakeFiles/project1.dir/UndefinedAutomata.cpp.s

CMakeFiles/project1.dir/UndefinedAutomata.cpp.o.requires:

.PHONY : CMakeFiles/project1.dir/UndefinedAutomata.cpp.o.requires

CMakeFiles/project1.dir/UndefinedAutomata.cpp.o.provides: CMakeFiles/project1.dir/UndefinedAutomata.cpp.o.requires
	$(MAKE) -f CMakeFiles/project1.dir/build.make CMakeFiles/project1.dir/UndefinedAutomata.cpp.o.provides.build
.PHONY : CMakeFiles/project1.dir/UndefinedAutomata.cpp.o.provides

CMakeFiles/project1.dir/UndefinedAutomata.cpp.o.provides.build: CMakeFiles/project1.dir/UndefinedAutomata.cpp.o


CMakeFiles/project1.dir/Parser.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/Parser.cpp.o: ../Parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.LSKQsAtbMT/cmake-build-debug-schizo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/project1.dir/Parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/Parser.cpp.o -c /tmp/tmp.LSKQsAtbMT/Parser.cpp

CMakeFiles/project1.dir/Parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/Parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.LSKQsAtbMT/Parser.cpp > CMakeFiles/project1.dir/Parser.cpp.i

CMakeFiles/project1.dir/Parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/Parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.LSKQsAtbMT/Parser.cpp -o CMakeFiles/project1.dir/Parser.cpp.s

CMakeFiles/project1.dir/Parser.cpp.o.requires:

.PHONY : CMakeFiles/project1.dir/Parser.cpp.o.requires

CMakeFiles/project1.dir/Parser.cpp.o.provides: CMakeFiles/project1.dir/Parser.cpp.o.requires
	$(MAKE) -f CMakeFiles/project1.dir/build.make CMakeFiles/project1.dir/Parser.cpp.o.provides.build
.PHONY : CMakeFiles/project1.dir/Parser.cpp.o.provides

CMakeFiles/project1.dir/Parser.cpp.o.provides.build: CMakeFiles/project1.dir/Parser.cpp.o


CMakeFiles/project1.dir/ParserHelper.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/ParserHelper.cpp.o: ../ParserHelper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.LSKQsAtbMT/cmake-build-debug-schizo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/project1.dir/ParserHelper.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/ParserHelper.cpp.o -c /tmp/tmp.LSKQsAtbMT/ParserHelper.cpp

CMakeFiles/project1.dir/ParserHelper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/ParserHelper.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.LSKQsAtbMT/ParserHelper.cpp > CMakeFiles/project1.dir/ParserHelper.cpp.i

CMakeFiles/project1.dir/ParserHelper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/ParserHelper.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.LSKQsAtbMT/ParserHelper.cpp -o CMakeFiles/project1.dir/ParserHelper.cpp.s

CMakeFiles/project1.dir/ParserHelper.cpp.o.requires:

.PHONY : CMakeFiles/project1.dir/ParserHelper.cpp.o.requires

CMakeFiles/project1.dir/ParserHelper.cpp.o.provides: CMakeFiles/project1.dir/ParserHelper.cpp.o.requires
	$(MAKE) -f CMakeFiles/project1.dir/build.make CMakeFiles/project1.dir/ParserHelper.cpp.o.provides.build
.PHONY : CMakeFiles/project1.dir/ParserHelper.cpp.o.provides

CMakeFiles/project1.dir/ParserHelper.cpp.o.provides.build: CMakeFiles/project1.dir/ParserHelper.cpp.o


CMakeFiles/project1.dir/DatalogProgram.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/DatalogProgram.cpp.o: ../DatalogProgram.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.LSKQsAtbMT/cmake-build-debug-schizo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/project1.dir/DatalogProgram.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/DatalogProgram.cpp.o -c /tmp/tmp.LSKQsAtbMT/DatalogProgram.cpp

CMakeFiles/project1.dir/DatalogProgram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/DatalogProgram.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.LSKQsAtbMT/DatalogProgram.cpp > CMakeFiles/project1.dir/DatalogProgram.cpp.i

CMakeFiles/project1.dir/DatalogProgram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/DatalogProgram.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.LSKQsAtbMT/DatalogProgram.cpp -o CMakeFiles/project1.dir/DatalogProgram.cpp.s

CMakeFiles/project1.dir/DatalogProgram.cpp.o.requires:

.PHONY : CMakeFiles/project1.dir/DatalogProgram.cpp.o.requires

CMakeFiles/project1.dir/DatalogProgram.cpp.o.provides: CMakeFiles/project1.dir/DatalogProgram.cpp.o.requires
	$(MAKE) -f CMakeFiles/project1.dir/build.make CMakeFiles/project1.dir/DatalogProgram.cpp.o.provides.build
.PHONY : CMakeFiles/project1.dir/DatalogProgram.cpp.o.provides

CMakeFiles/project1.dir/DatalogProgram.cpp.o.provides.build: CMakeFiles/project1.dir/DatalogProgram.cpp.o


CMakeFiles/project1.dir/Parameter.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/Parameter.cpp.o: ../Parameter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.LSKQsAtbMT/cmake-build-debug-schizo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/project1.dir/Parameter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/Parameter.cpp.o -c /tmp/tmp.LSKQsAtbMT/Parameter.cpp

CMakeFiles/project1.dir/Parameter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/Parameter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.LSKQsAtbMT/Parameter.cpp > CMakeFiles/project1.dir/Parameter.cpp.i

CMakeFiles/project1.dir/Parameter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/Parameter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.LSKQsAtbMT/Parameter.cpp -o CMakeFiles/project1.dir/Parameter.cpp.s

CMakeFiles/project1.dir/Parameter.cpp.o.requires:

.PHONY : CMakeFiles/project1.dir/Parameter.cpp.o.requires

CMakeFiles/project1.dir/Parameter.cpp.o.provides: CMakeFiles/project1.dir/Parameter.cpp.o.requires
	$(MAKE) -f CMakeFiles/project1.dir/build.make CMakeFiles/project1.dir/Parameter.cpp.o.provides.build
.PHONY : CMakeFiles/project1.dir/Parameter.cpp.o.provides

CMakeFiles/project1.dir/Parameter.cpp.o.provides.build: CMakeFiles/project1.dir/Parameter.cpp.o


CMakeFiles/project1.dir/Predicate.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/Predicate.cpp.o: ../Predicate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.LSKQsAtbMT/cmake-build-debug-schizo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/project1.dir/Predicate.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/Predicate.cpp.o -c /tmp/tmp.LSKQsAtbMT/Predicate.cpp

CMakeFiles/project1.dir/Predicate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/Predicate.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.LSKQsAtbMT/Predicate.cpp > CMakeFiles/project1.dir/Predicate.cpp.i

CMakeFiles/project1.dir/Predicate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/Predicate.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.LSKQsAtbMT/Predicate.cpp -o CMakeFiles/project1.dir/Predicate.cpp.s

CMakeFiles/project1.dir/Predicate.cpp.o.requires:

.PHONY : CMakeFiles/project1.dir/Predicate.cpp.o.requires

CMakeFiles/project1.dir/Predicate.cpp.o.provides: CMakeFiles/project1.dir/Predicate.cpp.o.requires
	$(MAKE) -f CMakeFiles/project1.dir/build.make CMakeFiles/project1.dir/Predicate.cpp.o.provides.build
.PHONY : CMakeFiles/project1.dir/Predicate.cpp.o.provides

CMakeFiles/project1.dir/Predicate.cpp.o.provides.build: CMakeFiles/project1.dir/Predicate.cpp.o


CMakeFiles/project1.dir/Rule.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/Rule.cpp.o: ../Rule.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.LSKQsAtbMT/cmake-build-debug-schizo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/project1.dir/Rule.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project1.dir/Rule.cpp.o -c /tmp/tmp.LSKQsAtbMT/Rule.cpp

CMakeFiles/project1.dir/Rule.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/Rule.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.LSKQsAtbMT/Rule.cpp > CMakeFiles/project1.dir/Rule.cpp.i

CMakeFiles/project1.dir/Rule.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/Rule.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.LSKQsAtbMT/Rule.cpp -o CMakeFiles/project1.dir/Rule.cpp.s

CMakeFiles/project1.dir/Rule.cpp.o.requires:

.PHONY : CMakeFiles/project1.dir/Rule.cpp.o.requires

CMakeFiles/project1.dir/Rule.cpp.o.provides: CMakeFiles/project1.dir/Rule.cpp.o.requires
	$(MAKE) -f CMakeFiles/project1.dir/build.make CMakeFiles/project1.dir/Rule.cpp.o.provides.build
.PHONY : CMakeFiles/project1.dir/Rule.cpp.o.provides

CMakeFiles/project1.dir/Rule.cpp.o.provides.build: CMakeFiles/project1.dir/Rule.cpp.o


# Object files for target project1
project1_OBJECTS = \
"CMakeFiles/project1.dir/main.cpp.o" \
"CMakeFiles/project1.dir/Lexer.cpp.o" \
"CMakeFiles/project1.dir/Token.cpp.o" \
"CMakeFiles/project1.dir/Automaton.cpp.o" \
"CMakeFiles/project1.dir/MatcherAutomaton.cpp.o" \
"CMakeFiles/project1.dir/NewLineAutomaton.cpp.o" \
"CMakeFiles/project1.dir/CommentAutomaton.cpp.o" \
"CMakeFiles/project1.dir/EndOfFileAutomaton.cpp.o" \
"CMakeFiles/project1.dir/StringAutomaton.cpp.o" \
"CMakeFiles/project1.dir/BlockCommentAutomaton.cpp.o" \
"CMakeFiles/project1.dir/IDAutomaton.cpp.o" \
"CMakeFiles/project1.dir/UndefinedAutomata.cpp.o" \
"CMakeFiles/project1.dir/Parser.cpp.o" \
"CMakeFiles/project1.dir/ParserHelper.cpp.o" \
"CMakeFiles/project1.dir/DatalogProgram.cpp.o" \
"CMakeFiles/project1.dir/Parameter.cpp.o" \
"CMakeFiles/project1.dir/Predicate.cpp.o" \
"CMakeFiles/project1.dir/Rule.cpp.o"

# External object files for target project1
project1_EXTERNAL_OBJECTS =

project1: CMakeFiles/project1.dir/main.cpp.o
project1: CMakeFiles/project1.dir/Lexer.cpp.o
project1: CMakeFiles/project1.dir/Token.cpp.o
project1: CMakeFiles/project1.dir/Automaton.cpp.o
project1: CMakeFiles/project1.dir/MatcherAutomaton.cpp.o
project1: CMakeFiles/project1.dir/NewLineAutomaton.cpp.o
project1: CMakeFiles/project1.dir/CommentAutomaton.cpp.o
project1: CMakeFiles/project1.dir/EndOfFileAutomaton.cpp.o
project1: CMakeFiles/project1.dir/StringAutomaton.cpp.o
project1: CMakeFiles/project1.dir/BlockCommentAutomaton.cpp.o
project1: CMakeFiles/project1.dir/IDAutomaton.cpp.o
project1: CMakeFiles/project1.dir/UndefinedAutomata.cpp.o
project1: CMakeFiles/project1.dir/Parser.cpp.o
project1: CMakeFiles/project1.dir/ParserHelper.cpp.o
project1: CMakeFiles/project1.dir/DatalogProgram.cpp.o
project1: CMakeFiles/project1.dir/Parameter.cpp.o
project1: CMakeFiles/project1.dir/Predicate.cpp.o
project1: CMakeFiles/project1.dir/Rule.cpp.o
project1: CMakeFiles/project1.dir/build.make
project1: CMakeFiles/project1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.LSKQsAtbMT/cmake-build-debug-schizo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Linking CXX executable project1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project1.dir/build: project1

.PHONY : CMakeFiles/project1.dir/build

CMakeFiles/project1.dir/requires: CMakeFiles/project1.dir/main.cpp.o.requires
CMakeFiles/project1.dir/requires: CMakeFiles/project1.dir/Lexer.cpp.o.requires
CMakeFiles/project1.dir/requires: CMakeFiles/project1.dir/Token.cpp.o.requires
CMakeFiles/project1.dir/requires: CMakeFiles/project1.dir/Automaton.cpp.o.requires
CMakeFiles/project1.dir/requires: CMakeFiles/project1.dir/MatcherAutomaton.cpp.o.requires
CMakeFiles/project1.dir/requires: CMakeFiles/project1.dir/NewLineAutomaton.cpp.o.requires
CMakeFiles/project1.dir/requires: CMakeFiles/project1.dir/CommentAutomaton.cpp.o.requires
CMakeFiles/project1.dir/requires: CMakeFiles/project1.dir/EndOfFileAutomaton.cpp.o.requires
CMakeFiles/project1.dir/requires: CMakeFiles/project1.dir/StringAutomaton.cpp.o.requires
CMakeFiles/project1.dir/requires: CMakeFiles/project1.dir/BlockCommentAutomaton.cpp.o.requires
CMakeFiles/project1.dir/requires: CMakeFiles/project1.dir/IDAutomaton.cpp.o.requires
CMakeFiles/project1.dir/requires: CMakeFiles/project1.dir/UndefinedAutomata.cpp.o.requires
CMakeFiles/project1.dir/requires: CMakeFiles/project1.dir/Parser.cpp.o.requires
CMakeFiles/project1.dir/requires: CMakeFiles/project1.dir/ParserHelper.cpp.o.requires
CMakeFiles/project1.dir/requires: CMakeFiles/project1.dir/DatalogProgram.cpp.o.requires
CMakeFiles/project1.dir/requires: CMakeFiles/project1.dir/Parameter.cpp.o.requires
CMakeFiles/project1.dir/requires: CMakeFiles/project1.dir/Predicate.cpp.o.requires
CMakeFiles/project1.dir/requires: CMakeFiles/project1.dir/Rule.cpp.o.requires

.PHONY : CMakeFiles/project1.dir/requires

CMakeFiles/project1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project1.dir/clean

CMakeFiles/project1.dir/depend:
	cd /tmp/tmp.LSKQsAtbMT/cmake-build-debug-schizo && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.LSKQsAtbMT /tmp/tmp.LSKQsAtbMT /tmp/tmp.LSKQsAtbMT/cmake-build-debug-schizo /tmp/tmp.LSKQsAtbMT/cmake-build-debug-schizo /tmp/tmp.LSKQsAtbMT/cmake-build-debug-schizo/CMakeFiles/project1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project1.dir/depend

