//
// Created by justi on 2/25/2021.
//

#ifndef PROJECT1_PARAMETER_H
#define PROJECT1_PARAMETER_H
#include <iostream>

class Parameter {
private:
    std::string name;

public:
    Parameter();
    void SetName(std::string name);
    std::string GetName();
    std::basic_string<char> ToString();
};


#endif //PROJECT1_PARAMETER_H
