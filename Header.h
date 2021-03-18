//
// Created by Justin on 3/15/2021.
//

#ifndef PROJECT1_HEADER_H
#define PROJECT1_HEADER_H
#include <iostream>
#include <vector>

class Header {
private:
    std::vector<std::string> headerNames;
public:
    Header(std::vector<std::string> headerNames);
    std::string ToString();
    std::vector<std::string> GetHeaderNames();
    Header* copy();
};


#endif //PROJECT1_HEADER_H
