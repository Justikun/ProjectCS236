//
// Created by justi on 2/23/2021.
//

#ifndef PROJECT1_PARSER_H
#define PROJECT1_PARSER_H

#include "Token.h"
#include "vector"
#include "DatalogProgram.h"
#include "Predicate.h"
#include "PlainParameter.h"

class Parser {
public:
    Parser(std::vector<Token*> tokens);
    ~Parser();

    void Parse();
    DatalogProgram* GetDatalogProgram();
private:
    int tokenPosition;
    std::vector<Token*> tokens;
    DatalogProgram* datalogProgram;

    void ParseDatalogProgram();

    void ParseSchemeList();
    void ParseFactList();
    void ParseRuleList();
    void ParseQueryList();

    void ParseScheme();
    void ParseFact();
    void ParseRule();
    void ParseQuery();

    Predicate* ParseHeadPredicate();
    Predicate* ParsePredicate();

    void ParsePredicateList(std::vector<Predicate*> *predicates);
    void ParseParameterList(std::vector<Parameter*> *parameters);
    void ParseStringList(std::vector<PlainParameter*> *parameters);
    void ParseIdList(std::vector<PlainParameter*> *parameters);

    Parameter* ParseParameter();
    Parameter* ParseExpression();
    void ParseOperator();

    void CheckTerminal(TokenType tokenType);

};



#endif //PROJECT1_PARSER_H