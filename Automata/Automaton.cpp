//
// Created by justi on 1/28/2021.
//

#include "Automaton.h"

Automaton::Automaton(TokenType type) {
    this->type = type;
}

Automaton::~Automaton () {

}

int Automaton::Start(const std::string &input) {
    return 0;
}

Token *Automaton::CreateToken(std::string input, int lineNumber) {
    return new Token(type, input, lineNumber);
}

int Automaton::NewLinesRead() const {
    return newLines;
}