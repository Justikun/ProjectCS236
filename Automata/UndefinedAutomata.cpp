//
// Created by justi on 2/1/2021.
//

#include "UndefinedAutomata.h"

UndefinedAutomata::UndefinedAutomata(TokenType tokenType) : Automaton(tokenType) {

}
enum UndefinedCases {
    BEGIN, BAD_STRING, BAD_COMMENT, UNKNOWN, ACCEPT
};

int UndefinedAutomata::Start(const std::string &input) {
    newLines = 0;
    inputRead = 0;
    UndefinedCases currentState = BEGIN;

    const std::string KNOWN_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz,.?():*+'#";

    while(true) {
        switch (currentState) {
            case BEGIN:
                if (input.at(inputRead) == '\'') {  //bad string
                    currentState = BAD_STRING;
                } else if (input.at(inputRead) == '#') { //bad comment
                    currentState = BAD_COMMENT;
                } else { //unknown char
                        currentState = UNKNOWN;
                }
                inputRead++;
                break;
            case BAD_STRING:

                if (input.at(inputRead) == '\n') {
                    newLines++;
                    if (inputRead + 1 >= input.size()) {
                        currentState = ACCEPT;
                        inputRead++;
                        break;
                    }
                }

                if (inputRead + 1 >= input.size()) {
                    currentState = ACCEPT;
                    break;
                }
                    //state remains

                inputRead++;
                break;
            case BAD_COMMENT:
                if (inputRead + 1 >= input.size()) {
                    currentState = ACCEPT;
                    break;
                } else {
                    //state remains
                }
                if (input.at(inputRead) == '\n') {
                    newLines++;
                }

                inputRead++;
                break;
            case UNKNOWN:
                if (input.at(inputRead-1) == '\t') {
                    return 0;
                }
                currentState = ACCEPT;
            case ACCEPT:
                return inputRead;
            default:
                return 0;
        }
    }


    return inputRead;
}