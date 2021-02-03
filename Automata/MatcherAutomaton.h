//
// Created by justi on 1/28/2021.
//

#ifndef PROJECT1_MATCHERAUTOMATON_H
#define PROJECT1_MATCHERAUTOMATON_H

#include "Automaton.h"

class MatcherAutomaton : public Automaton {
private:
    std::string toMatch;

public:
    MatcherAutomaton(std::string toMatch, TokenType tokenType);

    int Start(const std::string& input) override;
};


#endif //PROJECT1_MATCHERAUTOMATON_H
