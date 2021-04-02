//
// Created by Justin on 3/16/2021.
//

#include "Interpreter.h"
#include "Relation.h"
#include "map"
#include "Tuple.h"
#include "sstream"

Interpreter::Interpreter(DatalogProgram *datalogProgram, Database *database) {
    this->datalogProgram = datalogProgram;
    this->database = database;
}

void Interpreter::Run() {
    LoadSchemes();
    LoadFacts();
    //load the database
    database->SetRelationMap(relationMap);

    cout<< "Rule Evaluation\n";
    bool addedTuples = EvaluateRules();

    while(addedTuples) {
        addedTuples = EvaluateRules();
    }



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
        resultTuple.SetValues(resultValues);
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
        schemeMap.insert(pair<std::string,Predicate*>(scheme->GetName(),scheme));
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
        tuple.SetValues(values);

        Relation* relation = relationMap.at(name);
        relation->AddTuple(tuple);
    }
}

void Interpreter::RunQueries() {
    cout<< "\nQuery Evaluation\n";
    std::vector<Predicate*> queryPredicates = datalogProgram->GetQueryPredicates();

    for(Predicate* query : queryPredicates) {
        Relation* relation = EvaluatePredicate(query);

        cout << relation->GetOutput(query);
    }
}

bool Interpreter::EvaluateRules() {
    bool didAddTuple = false;

    //looping through all Rules (right hand side)
    std::vector<Rule*> rules = datalogProgram->GetRules();
    for(size_t i=0;i<rules.size();i++) {
        if (EvaluateRule(rules.at(i))) {
            didAddTuple = true;
        }
    }

    return didAddTuple;
}

// Returns true if a tuple was added
bool Interpreter::EvaluateRule(Rule *rule) {

    // Create a list of relations for each body predicate in the rule
    std::vector<Relation*> bodyRelations;
    for(size_t j=0;j<rule->GetBodyPredicates().size();j++) {
        Predicate* predicate = rule->GetBodyPredicates().at(j);
        bodyRelations.push_back(EvaluatePredicate(predicate));
    }

    Relation *joinedRelation = nullptr;

    if (bodyRelations.size() > 1) {
        joinedRelation = ComputeNaturalJoin(bodyRelations.at(0), 1, bodyRelations);
    } else {
        joinedRelation = bodyRelations.at(0);
    }

    ProjectRelation(joinedRelation, rule->GetHeadPredicate());
    string headerName = rule->GetHeadPredicate()->GetName();
    joinedRelation->SetName(headerName);

    ///outputing rule stuff for passoff
    rule->ToString();
    for (auto tuple : joinedRelation->GetTuples()) {
        for (size_t i=0;i<rule->GetHeadPredicate()->GetParameters().size();i++) {
            Predicate *scheme = schemeMap.at(joinedRelation->GetName());
            if (i==0) {
                cout <<  "  ";
            }
            if (i > 0) {
                cout << ", ";
            }
            cout << scheme->GetParameters().at(i)->ToString() << "=" << tuple.GetValue(i);
        }
        cout << endl;
    }

    map<string, Relation*>::iterator it;
    it = ruleRelationMap.find(joinedRelation->GetName());

    if (it != ruleRelationMap.end()) {
        //found
        Relation* existingRelation = ruleRelationMap[joinedRelation->GetName()];
        return existingRelation->AddTuples(joinedRelation->GetTuples());

    } else {
        //not found
        //insert into the map
        if (joinedRelation->GetTuples().size() > 0) {
            cout << "Putting " << joinedRelation->GetName() << " into map" << endl;
            ruleRelationMap.insert(pair<string, Relation *>(joinedRelation->GetName(), joinedRelation));
            return true;
        }
    }

    return false;
}

Relation* Interpreter::ComputeNaturalJoin(Relation* firstRelation, int secondRelationIndex, std::vector<Relation*> relations) {
    Relation* relation1 = firstRelation;
    Relation* relation2 = relations.at(secondRelationIndex);
    set<Tuple> tuples1 = relation1->GetTuples();
    set<Tuple> tuples2 = relation2->GetTuples();

    cout << "Rel 1: " << relation1->GetName() << endl;
    for (auto tuple : relation1->GetTuples()) {
        cout << tuple.ToString() << endl;
    }

    cout << "Rel 2: " << relation2->GetName() << endl;
    for (auto tuple : relation2->GetTuples()) {
        cout << tuple.ToString() << endl;
    }


    //Get matching column indices
    vector<pair<int, int>> matchingColumnIndices = GetMatchingColumnIndices(relation1, relation2);

    cout << "Matching indices" << endl;
    for (auto index : matchingColumnIndices) {
        cout << index.first << ", " << index.second << endl;
    }


    //Get and combine header from relation1 and relation2
    Header* combinedHeader = CombineHeaders(relation1, relation2, matchingColumnIndices);
    std::vector<string> combinedHeaderNames = combinedHeader->GetHeaderNames();

    //match Tuples and create a relation
    set<Tuple> joinedTuples;
    for (auto tuple1 : tuples1) {
        for (auto tuple2: tuples2) {
            for (auto indexPair : matchingColumnIndices) {
                if (tuple1.GetValue(indexPair.first) == tuple2.GetValue(indexPair.second)) {
                    //tuples are join-able
                    //combining tuples
                    Tuple combinedTuple = CombineTuples(tuple1, tuple2, matchingColumnIndices);
                    joinedTuples.insert(combinedTuple);
                }
            }
        }
    }

    //create name using the combinedHeader
    string headerName = "";
    for (auto letter : combinedHeaderNames) {
        headerName.append(letter);
    }

    Relation* joinedRelation = new Relation(headerName, combinedHeader);
    if (joinedTuples.size() > 0) {
        joinedRelation->AddTuples(joinedTuples);
    }

    secondRelationIndex++;
    if (secondRelationIndex >= relations.size()) {
        return joinedRelation;
    }

    return ComputeNaturalJoin(joinedRelation, secondRelationIndex, relations);
}

