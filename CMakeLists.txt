cmake_minimum_required(VERSION 3.10.2)
project(project1)

set(CMAKE_CXX_STANDARD 11)

add_executable(project1 main.cpp Lexer.cpp Lexer.h Token.cpp Token.h Automaton.cpp Automaton.h MatcherAutomaton.cpp MatcherAutomaton.h "NewLineAutomaton.cpp" "NewLineAutomaton.h" "CommentAutomaton.cpp" "CommentAutomaton.h" EndOfFileAutomaton.cpp EndOfFileAutomaton.h StringAutomaton.cpp StringAutomaton.h BlockCommentAutomaton.cpp BlockCommentAutomaton.h IDAutomaton.cpp IDAutomaton.h UndefinedAutomata.cpp UndefinedAutomata.h Parser.cpp Parser.h DatalogProgram.cpp DatalogProgram.h PlainParameter.cpp PlainParameter.h Predicate.cpp Predicate.h Rule.cpp Rule.h Expression.cpp Expression.h Parameter.cpp Parameter.h Tuple.cpp Tuple.h Header.cpp Header.h Relation.cpp Relation.h Database.cpp Database.h Interpreter.cpp Interpreter.h)