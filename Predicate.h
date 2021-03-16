//
// Created by justi on 2/25/2021.
//

#ifndef PROJECT1_PREDICATE_H
#define PROJECT1_PREDICATE_H


#include "PlainParameter.h"
#include <iostream>
#include <vector>

class Predicate {
private:
    std::string predicateName;
    std::vector<Parameter*> predicateParameters;

public:
    Predicate();
    void SetPredicateName(std::string predicateName);
    std::string GetName();
    void AddParameter(Parameter* parameter);
    void ToString();
    std::vector<Parameter*> GetParameters();
};


#endif //PROJECT1_PREDICATE_H
