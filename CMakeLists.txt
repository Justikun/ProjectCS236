cmake_minimum_required(VERSION 3.10.2)
project(project1)

set(CMAKE_CXX_STANDARD 11)

add_executable(project1 main.cpp Lexer.cpp Lexer.h Token.cpp Token.h Automaton.cpp Automaton.h MatcherAutomaton.cpp MatcherAutomaton.h "NewLineAutomaton.cpp" "NewLineAutomaton.h" "CommentAutomaton.cpp" "CommentAutomaton.h" EndOfFileAutomaton.cpp EndOfFileAutomaton.h StringAutomaton.cpp StringAutomaton.h BlockCommentAutomaton.cpp BlockCommentAutomaton.h IDAutomaton.cpp IDAutomaton.h UndefinedAutomata.cpp UndefinedAutomata.h)