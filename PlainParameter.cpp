//
// Created by justi on 2/25/2021.
//

#include "PlainParameter.h"

std::string PlainParameter::ToString() {
    return value;
}

void PlainParameter::SetValue(std::string value, bool constant) {
 this->value = value;
 this->constant = constant;
}

