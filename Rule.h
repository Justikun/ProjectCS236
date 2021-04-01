//
// Created by justi on 2/25/2021.
//

#ifndef PROJECT1_RULE_H
#define PROJECT1_RULE_H
#include <iostream>
#include "vector"
#include "Predicate.h"

class Rule {
private:
    Predicate* headPredicate;
    std::vector<Predicate*> bodyPredicates;

public:
    Rule();
    void ToString();

    //add methods
    void AddHeadPredicate(Predicate* headPredicate);
    void AddBodyPredicate(Predicate* bodyPredicate);

    //Setters

    //Getters
    Predicate* GetHeadPredicate();
    std::vector<Predicate*> GetBodyPredicates();
};


#endif //PROJECT1_RULE_H
