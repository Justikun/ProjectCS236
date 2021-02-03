//
// Created by justi on 2/1/2021.
//

#ifndef PROJECT1_IDAUTOMATON_H
#define PROJECT1_IDAUTOMATON_H
#include "Automaton.h"

class IDAutomaton : public Automaton {
public:
    IDAutomaton(TokenType tokenType);

    ~IDAutomaton();

    int Start(const std::string &input) override;


#endif //PROJECT1_IDAUTOMATON_H
};