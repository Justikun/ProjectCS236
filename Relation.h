//
// Created by Justin on 3/15/2021.
//

#ifndef PROJECT1_RELATION_H
#define PROJECT1_RELATION_H

#include "Tuple.h"
#include "Header.h"
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include "Predicate.h"

class Relation {
    std::string name;
    Header* header;
    std::set<Tuple> tuples;
public:
    std::string GetName();
    void SetName(std::string name);
    Relation(std::string name, Header* header);
    bool AddTuple(Tuple tuple);
    bool AddTuples(std::set<Tuple> tuples);
    std::set<Tuple> GetTuples();
    Header* GetHeader();
    void SetHeader(Header* header);
    std::string ToString();
    std::string GetOutput(Predicate* queryPredicate);
    void SetTuples(std::set<Tuple> tuples);

};


#endif //PROJECT1_RELATION_H
