//
// Created by justi on 2/1/2021.
//

#include "IDAutomaton.h"

IDAutomaton::IDAutomaton(TokenType tokenType) : Automaton(tokenType) {

}

enum IDStates {
    BEGIN, NEUTRAL, ACCEPT, REJECT
};


int IDAutomaton::Start(const std::string &input) {
    inputRead = 0;
    newLines = 0;
    IDStates currentState = BEGIN;

    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string tokenIdentifier = ",.?():*+#";

    while (true) {
        switch (currentState) {
            case BEGIN:
                //if any alphabet letter -> NEUTRAL
                if (alphabet.find(input.at(inputRead)) != std::string::npos) {
                    currentState = NEUTRAL;
                } else {
                    currentState = REJECT;
                    break;
                }
                inputRead++;
                break;
            case NEUTRAL:
                //if EOF
                if (inputRead >= input.size()) {
                    currentState = ACCEPT;
                    break;
                }

                //if endl
                if (input.at(inputRead) == '\n') {
                    currentState = ACCEPT;
                    break;
                }

                //if space
                if (input.at((inputRead)) == ' '){
                    currentState = ACCEPT;
                    break;
                }

                //if any single token identifiers
                if (tokenIdentifier.find(input.at(inputRead)) != std::string::npos) {
                    currentState = ACCEPT;
                    break;
                }

//                if (alphabet.find(inputRead) != std::string::npos)


                inputRead++;
                break;
            case ACCEPT:
                return inputRead;
            case REJECT:
                return 0;
            default:
                break;
        }
    }

    return inputRead;
}