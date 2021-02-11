//
// Created by justi on 1/30/2021.
//

#include <iostream>

#include "CommentAutomaton.h"
#include <string>

CommentAutomaton::CommentAutomaton(std::string toMatch, TokenType tokenType) : Automaton(tokenType) {
    this->toMatch = toMatch;
}

CommentAutomaton::~CommentAutomaton() {

}
enum CommentStates {
    BEGIN, NEUTRAL, ACCEPT, REJECT
};

int CommentAutomaton::Start(const std::string &input) {
    CommentStates currentState = BEGIN;
    newLines = 0;
    inputRead = 0;

    bool poundBefore = true;

    while(true) {
        switch (currentState) {
            case BEGIN:
                if (input.at(inputRead) == toMatch[0]) {
                    currentState = NEUTRAL;
                    poundBefore = true;
                } else {
                    currentState = REJECT;
                }
                inputRead++;
                break;
            case NEUTRAL:
                //if EOF -> ACCEPT
                if(inputRead >= input.size()){
                    currentState = ACCEPT;
                    break;
                }

                //if | && poundBefore -> Reject
                if (input.at(inputRead) == '|') {
                    if (poundBefore) {
                        currentState = REJECT;
                        break;
                    }
                    //state remains (updates at the end)
                }

                //if # remains
                if (input.at(inputRead) == toMatch[0]) {
                    poundBefore = true;
                    inputRead++;
                    break;
                }

                //if endl -> ACCEPT
                if (input.at(inputRead) == '\n') {
                    currentState = ACCEPT;
                    break;
                }

                //if endl -> ACCEPT
                if (input.at(inputRead) == '\n') {
                    currentState = ACCEPT;
                }

                //if \t
                    //state remains(updates at the end);

                poundBefore = false;
                inputRead++;
                break;
            case ACCEPT:
                return inputRead;
                break;
            case REJECT:
                return 0;
        }
    }


    return inputRead;
}

Token *CommentAutomaton::CreateToken(std::string input, int lineNumber) {
//    for (size_t i=0;i<input.size();i++) {
//        if (input.at(i) == '\t') {
//            input.replace(i,i," ");
//        }
//    }
    return Automaton::CreateToken(input, lineNumber);
}
