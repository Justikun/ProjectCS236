//
// Created by justi on 2/23/2021.
//

#ifndef PROJECT1_PARSER_H
#define PROJECT1_PARSER_H

#include "Token.h"
#include "vector"
<<<<<<< HEAD
#include "DatalogProgram.h"
#include "Predicate.h"
#include "Parameter.h"
=======
>>>>>>> parent of 2713c90 (project2 part one running smoothly)

class Parser {
public:
    Parser();
    ~Parser();
    void Parse(std::vector<Token*> tokens);
private:
    int tokenPosition;
    void ParseDatalogProgram(std::vector<Token*> tokens);

    void ParseSchemeList(std::vector<Token*> tokens);
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
    Parameter* ParseIdList(std::vector<Token*> tokens);

    void ParseParameter(std::vector<Token*> tokens);
    void ParseExpression(std::vector<Token*> tokens);
    void ParseOperator(std::vector<Token*> tokens);

    void ParseMatchFail();

    void CheckTerminal(std::vector<Token*> tokens, TokenType tokenType);

};



#endif //PROJECT1_PARSER_H