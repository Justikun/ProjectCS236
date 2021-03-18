//
// Created by justi on 1/27/2021.
//

#ifndef PROJECT1_TOKEN_H
#define PROJECT1_TOKEN_H
#include <string>
#include <map>
#include <iostream>

enum TokenType {COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING, COMMENT, UNDEFINED, END_OF_FILE, NEW_LINE};



class Token {
    protected:
        TokenType type;
        std::string input;
        int lineNumber;

    public:
        Token(TokenType type, std::string input, int lineNumber);
        ~Token();
        TokenType GetTokenTypeNumber();

        std::string GetTokenTypeName();
        std::string GetInput();
        std::string GetLineNumber();
        void PrintTokenAsString();
};


#endif //PROJECT1_TOKEN_H
