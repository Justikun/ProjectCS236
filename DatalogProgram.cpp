//
// Created by justi on 2/24/2021.
//

#include "DatalogProgram.h"

DatalogProgram::DatalogProgram() {

}

DatalogProgram::~DatalogProgram() {

}

void DatalogProgram::AddSchemePredicate(Predicate predicate) {
    schemePredicates.push_back(predicate);
}
