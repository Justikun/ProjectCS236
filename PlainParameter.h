//
// Created by justi on 2/25/2021.
//

#ifndef PROJECT1_PLAINPARAMETER_H
#define PROJECT1_PLAINPARAMETER_H
#include <iostream>
#include "Parameter.h"

class PlainParameter: public Parameter {
private:
    std::string value;
public:
    void SetValue(std::string value);
    std::basic_string<char> ToString() override;
};


#endif //PROJECT1_PLAINPARAMETER_H
