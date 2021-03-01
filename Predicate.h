//
// Created by justi on 2/25/2021.
//

#ifndef PROJECT1_PREDICATE_H
#define PROJECT1_PREDICATE_H

#include <iostream>
#include <vector>
#include "Parameter.h"

class Predicate {
private:
    std::string predicateName;
    std::vector<Parameter*> predicateParameters;

public:
    Predicate();
    ~Predicate();
    void AddPredicateName(std::string predicateName);
    void AddPredicateParameter(Parameter* parameter);
    std::string ToString();
};


#endif //PROJECT1_PREDICATE_H
