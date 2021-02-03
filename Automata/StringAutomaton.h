//
// Created by justi on 1/30/2021.
//

#ifndef PROJECT1_STRINGAUTOMATON_H
#define PROJECT1_STRINGAUTOMATON_H

#include "Automaton.h"

class StringAutomaton : public Automaton {

private:
    std::string toMatch;

public:

    StringAutomaton(std::string toMatch, TokenType tokenType);
    int Start(const std::string& input) override;


};


#endif //PROJECT1_STRINGAUTOMATON_H
