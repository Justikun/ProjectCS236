//
// Created by justi on 1/30/2021.
//

#include "EndOfFileAutomaton.h"
#include <iostream>

EndOfFileAutomaton::EndOfFileAutomaton(TokenType tokenType) : Automaton(tokenType) {

}

EndOfFileAutomaton::~EndOfFileAutomaton() = default;

int EndOfFileAutomaton::Start(const std::string &input) {

    return 0;
}
