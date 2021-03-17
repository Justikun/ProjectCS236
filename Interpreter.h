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

    void LoadSchemes();
    void LoadFacts();
    void RunQueries();
public:
    Interpreter(DatalogProgram* datalogProgram, Database* database);
    Relation* EvaluatePredicate(Predicate* p);
    void Run();
};



#endif //PROJECT1_INTERPRETER_H
