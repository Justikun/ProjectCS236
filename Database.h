//
// Created by Justin on 3/15/2021.
//

#ifndef PROJECT1_DATABASE_H
#define PROJECT1_DATABASE_H
#include <map>
#include "Relation.h"

class Database {
private:
    std::map<std::string, Relation*> relationshipMap;
public:
    Database();
    void test();

    std::map<std::string, Relation*> GetRelationMap();
    void SetRelationMap(std::map<std::string, Relation*> relationshipMap);
};


#endif //PROJECT1_DATABASE_H
