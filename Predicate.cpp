//
// Created by justi on 2/25/2021.
//

#include "Predicate.h"

void Predicate::SetPredicateName(std::string predicateName) {
    this->predicateName = predicateName;
}

std::string Predicate::GetName() {
    return this->predicateName;
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
        std::cout << predicateParameters.at(i)->ToString();

        if (predicateParameters.size() != i+1) {
            std::cout << ",";
        }
    }

    std::cout << ")";
}

std::vector<Parameter *> Predicate::GetParameters() {
    return predicateParameters;
}
