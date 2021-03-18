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
    Relation(std::string name, Header* header);
    void AddTuple(Tuple tuple);
    void AddTuples(std::set<Tuple> tuples);
    std::set<Tuple> GetTuples();
    Header* GetHeader();
    std::string ToString();
    std::string GetOutput(Predicate* queryPredicate);


};


#endif //PROJECT1_RELATION_H
