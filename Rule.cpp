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
    std::cout << "SIZE: " << bodyPredicates.size() << std::endl;
}


void Rule::ToString() {
    headPredicate->ToString();
    std::cout << " :- ";
    for (int i=0; i<bodyPredicates.size();i++) {
        if (i>0) {
            std::cout << ",";
        }
        bodyPredicates.at(i)->ToString();
    }
}
