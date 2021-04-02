//
// Created by Justin on 3/16/2021.
//
using namespace std;

#ifndef PROJECT1_INTERPRETER_H
#define PROJECT1_INTERPRETER_H
#include "DatalogProgram.h"
#include "Database.h"

class Interpreter {
private:
    DatalogProgram* datalogProgram;
    Database* database;
    std::map<std::string,Relation*> relationMap;
    std::map<std::string,Relation*> ruleRelationMap;
    std::map<std::string,Predicate*> schemeMap;

    void LoadSchemes();
    void LoadFacts();
    void RunQueries();

public:
    Interpreter(DatalogProgram* datalogProgram, Database* database);
    Relation* EvaluatePredicate(Predicate* p);
    bool EvaluateRule(Rule* rule);
    bool EvaluateRules();

    void ProjectRelation(Relation* relation, Predicate* headPredicate);

    vector<pair<int, int>> GetMatchingColumnIndices(Relation* relation1, Relation* relation2);
    Header* CombineHeaders(Relation* relation1, Relation* relation2, vector<pair<int, int>> matchingColumnIndices);

    Tuple CombineTuples(Tuple tuple1, Tuple tuple2, vector<pair<int, int>> matchingColumnIndices);

    Relation* ComputeNaturalJoin(Relation* firstRelation, int secondRelationIndex, std::vector<Relation*> relations);
    std::string CreateProjectString(Rule* headRule, Relation* combinedRelation);

    void UnionizeRelationMap();
    void Run();
};



#endif //PROJECT1_INTERPRETER_H
