//
// Created by justi on 2/24/2021.
//

#include "DatalogProgram.h"

DatalogProgram::DatalogProgram() {
//    schemePredicates = {};
//    factPredicates = {};
//    queryPredicates = {};
//    rulePredicates = {};

}

DatalogProgram::~DatalogProgram() {

}

void DatalogProgram::AddSchemePredicate(Predicate* predicate) {
    schemePredicates.push_back(predicate);
}

void DatalogProgram::AddFactPredicate(Predicate* predicate) {
    factPredicates.push_back(predicate);

}

void DatalogProgram::AddRulePredicate(Rule *rule) {
    rulePredicates.push_back(rule);
}


void DatalogProgram::AddQueryPredicate(Predicate *predicate) {
    queryPredicates.push_back(predicate);
}

void DatalogProgram::ToString() {
    ///printing Schemes
    std::cout << "Schemes(" << schemePredicates.size() << "):\n";
    for (int i=0;i<schemePredicates.size();i++) {
        std::cout << "  ";
        schemePredicates.at(i)->ToString();
        std::cout << ")\n";
    }

    ///printing Facts
    if (factPredicates.size() != 0) {
        std::cout << "Facts(" << factPredicates.size() << "):\n";
    }

    for (int i=0;i<factPredicates.size();i++) {
        std::cout << "  ";
        factPredicates.at(i)->ToString();
        std::cout << ").\n";
    }

    std::cout << "Size: " << rulePredicates.size() << std::endl;

    ///printing Rules
    if (rulePredicates.size() != 0) {
        std::cout << "Rule(" << rulePredicates.size() << "):\n";
    }

    for (int i=0;i<rulePredicates.size();i++) {
        std::cout << "  ";
        rulePredicates.at(i)->ToString();
    }
}
