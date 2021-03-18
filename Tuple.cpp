//
// Created by Justin on 3/15/2021.
//

#include "Tuple.h"

// This defines how we sort Tuples
bool Tuple::operator< (const Tuple &other) const {
    for (unsigned int i=0;i<values.size();i++) {
        if (values.at(i) > other.values.at(i)) {
            return false;
        } else if (values.at(i) < other.values.at(i)) {
            return true;
        }
    }
    return true;
}

std::string Tuple::ToString() {
    std::string text = "";
    for (std::string value: values) {
        if (text.length() > 0) {
            text.append(",");
        }
        text.append((value));
    }
    return text;
}

void Tuple::setValues(std::vector<std::string> values) {
    this->values = values;
}

Tuple::Tuple() {

}

std::string Tuple::GetValue(int index) {
    return values.at(index);
}

Tuple Tuple::copy() {
    std::vector<std::string> valuesCopy;

    for (std::string value: values) {
        valuesCopy.push_back(value);
    }
    Tuple tuple = Tuple();
    tuple.setValues(valuesCopy);

    return tuple;
}

