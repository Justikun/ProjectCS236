//
// Created by justi on 1/30/2021.
//

#include "StringAutomaton.h"

#include <iostream>

StringAutomaton::StringAutomaton(std::string toMatch, TokenType tokenType) : Automaton(tokenType) {
    this->toMatch = toMatch;
}

enum StringStates {
    BEGIN, NEUTRAL, ACCEPT, REJECT
};



int StringAutomaton::Start(const std::string &input) {
    StringStates currentState = BEGIN;
    newLines = 0;
    inputRead = 0;

    while (true) {
        switch (currentState) {
            case BEGIN:
                if (input.at(inputRead) == '\'') {
                    if (inputRead+1 >= input.size()) {
                        //END OF FILE
                        currentState = REJECT;
                    } else {
                        currentState = NEUTRAL;
                    }
                } else {
                    currentState = REJECT;
                }
                inputRead++;
                break;
            case NEUTRAL:
                //if EOF
                if (inputRead+1 > input.size()){
                    currentState = REJECT;
                } else {
                    if (input.at(inputRead) == '\n') {
                        newLines++;
                        currentState = NEUTRAL;
                    } else if (input.at(inputRead) == '\'') {
                        currentState = ACCEPT;
                    } else {
                        currentState = NEUTRAL;
                    }
                    inputRead++;
                }
                break;
            case ACCEPT:
                if (inputRead+1 >= input.size()) {
                    return inputRead;
                }
                else {
                    if (input.at(inputRead) != '\'') {
                        return inputRead;
                    } else {
                        currentState = NEUTRAL;
                    }
                }
                inputRead++;
                break;
            case REJECT:
                return 0;
                break;
            default:
                std::cout << "Error! Invalid State Detected.\n";
                break;
        }
    }
    return 0;
}


//void neutralState() {
//    newLines = 0;
//    inputRead = 0;
//
//    for (size_t i = 0; i < (int)toMatch.size() && isMatch; i++) {
//        if (input[i] != toMatch[i]) {
//            isMatch = false;
//        }
//    }
//}
//
//void acceptState() {
//
//}
//
//void rejectState() {
//
//}