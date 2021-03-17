//
// Created by Justin on 3/16/2021.
//

#include "Interpreter.h"
#include "Relation.h"
#include "map"

Interpreter::Interpreter(DatalogProgram *datalogProgram, Database *database) {
    this->datalogProgram = datalogProgram;
    this->database = database;
    Run();
}

void Interpreter::Run() {
    LoadSchemes();
    LoadFacts();
    RunQueries();
}

Relation *Interpreter::EvaluatePredicate(Predicate *queryPredicate) {
    string name = queryPredicate->GetName();
    Relation* relation = relationMap.at(name);

    Header* header = relation->GetHeader();

    Relation* resultRelation = new Relation(name, header->copy());
    vector<Parameter*> parameters = queryPredicate->GetParameters();
    map<std::string,int> selectMap;
    vector<int> projectIndices;
    vector<string> renameIds;

    // All the tuples in the existing table
    std::set<Tuple> tuples = relation->GetTuples();

    // Go through each query parameter
    for (int i=0; i<parameters.size(); i++) {
        Parameter* parameter = parameters.at(i);
        string paramValue = parameter->ToString();

        if (parameter->IsConstant()) {
            //------------------------------------------
            // Do select (type 1)
            // Look for match for value in this column
            //------------------------------------------
            for(Tuple tuple : tuples) {
                if (paramValue == tuple.GetValue(i)) {
                    // Have a match. Add the tuple.
                    resultRelation->AddTuple(tuple.copy());
                }
            }

            // New set of tuples. We've narrowed it down to a smaller set.
            tuples = resultRelation->GetTuples();
        } else {
            //have we seen this variable before?
            map<string, int>::iterator it;
            it = selectMap.find(paramValue);

            if (it != selectMap.end()) {
                //Do a select (type 2)
                cout << "Doing select type 2\n";
                // TODO: Narrow down our selection on columns that have the same values
            } else {
//                //Mark it to keep for the project and rename
                cout << "Inserting paramValue: " << paramValue << " at index " << i << "\n";

                selectMap.insert(pair<string, int>(paramValue,i));
                projectIndices.push_back(i);
                renameIds.push_back(paramValue);

            }
        }

        // TODO: Rename columns
        // TODO: Project columns
        // TODO: Update GetOutpout in Relation to output the tuples
    }

   cout << resultRelation->GetOutput(queryPredicate) << endl;

    return relation;
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

    //    auto iter = relationMap.begin();
//    while(iter!= relationMap.end()) {
//        Relation* relation = (Relation*) iter->second;
//        cout << "[" << iter->first << ","
//             << relation->ToString() << "]\n";
//        ++iter;
//    }

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


//
//    Relation* relation = relationMap.at("snap");
//    cout << relation->ToString() << endl;

}

void Interpreter::RunQueries() {
    std::vector<Predicate*> queryPredicates = datalogProgram->GetQueryPredicates();

    for(Predicate* query : queryPredicates) {
        Relation* relation = EvaluatePredicate(query);
    }
}

