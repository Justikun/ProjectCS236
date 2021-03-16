//
// Created by justi on 2/25/2021.
//

#include "PlainParameter.h"

std::basic_string<char> PlainParameter::ToString() {
    return value;
}

void PlainParameter::SetValue(std::string value) {
 this->value = value;
}