std::string Interpreter::CreateProjectString(Rule* headRule, Relation* combinedRelation) {
    //TODO: create and return string for the correct projection.

    return std::__cxx11::string();
}

vector<pair<int, int>> Interpreter::GetMatchingColumnIndices(Relation* relation1, Relation* relation2) {
    //marking the matching headers
    vector<pair<int, int>> matchingColumnIndices;
    for (size_t i=0;i<relation1->GetHeader()->GetHeaderNames().size();i++) {
        for(size_t j=0;j<relation2->GetHeader()->GetHeaderNames().size();j++) {
            if (relation1->GetHeader()->GetHeaderNames().at(i) == relation2->GetHeader()->GetHeaderNames().at(j)) {
                //headers match, add indices to matchingColumnIndices
                pair<int,int> indexes;
                indexes.first = static_cast<int>(i);
                indexes.second = static_cast<int>(j);
                matchingColumnIndices.push_back(indexes);
            }
        }
    }

    return matchingColumnIndices;
}

//this will get rid of the columns that don't match the head predicate parameters
void Interpreter::ProjectRelation(Relation *relation, Predicate* headPredicate) {
    //get the indices for the columns we want to keep
    vector<int> indices;
    for (size_t i=0;i<headPredicate->GetParameters().size();i++) {
        string headColumnName = headPredicate->GetParameters().at(i)->ToString();
        for (size_t j=0;j<relation->GetHeader()->GetHeaderNames().size();j++) {
        string columnName = relation->GetHeader()->GetHeaderNames().at(j);
            if (headColumnName == columnName) {
                indices.push_back(j);
            }
        }
    }

    set<Tuple> projectedTuples;
    auto tuples = relation->GetTuples();
    //getting the values for the columns that are in the head predicate and putting them into the relation
    for (auto tuple : tuples) {
        Tuple resultTuple;
        vector<string> values;
        for (size_t i=0;i<tuple.GetValues().size();i++) {
            for (size_t j = 0; j < indices.size(); j++) {
                if (i==j) {
                    values.push_back(tuple.GetValue(i));
                }
            }
        }
        resultTuple.SetValues(values);
        projectedTuples.insert(resultTuple);
    }

    relation->SetTuples(projectedTuples);

    // changing the the header to match the head predicate
    vector<string> resultHeaderNames;
    for(size_t i=0;i<headPredicate->GetParameters().size();i++) {
        resultHeaderNames.push_back(headPredicate->GetParameters().at(i)->ToString());
    }
    Header* resultHeader = new Header(resultHeaderNames);
    relation->SetHeader(resultHeader);
}

void Interpreter::UnionizeRelationMap() {
    auto it = ruleRelationMap.begin();

    while (it != ruleRelationMap.end()) {
        string relationName = it->first;
        Relation* ruleRelation = it->second;

        Relation* existingRelation = relationMap.at(relationName);
        existingRelation->AddTuples(ruleRelation->GetTuples());
    }
}

Tuple Interpreter::CombineTuples(Tuple tuple1, Tuple tuple2, vector<pair<int, int>> matchingColumnIndices) {
    //combining tuple1 & tuple2
    Tuple combinedTuple = Tuple();
    vector<string> values;

    for (auto value : tuple1.GetValues()) {
        values.push_back(value);
    }

    for (size_t i=0;i<tuple2.GetValues().size();i++) {
        auto itr = matchingColumnIndices.begin();
        while(itr != matchingColumnIndices.end()) {
            if (itr->second != i) {
                values.push_back(tuple2.GetValue(i));
            }
            itr++;
        }
    }

    combinedTuple.SetValues(values);
    return combinedTuple;
}

Header* Interpreter::CombineHeaders(Relation *relation1, Relation *relation2, vector<pair<int, int>> matchingColumnIndices) {
    //adding headers into a combined headers vector
    //add header names from the relation2;
    std::vector<std::string> combinedHeaderNames;
    for (size_t i=0;i<relation1->GetHeader()->GetHeaderNames().size();i++) {
        combinedHeaderNames.push_back(relation1->GetHeader()->GetHeaderNames().at(i));
    }

    //adding the unique names from relation2
    for (size_t i=0;i<relation2->GetHeader()->GetHeaderNames().size();i++) {
        auto itr = matchingColumnIndices.begin();
        while(itr != matchingColumnIndices.end()) {
            if (itr->second != i) {
                combinedHeaderNames.push_back(relation2->GetHeader()->GetHeaderNames().at(i));
            }
            itr++;
        }
    }

    Header* combinedHeader = new Header(combinedHeaderNames);

    return combinedHeader;
}
