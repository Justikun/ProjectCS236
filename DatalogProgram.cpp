//
// Created by justi on 2/24/2021.
//

#include "DatalogProgram.h"

DatalogProgram::DatalogProgram() {

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
    rules.push_back(rule);
}


void DatalogProgram::AddQueryPredicate(Predicate *predicate) {
    queryPredicates.push_back(predicate);
}

void DatalogProgram::ToString() {
    ///printing Schemes
    std::cout << "Schemes(" << schemePredicates.size() << "):\n";
    for (unsigned int i=0;i<schemePredicates.size();i++) {
        std::cout << "  ";
        schemePredicates.at(i)->ToString();
        std::cout << "\n";
    }

    ///printing Facts
    std::cout << "Facts(" << factPredicates.size() << "):\n";


    for (unsigned int i=0;i<factPredicates.size();i++) {
        std::cout << "  ";
        factPredicates.at(i)->ToString();
        std::cout << ".\n";
    }

    ///printing Rules

    std::cout << "Rules(" << rules.size() << "):\n";


    for (unsigned int i=0; i < rules.size(); i++) {
        std::cout << "  ";
        rules.at(i)->ToString();
        std::cout << "." << std::endl;

    }

    ///printing Queries
    if (queryPredicates.size() !=0) {
        std::cout << "Queries(" << queryPredicates.size() << "):\n";
    }

    for (unsigned int i=0;i<queryPredicates.size();i++) {
        std::cout << "  ";
        queryPredicates.at(i)->ToString();
        std::cout << "?" << std::endl;

    }

    ///printing domain
    std::cout << "Domain(" << domains.size() << "):\n";


    for (auto it: domains) {
        std::cout << "  ";
        std::cout << it << std::endl;
    }

}

void DatalogProgram::AddDomain(Predicate *predicate) {
    std::vector<Parameter*> parameters = predicate->GetParameters();

    for (unsigned int i=0;i<parameters.size();i++) {
        domains.insert(parameters.at(i)->ToString());
    }

}

std::vector<Predicate *> DatalogProgram::GetSchemePredicates() {
    return schemePredicates;
}

std::vector<Predicate *> DatalogProgram::GetFactPredicates() {
    return factPredicates;
}

std::vector<Predicate *> DatalogProgram::GetQueryPredicates() {
    return queryPredicates;
}

std::vector<Rule *> DatalogProgram::GetRules() {
    return rules;
}

