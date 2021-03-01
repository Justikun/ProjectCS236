//
// Created by justi on 2/25/2021.
//

#ifndef PROJECT1_RULE_H
#define PROJECT1_RULE_H
#include "Predicate.h"


class Rule {
private:
    Predicate headPredicate;
    std::vector<Predicate> bodyPredicates;
public:
    std::string ToString();
};


#endif //PROJECT1_RULE_H
