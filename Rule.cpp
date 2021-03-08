//
// Created by justi on 2/25/2021.
//

#include "Rule.h"

Rule::Rule() {
    bodyPredicates = {};
}

void Rule::AddHeadPredicate(Predicate *headPredicate) {
    this->headPredicate = headPredicate;
}

void Rule::AddBodyPredicate(Predicate *bodyPredicate) {
    bodyPredicates.push_back(bodyPredicate);
}

void Rule::ToString() {
    headPredicate->ToString();
    std::cout << ") :- ";
    std::cout << bodyPredicates.size();
    for (int i=0; i<bodyPredicates.size();i++) {
        std::cout << "HERE" << std::endl;
        bodyPredicates.at(i)->ToString();
    }
}
