//
// Created by justi on 2/25/2021.
//

#include "Predicate.h"

void Predicate::AddPredicateName(std::string predicateName) {
    this->predicateName = predicateName;
}

void Predicate::AddParameter(Parameter* parameter) {
    predicateParameters.push_back(parameter);
}

Predicate::Predicate() {

}

void Predicate::ToString() {
    //print predicate
    std::cout << predicateName << "(";
    //prints parameters
    for (int i=0;i<predicateParameters.size();i++) {
        predicateParameters.at(i)->ToString();
        if (predicateParameters.size() != i+1) {
            std::cout << ",";
        }
    }
}