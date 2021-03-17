//
// Created by Justin on 3/15/2021.
//

#ifndef PROJECT1_PARAMETER_H
#define PROJECT1_PARAMETER_H
#include <iostream>

class Parameter {
protected:
    bool constant;

public:
    virtual std::string ToString() = 0;
    bool IsConstant();
};


#endif //PROJECT1_PARAMETER_H
