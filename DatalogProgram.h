//
// Created by justi on 2/24/2021.
//

#ifndef PROJECT1_DATALOGPROGRAM_H
#define PROJECT1_DATALOGPROGRAM_H

#include "Predicate.h"
#include "Rule.h"

class DatalogProgram {
private:
    std::vector<Predicate*> schemePredicates;
    std::vector<Predicate*> factPredicates;
    std::vector<Rule*> rulePredicates;
    std::vector<Predicate*> queryPredicates;


public:
    DatalogProgram();
    ~DatalogProgram();

    void AddSchemePredicate(Predicate* predicate);
    void AddFactPredicate(Predicate* predicate);
    void AddRulePredicate(Rule* predicate);
    void AddQueryPredicate(Predicate* predicate);

    void ToString();

};


#endif //PROJECT1_DATALOGPROGRAM_H
