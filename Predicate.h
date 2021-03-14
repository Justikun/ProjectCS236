//
// Created by justi on 2/25/2021.
//

#ifndef PROJECT1_PREDICATE_H
#define PROJECT1_PREDICATE_H


#include "Parameter.h"
#include <iostream>
#include <vector>

class Predicate {
private:
    std::string predicateName;
    std::vector<Parameter*> predicateParameters;

public:
    Predicate();
    void AddPredicateName(std::string predicateName);
    void AddParameter(Parameter* parameter);
    void ToString();
};


#endif //PROJECT1_PREDICATE_H
