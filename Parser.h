//
// Created by justi on 2/23/2021.
//

#ifndef PROJECT1_PARSER_H
#define PROJECT1_PARSER_H

#include "Token.h"
#include "vector"
#include "Predicate.h"
#include "DatalogProgram.h"

class Parser {
public:
    Parser();
    ~Parser();
    void Parse(std::vector<Token*> tokens);
private:
    int tokenPosition;
    void ParseDatalogProgram(std::vector<Token*> tokens);

    std::vector<Predicate> ParseSchemeList(std::vector<Token*> tokens);
    void ParseFactList(std::vector<Token*> tokens);
    void ParseRuleList(std::vector<Token*> tokens);
    void ParseQueryList(std::vector<Token*> tokens);

    void ParseScheme(std::vector<Token*> tokens);
    void ParseFact(std::vector<Token*> tokens);
    void ParseRule(std::vector<Token*> tokens);
    void ParseQuery(std::vector<Token*> tokens);

    void ParseHeadPredicate(std::vector<Token*> tokens);
    void ParsePredicate(std::vector<Token*> tokens);

    void ParsePredicateList(std::vector<Token*> tokens);
    void ParseParameterList(std::vector<Token*> tokens);
    void ParseStringList(std::vector<Token*> tokens);
    void ParseIdList(std::vector<Token*> tokens);

    void ParseParameter(std::vector<Token*> tokens);
    void ParseExpression(std::vector<Token*> tokens);
    void ParseOperator(std::vector<Token*> tokens);

    void CheckTerminal(std::vector<Token*> tokens, TokenType tokenType);

    std::vector<Predicate> GetPredicates();
    std::vector<Predicate> GetFacts();
    std::vector<Predicate> GetQueries();
    std::vector<Predicate> GetRules();
};



#endif //PROJECT1_PARSER_H