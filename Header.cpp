//
// Created by Justin on 3/15/2021.
//

#include "Header.h"

Header::Header(std::vector<std::string> headerNames) {
    this->headerNames = headerNames;
}

std::string Header::ToString() {

    std::string text = "";
    for (std::string headerName: this->headerNames) {
        if (text.length() > 0) {
            text.append(",");
        }
        text.append(headerName);
    }

    return text;
}

Header *Header::copy() {
    std::vector<std::string> headerNamesCopy;
    for (std::string headerName : headerNames) {
        headerNamesCopy.push_back(headerName);
    }
    Header* header = new Header(headerNamesCopy);
    return header;
}
