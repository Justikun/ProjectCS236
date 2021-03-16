//
// Created by Justin on 3/15/2021.
//

#ifndef PROJECT1_EXPRESSION_H
#define PROJECT1_EXPRESSION_H

#include "Parameter.h"

class Expression: public Parameter {
private:
    Parameter* leftParameter;
    std::string operatorValue;
    Parameter* rightParameter;
public:
    void SetLeftParameter(Parameter* parameter);
    void SetOperator(std::string operatorValue);
    void SetRightParameter(Parameter* parameter);

    std::basic_string<char> ToString();
};


#endif //PROJECT1_EXPRESSION_H
