//
// Created by justi on 2/25/2021.
//

#include "Parameter.h"


Parameter::Parameter() {

}

void Parameter::AddParameter(std::string parameter) {
    this->parameter = parameter;
}

void Parameter::ToString() {
    std::cout << parameter;
}