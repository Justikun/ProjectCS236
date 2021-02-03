//
// Created by justi on 1/27/2021.
//

#ifndef PROJECT1_LEXER_H
#define PROJECT1_LEXER_H

#include <string>
#include <vector>
#include <fstream>

#include "Token.h"
#include "Automata/Automaton.h"

class Lexer {
    private:
        std::vector<Token*> tokens;
        std::vector<Automaton*> automata;

    public:
        Lexer();
        ~Lexer();

        void Run(std::string& input);
        void printTokens();
        void printTokensSize();
        void copyToOutPut();
        //changes have been made here
        //changs here
        
};


#endif //PROJECT1_LEXER_H
