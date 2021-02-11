//
// Created by justi on 2/1/2021.
//

#ifndef PROJECT1_BLOCKCOMMENTAUTOMATON_H
#define PROJECT1_BLOCKCOMMENTAUTOMATON_H

#include "Automaton.h"

class BlockCommentAutomaton : public Automaton {
private:
    std::string toMatch;

public:
    BlockCommentAutomaton(std::string toMatch, TokenType tokenType);

    int Start(const std::string& input) override;
};


#endif //PROJECT1_COMMENTAUTOMATON_H
