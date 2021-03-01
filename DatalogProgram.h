//
// Created by justi on 2/24/2021.
//

#ifndef PROJECT1_DATALOGPROGRAM_H
#define PROJECT1_DATALOGPROGRAM_H
#include "Parser.h"
#include "Predicate.h"
#include "Rule.h"

class DatalogProgram {
private:
    std::vector<Predicate> schemePredicates;
    std::vector<Predicate> factPredicates;
    std::vector<Predicate> queryPredicates;
    std::vector<Predicate> rulePredicates;

public:
    DatalogProgram();
    ~DatalogProgram();

    void AddSchemePredicate(Predicate);
    void AddFactPredicate(Predicate);
    void AddQueryPredicate(Predicate);
    void AddRulePredicate(Rule);


    std::string ToString();
};


#endif //PROJECT1_DATALOGPROGRAM_H
