//
// Created by justi on 2/25/2021.
//

#include "Parameter.h"


Parameter::Parameter() {

}

void Parameter::SetName(std::string name) {
    this->name = name;
}

std::basic_string<char> Parameter::ToString() {
    std::cout << name;
}

std::string Parameter::GetName() {
    return name;
}
