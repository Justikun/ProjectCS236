cmake_minimum_required(VERSION 3.17)
project(project1)

set(CMAKE_CXX_STANDARD 20)

add_executable(project1 main.cpp Lexer.cpp Lexer.h Token.cpp Token.h Automata/Automaton.cpp Automata/Automaton.h Automata/MatcherAutomaton.cpp Automata/MatcherAutomaton.h "Automata/NewLineAutomaton.cpp" "Automata/NewLineAutomaton.h" "Automata/CommentAutomaton.cpp" "Automata/CommentAutomaton.h" Automata/EndOfFileAutomaton.cpp Automata/EndOfFileAutomaton.h Automata/StringAutomaton.cpp Automata/StringAutomaton.h Automata/BlockCommentAutomaton.cpp Automata/BlockCommentAutomaton.h Automata/IDAutomaton.cpp Automata/IDAutomaton.h Automata/UndefinedAutomata.cpp Automata/UndefinedAutomata.h)