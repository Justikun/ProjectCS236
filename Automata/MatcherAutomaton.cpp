//
// Created by justi on 1/28/2021.
//

#include "MatcherAutomaton.h"



MatcherAutomaton::MatcherAutomaton(std::string toMatch, TokenType tokenType) : Automaton(tokenType) {
    this->toMatch = toMatch;
}

int MatcherAutomaton::Start(const std::string &input) {
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
    }
    return inputRead;
}