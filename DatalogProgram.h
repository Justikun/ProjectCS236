//
// Created by justi on 2/24/2021.
//

#ifndef PROJECT1_DATALOGPROGRAM_H
#define PROJECT1_DATALOGPROGRAM_H

#include "Predicate.h"
#include "Rule.h"
#include "set"
class DatalogProgram {
private:
    std::vector<Predicate*> schemePredicates;
    std::vector<Predicate*> factPredicates;
    std::vector<Rule*> rulePredicates;
    std::vector<Predicate*> queryPredicates;
    std::set<std::string> domains;

public:
    DatalogProgram();
    ~DatalogProgram();

    void AddSchemePredicate(Predicate* predicate);
    void AddFactPredicate(Predicate* predicate);
    void AddRulePredicate(Rule* predicate);
    void AddQueryPredicate(Predicate* predicate);
    void AddDomain(Predicate* predicate);

    //Get methods
    std::vector<Predicate*> GetSchemePredicates();
    std::vector<Predicate*> GetFactPredicates();
    std::vector<Predicate*> GetQueryPredicates();


    void ToString();

};


#endif //PROJECT1_DATALOGPROGRAM_H
