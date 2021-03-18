//
// Created by Justin on 3/16/2021.
//

#include "Interpreter.h"
#include "Relation.h"
#include "map"

Interpreter::Interpreter(DatalogProgram *datalogProgram, Database *database) {
    this->datalogProgram = datalogProgram;
    this->database = database;
}

void Interpreter::Run() {
    LoadSchemes();
    LoadFacts();
    RunQueries();
}

Relation *Interpreter::EvaluatePredicate(Predicate *queryPredicate) {
    string name = queryPredicate->GetName();
    Relation* relation = relationMap.at(name);

    vector<Parameter*> parameters = queryPredicate->GetParameters();
    map<std::string,int> selectMap;
    vector<int> projectIndices;
    vector<string> renameIds;

    // All the tuples in the existing table
    std::set<Tuple> origTuples = relation->GetTuples();
    std::set<Tuple> tuples;

    // Copy the original tuples
    for(Tuple tuple : origTuples) {
        tuples.insert(tuple.copy());
    }

    // Go through each query parameter
    for (unsigned int index = 0; index < parameters.size(); index++) {
        Parameter* parameter = parameters.at(index);
        string paramValue = parameter->ToString();

        if (parameter->IsConstant()) {
            //------------------------------------------
            // Do select (type 1)
            // Look for match for value in this column
            //------------------------------------------
            std::set<Tuple> tempTuples;

            for(Tuple tuple : tuples) {
                if (paramValue == tuple.GetValue(index)) {
                    // Have a match.
                    //inserting tuple
                    tempTuples.insert(tuple);
                }
            }

            tuples = tempTuples;
        } else {
            //have we seen this variable before?
            map<string, int>::iterator it;
            it = selectMap.find(paramValue);

            if (it != selectMap.end()) {
                //Do a select (type 2)
                std::set<Tuple> tempTuples;
                int firstMatchIndex = selectMap[paramValue];
                for (Tuple tuple : tuples) {
                    if (tuple.GetValue(firstMatchIndex) == tuple.GetValue(index)) {
                        tempTuples.insert(tuple);
                    }
                }

                tuples = tempTuples;
            } else {

//                //Mark it to keep for the project and rename
                selectMap.insert(pair<string, int>(paramValue, index));
                projectIndices.push_back(index);
                renameIds.push_back(paramValue);
            }
        }
    }

    //narrowing down the columns
    set<Tuple> resultTuples;
    for(Tuple tuple: tuples) {
        Tuple resultTuple = Tuple();
        vector<string> resultValues;
        for (size_t i=0;i<projectIndices.size();i++) {
            resultValues.push_back(tuple.GetValue(projectIndices.at(i)));
        }
        resultTuple.setValues(resultValues);
        resultTuples.insert(resultTuple);
    }

    Header* resultHeader = new Header(renameIds);
    Relation* resultRelation = new Relation(name, resultHeader);

    resultRelation->AddTuples(resultTuples);
    return resultRelation;
}

void Interpreter::LoadSchemes() {
    std::vector<Predicate*> schemePredicates = datalogProgram->GetSchemePredicates();

    //building relation tables (using schemes)
    for (Predicate* scheme : schemePredicates) {
        std::vector<std::string> headerNames;
        for (Parameter* parameter : scheme->GetParameters()) {
            headerNames.push_back(parameter->ToString());
        }
        Header* header = new Header(headerNames);
        Relation* relation = new Relation(scheme->GetName(),header);
        relationMap.insert(std::pair<std::string,Relation*>(scheme->GetName(),relation));
    }
}

void Interpreter::LoadFacts() {
    std::vector<Predicate*> factPredicates = datalogProgram->GetFactPredicates();
    for (Predicate* fact : factPredicates) {
        string name = fact->GetName();

        vector<string> values;
        for (Parameter* parameter: fact->GetParameters()) {
            values.push_back(parameter->ToString());
        }
        Tuple tuple = Tuple();
        tuple.setValues(values);

        Relation* relation = relationMap.at(name);
        relation->AddTuple(tuple);
    }
}

void Interpreter::RunQueries() {
    std::vector<Predicate*> queryPredicates = datalogProgram->GetQueryPredicates();

    for(Predicate* query : queryPredicates) {
        Relation* relation = EvaluatePredicate(query);
        cout << relation->GetOutput(query);
    }
}

