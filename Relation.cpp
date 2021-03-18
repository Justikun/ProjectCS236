//
// Created by Justin on 3/15/2021.
//
using namespace std;
#include "Relation.h"
#include <sstream>

Relation::Relation(std::string name, Header* header) {
    this->name = name;
    this->header = header;
}

std::string Relation::ToString() {
//    return this->header->ToString();
    string text = "";
    for (Tuple tuple : tuples) {
        if (text.length() > 0) {
            text.append("\n");
        }
        text.append(tuple.ToString());
    }

    return text;
}


void Relation::AddTuple(Tuple tuple) {
    tuples.insert(tuple);
}

Header *Relation::GetHeader() {
    return header;
}

std::set<Tuple> Relation::GetTuples() {
    return tuples;
}

string Relation::GetOutput(Predicate *queryPredicate) {
    string predicateName = queryPredicate->GetName();
    vector<Parameter*> predicateParameters = queryPredicate->GetParameters();

    std::ostringstream text;

    text << predicateName << "(";
    for (unsigned int i=0;i<predicateParameters.size();i++) {
        text << predicateParameters.at(i)->ToString();
        if (predicateParameters.size() != i+1) {
            text << ",";
        }
    }

    text << ")?";

    if (tuples.size() > 0) {
        text << " Yes(" << tuples.size() << ")";
    }
    else {
        text << " No";
    }
    text << "\n";

    vector<string> headerNames = header->GetHeaderNames();

    for(Tuple tuple : tuples) {
        for(size_t i=0;i<headerNames.size();i++) {
            if (i==0) {
                text << "  ";
            }
            text << headerNames.at(i) << "=" << tuple.GetValue(i);
            if (i<headerNames.size()-1) {
                text << ", ";
            }
        }
        if (headerNames.size() > 0) {
            text << endl;
        }
    }


    return text.str();
}

void Relation::AddTuples(std::set<Tuple> tuples) {
    for (Tuple tuple: tuples) {
        AddTuple(tuple);
    }
}
