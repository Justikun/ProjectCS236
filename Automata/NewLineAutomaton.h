//
// Created by justi on 1/29/2021.
//

#ifndef PROJECT1_NEWLINEAUTOMATON_H
#define PROJECT1_NEWLINEAUTOMATON_H

#include "Automaton.h"


class NewLineAutomaton : public Automaton {
private:
    std::string toMatch;
public:
    NewLineAutomaton(std::string toMatch, TokenType tokenType);
    int Start(const std::string &input) override;
};


#endif //PROJECT1_NEWLINEAUTOMATON_H
