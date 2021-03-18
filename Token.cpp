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

TokenType Token::GetTokenTypeNumber() {
    return type;
}

std::string Token::GetInput() {
    return input;
}

std::string Token::GetLineNumber() {
    return std::to_string(lineNumber);
}

void Token::PrintTokenAsString() {
    std::cout << "(" << GetTokenTypeNumber() << "," << "\"" << GetInput() << "\"," << GetLineNumber() << ")";
}

std::string Token::GetTokenTypeName() {
    std::map<TokenType,std::string> tokenTypeMap
            {
                    {COMMA,"COMMA"},
                    {PERIOD,"PERIOD"},
                    {Q_MARK,"Q_MARK"},
                    {LEFT_PAREN, "LEFT_PAREN"},
                    {RIGHT_PAREN, "RIGHT_PAREN"},
                    {COLON, "COLON"},
                    {COLON_DASH, "COLON_DASH"},
                    {MULTIPLY, "MULTIPLY"},
                    {ADD, "ADD"},
                    {SCHEMES, "SCHEMES"},
                    {FACTS, "FACTS"},
                    {RULES, "RULES"},
                    {QUERIES, "QUERIES"},
                    {NEW_LINE, "\n"},
                    {COMMENT, "COMMENT"},
                    {END_OF_FILE, "EOF"},
                    {STRING, "STRING"},
                    {ID, "ID"},
                    {UNDEFINED, "UNDEFINED"}
            };

    std::string tokenName = tokenTypeMap.at(type);

    return tokenName;
}
