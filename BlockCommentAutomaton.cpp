//
// Created by justi on 2/1/2021.
//

#include "BlockCommentAutomaton.h"

#include <iostream>
#include <vector>

BlockCommentAutomaton::BlockCommentAutomaton(std::string toMatch, TokenType tokenType) : Automaton(tokenType) {
    this->toMatch = toMatch;
}

enum CommentStates {
    BEGIN, OPEN_POUND, OPEN_LINE, CLOSING_LINE, ACCEPT, REJECT

};

int BlockCommentAutomaton::Start(const std::string &input) {
    CommentStates currentState = BEGIN;
    newLines = 0;
    inputRead = 0;

    while(true) {
        switch (currentState) {
            case BEGIN:
                //if EOF -> REJECT
                if (inputRead+1 >= input.size()) {
                    currentState = REJECT;
                    break;
                }

                //if anything but #
                if (input.at(inputRead) != toMatch[0]) {
                    currentState = REJECT;
                } else {
                    currentState = OPEN_POUND;
                    inputRead++;
                }
                break;
            case OPEN_POUND:
                //if EOF -> REJECT
                if (inputRead+1 >= input.size()) {
                    currentState = REJECT;
                    break;
                }

                //if anything but |
                if (input.at(inputRead) != toMatch[1]) {
                    currentState = REJECT;
                } else {
                    currentState = OPEN_LINE;
                    inputRead++;
                }
                break;
            case OPEN_LINE:

                //if EOF -> REJECT;
                if (inputRead+1 >= input.size()) {
                    currentState = REJECT;
                    break;
                }

                //if | -> CLOSING_LINE
                if (input.at(inputRead) == toMatch[1]) {
                    currentState = CLOSING_LINE;
                }
                if (input.at(inputRead) == '\n') {
                    newLines++;
                }
                inputRead++;
                break;
            case CLOSING_LINE:
                //if anything other than #
                if (input.at(inputRead) != toMatch[0]) {
                    if (input.at(inputRead) == '\n') {
                        newLines++;
                    }
                    currentState = OPEN_LINE;
                } else {
                    currentState = ACCEPT;
                }

                inputRead++;
                break;
            case ACCEPT:
                return inputRead;
            case REJECT:
                return 0;
            default:
                std::cout << "Error! Invalid State Detected.\n";
                break;
        }
    }


    return 0;
}