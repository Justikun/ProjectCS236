//
// Created by justi on 2/25/2021.
//

#include "Predicate.h"

Predicate::Predicate() {

}

void Predicate::AddPredicateName(std::string predicateName) {
    this->predicateName = predicateName;
}

void Predicate::AddPredicateParameter(Parameter* parameter) {
    predicateParameters.push_back(parameter);
}