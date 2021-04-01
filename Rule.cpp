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
    std::cout << " :- ";
    for (unsigned int i=0; i<bodyPredicates.size();i++) {
        if (i>0) {
            std::cout << ",";
        }
        bodyPredicates.at(i)->ToString();
    }
}

Predicate *Rule::GetHeadPredicate() {
    return headPredicate;
}

std::vector<Predicate *> Rule::GetBodyPredicates() {
    return bodyPredicates;
}
