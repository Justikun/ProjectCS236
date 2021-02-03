//
// Created by justi on 1/28/2021.
//

#ifndef PROJECT1_AUTOMATON_H
#define PROJECT1_AUTOMATON_H


#include "../Token.h"

class Automaton {
protected:
        long unsigned int inputRead = 0;
        int newLines = 0;
        TokenType type;

public:
    Automaton(TokenType tokenType);
    ~Automaton();

    //Start the automaton and return the number of characters read
    // read == 0 indicates the input was rejected
    // read > 0 indicates the input was accepted
    virtual int Start(const std::string& input);
    virtual Token* CreateToken(std::string input, int lineNumber);
    virtual int NewLinesRead() const;
};


#endif //PROJECT1_AUTOMATON_H
