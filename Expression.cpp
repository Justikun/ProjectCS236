//
// Created by Justin on 3/15/2021.
//

#include "Expression.h"

void Expression::SetLeftParameter(Parameter *parameter) {
    leftParameter = parameter;
}

void Expression::SetOperator(std::string operatorValue) {
    this->operatorValue = operatorValue;
}

void Expression::SetRightParameter(Parameter *parameter) {
    rightParameter = parameter;
}

std::basic_string<char> Expression::ToString() {
    std::string value = "";
    std::string leftParen = "(";
    std::string rightParen = ")";
    value.append(leftParen);
    value.append(leftParameter->ToString());
    value.append(operatorValue);
    value.append(rightParameter->ToString());
    value.append(rightParen);
    return value;
}

