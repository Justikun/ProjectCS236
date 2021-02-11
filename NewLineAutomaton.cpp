//
// Created by justi on 1/29/2021.
//

#include "NewLineAutomaton.h"

NewLineAutomaton::NewLineAutomaton(std::string toMatch, TokenType tokenType) : Automaton(tokenType) {
    this->toMatch = toMatch;
}

int NewLineAutomaton::Start(const std::string &input) {
    bool isMatch = true;
    inputRead = 0; //member variable inherited from Automation class

    //while the char is less than the match size and is a match
    for (size_t i = 0;i<toMatch.size() && isMatch;i++) {
        if (input[i] != toMatch[i]) {
            isMatch = false;
        }
    }
    if (isMatch) {
        inputRead = toMatch.size();
        newLines = 1;
    }
    return inputRead;

    return Automaton::Start(input);
}

