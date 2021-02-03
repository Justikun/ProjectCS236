//
// Created by justi on 1/27/2021.
//

#include "Token.h"

Token::Token(TokenType type, std::string input, int lineNumber) {
    this->type = type;
    this->input = input;
    this->lineNumber = lineNumber;
}

Token::~Token() {

}

TokenType Token::GetTokenType() {
    return type;
}

std::string Token::GetInput() {
    return input;
}

std::string Token::GetLineNumber() {
    return std::to_string(lineNumber);
}
