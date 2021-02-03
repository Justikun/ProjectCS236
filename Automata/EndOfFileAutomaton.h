//
// Created by justi on 1/30/2021.
//

#ifndef PROJECT1_ENDOFFILEAUTOMATON_H
#define PROJECT1_ENDOFFILEAUTOMATON_H

#include "Automaton.h"

class EndOfFileAutomaton : public Automaton{

public:
    EndOfFileAutomaton(TokenType tokenType);
    int Start(const std::string &input) override;
    ~EndOfFileAutomaton();
};


#endif //PROJECT1_ENDOFFILEAUTOMATON_H
