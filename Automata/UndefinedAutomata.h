//
// Created by justi on 2/1/2021.
//

#ifndef PROJECT1_UNDEFINEDAUTOMATA_H
#define PROJECT1_UNDEFINEDAUTOMATA_H
#include "Automaton.h"

class UndefinedAutomata : public Automaton {
public:
    UndefinedAutomata(TokenType tokenType);
    int Start(const std::string &input) override;
};


#endif //PROJECT1_UNDEFINEDAUTOMATA_H
