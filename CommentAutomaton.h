//
// Created by justi on 1/30/2021.
//

#ifndef PROJECT1_COMMENTAUTOMATON_H
#define PROJECT1_COMMENTAUTOMATON_H

#include "Automaton.h"

class CommentAutomaton : public Automaton {
private:
    std::string toMatch;

public:
    CommentAutomaton(std::string toMatch, TokenType tokenType);
    ~CommentAutomaton();

    int Start(const std::string& input) override;
    Token * CreateToken(std::string input, int lineNumber) override;
};


#endif //PROJECT1_COMMENTAUTOMATON_H
