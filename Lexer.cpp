//
// Created by justi on 1/27/2021.
//

#include "Lexer.h"
#include <iostream>
#include "Parser.h"

#include "MatcherAutomaton.h"
#include "NewLineAutomaton.h"
#include "CommentAutomaton.h"
#include "EndOfFileAutomaton.h"
#include "StringAutomaton.h"
#include "BlockCommentAutomaton.h"
#include "IDAutomaton.h"
#include "UndefinedAutomata.h"

Lexer::Lexer() {
    automata.push_back(new EndOfFileAutomaton(END_OF_FILE));
    automata.push_back(new MatcherAutomaton(",", COMMA));
    automata.push_back(new MatcherAutomaton(".", PERIOD));
    automata.push_back(new MatcherAutomaton("?", Q_MARK));
    automata.push_back(new MatcherAutomaton("(", LEFT_PAREN));
    automata.push_back(new MatcherAutomaton(")", RIGHT_PAREN));
    automata.push_back(new MatcherAutomaton(":", COLON));
    automata.push_back(new MatcherAutomaton(":-", COLON_DASH));
    automata.push_back(new MatcherAutomaton("*", MULTIPLY));
    automata.push_back(new MatcherAutomaton("+", ADD));
    automata.push_back(new MatcherAutomaton("Schemes", SCHEMES));
    automata.push_back(new MatcherAutomaton("Facts", FACTS));
    automata.push_back(new MatcherAutomaton("Rules", RULES));
    automata.push_back(new MatcherAutomaton("Queries", QUERIES));
    automata.push_back(new BlockCommentAutomaton("#|",COMMENT));
    automata.push_back(new CommentAutomaton("#",COMMENT));
    automata.push_back(new StringAutomaton("\'", STRING));
    automata.push_back(new IDAutomaton(ID));
    automata.push_back(new NewLineAutomaton("\n", NEW_LINE));
}

Lexer::~Lexer() = default;

void Lexer::Run(std::string& inputString) {
    int lineNumber = 1;
    //while there are more characters to tokenize
    while (!inputString.empty()) {
        int maxRead = 0;
        Automaton *maxAutomaton = automata.at(0);

        //handle-ing whitespace between tokens
        while (inputString.at(0) == ' ' || inputString.at(0) == '\t') {
            inputString = inputString.substr(1,inputString.size());
        }

        //"Parallel" part of the algorithm
        //Each automaton runs with the same input
        int inputRead = 0;

        for (auto automaton : automata) {
            inputRead = automaton->Start(inputString);

            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = automaton;
            }
        }

        //"Max" part of the algorithm
        if (maxRead > 0) {
            //creates new token
            Token *newToken = maxAutomaton->CreateToken(inputString.substr(0, maxRead), lineNumber);
            if (newToken->GetTokenType() == COMMENT) {
                //don't pushback newToken
            } else if (newToken->GetTokenType() != NEW_LINE) {
                //adds token to out tokens vector
                tokens.push_back(newToken);
                lineNumber += maxAutomaton->NewLinesRead();
            } else {
                lineNumber += maxAutomaton->NewLinesRead();
            }
        }
            //No automaton accepted input; create invalid token
        else {
            Automaton *automaton = new UndefinedAutomata(UNDEFINED);
            maxRead = automaton->Start(inputString);
                Token *newToken = automaton->CreateToken(inputString.substr(0,maxRead),lineNumber);
                lineNumber += automaton->NewLinesRead();
                tokens.push_back(newToken);
        }
        inputString = inputString.substr(maxRead, inputString.size() - 1);
    }
    Automaton *automaton = new EndOfFileAutomaton(END_OF_FILE);
    Token *newToken = automaton->CreateToken("", lineNumber);
    tokens.push_back(newToken);
}

void Lexer::printTokens() {
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

    for(size_t i=0;i<tokens.size();i++) {
        std::cout << "(" << tokenTypeMap.at(tokens.at(i)->GetTokenType()) << ",\"" << tokens.at(i)->GetInput() << "\"," << tokens.at(i)->GetLineNumber() << ")";
        if (i < tokens.size()) {
            std::cout << '\n';
        }
    }
}

void Lexer::printTokensSize() {
    std::cout << "Total Tokens = " << tokens.size();
}

void Lexer::copyToOutPut() {
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

    std::ofstream myfile("myOutputFile.txt");
    if (!myfile.is_open()) {
        std::cout << "ERROR opening file" << std::endl;
    } else {
        for(size_t i=0;i<tokens.size();i++) {
            myfile << "(" << tokenTypeMap.at(tokens.at(i)->GetTokenType()) << ",\"" << tokens.at(i)->GetInput() << "\"," << tokens.at(i)->GetLineNumber() << ")";
            if (i < tokens.size()) {
                myfile << '\n';
            }
        }
        myfile << "Total Tokens = " << tokens.size();
        myfile.close();
    }
}

std::vector<Token*> Lexer::getTokensVector() {
    return tokens;
}

