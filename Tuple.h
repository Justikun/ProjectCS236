//
// Created by Justin on 3/15/2021.
//

#ifndef PROJECT1_TUPLE_H
#define PROJECT1_TUPLE_H
#include <iostream>
#include <vector>

class Tuple {
private:
    std::vector<std::string> values;
public:
    Tuple();
    void setValues(std::vector<std::string> values);
    std::string ToString();
    bool operator< (const Tuple & other) const;
    std::string GetValue(int index);
    Tuple copy();
};


#endif //PROJECT1_TUPLE_H
