//
// Created by justi on 2/23/2021.
//

#include <iostream>
#include "Parser.h"
#include "Expression.h"
Parser::Parser(std::vector<Token*> tokens){
    tokenPosition = 0;
    datalogProgram = new DatalogProgram();
    this->tokens = tokens;
}

Parser::~Parser() {

}

void Parser::Parse() {
    ParseDatalogProgram();
}

void Parser::ParseDatalogProgram() {
    ///PRODUCTION
    ///NOTE: SCHEMES COLON scheme schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList EOF

    CheckTerminal( SCHEMES);
    tokenPosition++;
    CheckTerminal(COLON);
    tokenPosition++;
    ParseScheme();

    //checks follow-set of ParseSchemeList
    if (tokens.at(tokenPosition)->GetTokenType() != FACTS) {
        ParseSchemeList();
    }

    CheckTerminal( FACTS);
    tokenPosition++;
    CheckTerminal( COLON);
    tokenPosition++;

    //checks follow-set of ParseFactList
    if (tokens.at(tokenPosition)->GetTokenType() != RULES) {
        ParseFactList();
    }

    //TODO: parse Rules && ask TA for help on this. because I am very confused.

    CheckTerminal( RULES);
    tokenPosition++;
    CheckTerminal( COLON);
    tokenPosition++;

//    checks follow-set of ruleList
    if (tokens.at(tokenPosition)->GetTokenType() != QUERIES) {
        ParseRuleList();
    }

    std::cout << "Success!" << std::endl;

    CheckTerminal( QUERIES);
    tokenPosition++;

    CheckTerminal( COLON);
    tokenPosition++;

    ParseQuery();

    //checks follow-set of ParseQueryList
    if (tokens.at(tokenPosition)->GetTokenType() != END_OF_FILE) {
        ParseQueryList();
    }
}

void Parser::ParseSchemeList() {
    ///PRODUCTION
    ///scheme schemeList | lambda
    ParseScheme();

    if (tokens.at(tokenPosition)->GetTokenType() != FACTS) {
        ParseSchemeList();
    }
}

void Parser::ParseScheme() {
    ///Production
    ///ID LEFT_PAREN ID idList RIGHT_PAREN

    Predicate* predicate = new Predicate();

    CheckTerminal( ID);
    //Creating a predicate with the ID name
    predicate->SetPredicateName(tokens.at(tokenPosition)->GetInput());
    tokenPosition++;

    CheckTerminal( LEFT_PAREN);
    tokenPosition++;

    //Creating the first name of the predicate
    CheckTerminal( ID);
    PlainParameter* parameter = new PlainParameter();
    parameter->SetValue(tokens.at(tokenPosition)->GetInput());
    predicate->AddParameter(parameter);
    tokenPosition++;

    //checks follow-set of parseIdList
    if (tokens.at(tokenPosition)->GetTokenType() != RIGHT_PAREN) {
        std::vector<PlainParameter*> parameters;
        ParseIdList(&parameters);

        for (int i=0; i<parameters.size(); i++) {
            predicate->AddParameter(parameters.at(i));
        }
    }

    CheckTerminal( RIGHT_PAREN);

    datalogProgram->AddSchemePredicate(predicate);
    tokenPosition++;
}

void Parser::ParseIdList(std::vector<PlainParameter*> *parameters) {
    ///PRODUCTION
    ///COMMA ID idList | lambda
    PlainParameter *parameter = new PlainParameter();
    CheckTerminal(COMMA);
    tokenPosition++;

    // Check for ID and add
    CheckTerminal(ID);
    parameter->SetValue(tokens.at(tokenPosition)->GetInput());
    tokenPosition++;
    parameters->push_back(parameter);

    //checks follows-Set of parseIdList
    if (tokens.at(tokenPosition)->GetTokenType() != RIGHT_PAREN) {
        ParseIdList(parameters);
    }
}

void Parser::ParseFactList() {
    ///PRODUCTION
    ///fact factList | lambda

    ParseFact();
    //checks follow-Set of ParseFact
    if (tokens.at(tokenPosition)->GetTokenType() != RULES) {
        ParseFactList();
    }
}

void Parser::ParseFact() {
    ///PRODUCTION
    ///ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
    Predicate* predicate = new Predicate();

    CheckTerminal( ID);
    predicate->SetPredicateName(tokens.at(tokenPosition)->GetInput());
    tokenPosition++;

    CheckTerminal( LEFT_PAREN);
    tokenPosition++;

    CheckTerminal( STRING);
    PlainParameter* parameter = new PlainParameter();
    parameter->SetValue(tokens.at(tokenPosition)->GetInput());
    tokenPosition++;
    predicate->AddParameter(parameter);

    //checks follow-set of ParseStringList
    if (tokens.at(tokenPosition)->GetTokenType() != RIGHT_PAREN) {
        std::vector<PlainParameter*> parameters;
        ParseStringList(&parameters);

        for (int i=0; i<parameters.size(); i++) {
            predicate->AddParameter(parameters.at(i));
        }
    }

    CheckTerminal( RIGHT_PAREN);
    tokenPosition++;
    CheckTerminal( PERIOD);
    tokenPosition++;

    datalogProgram->AddFactPredicate(predicate);
    datalogProgram->AddDomain(predicate);
}

void Parser::ParseStringList(std::vector<PlainParameter*> *parameters) {
    ///PRODUCTION
    ///COMMA STRING stringList | lambda

    CheckTerminal( COMMA);
    tokenPosition++;

    CheckTerminal( STRING);
    PlainParameter* parameter = new PlainParameter();
    parameter->SetValue(tokens.at(tokenPosition)->GetInput());
    tokenPosition++;

    parameters->push_back(parameter);

    //checks follow-set of ParseStringList
    if (tokens.at(tokenPosition)->GetTokenType() != RIGHT_PAREN) {
        ParseStringList(parameters);
    }
}

void Parser::ParseRule() {
    ///PRODUCTION
    ///headPredicate COLON_DASH predicate predicateList PERIOD
    Rule* rule = new Rule();

    //checks follow-set of headPredicate
    if (tokens.at(tokenPosition)->GetTokenType() != COLON_DASH) {
        rule->AddHeadPredicate(ParseHeadPredicate());
    }

    CheckTerminal( COLON_DASH);
    tokenPosition++;

    //adds the first predicate to body predicates for our rule object
    rule->AddBodyPredicate(ParsePredicate());

//    checks follow-set of predicate
    if (tokens.at(tokenPosition)->GetTokenType() != PERIOD) {
        std::vector<Predicate*> predicates;
        ParsePredicateList(&predicates);

        for (int i=0; i<predicates.size(); i++) {
            rule->AddBodyPredicate(predicates.at(i));
        }
    }

    CheckTerminal( PERIOD);
    tokenPosition++;
    datalogProgram->AddRulePredicate(rule);
}

void Parser::ParseRuleList() {
    ///PRODUCTION
    ///rule ruleList | lambda
    ParseRule();

    //checks follow-set for ParseRuleList
    if (tokens.at(tokenPosition)->GetTokenType() != QUERIES) {
        ParseRuleList();
    }
}

Predicate* Parser::ParseHeadPredicate() {
    ///PRODUCTION
    ///ID LEFT_PAREN ID idList RIGHT_PAREN

    Predicate* headPredicate = new Predicate();

    // Check for ID and add
    CheckTerminal( ID);
    headPredicate->SetPredicateName(tokens.at(tokenPosition)->GetInput());
    tokenPosition++;

    // Check for left paren and skip
    CheckTerminal( LEFT_PAREN);
    tokenPosition++;

    // Check for parameter ID and add
    CheckTerminal( ID);
    PlainParameter* parameter = new PlainParameter();
    parameter->SetValue(tokens.at(tokenPosition)->GetInput());
    headPredicate->AddParameter(parameter);
    tokenPosition++;

    // Checks follow-set for idList
    if (tokens.at(tokenPosition)->GetTokenType() != RIGHT_PAREN) {
        std::vector<PlainParameter*> parameters;
        ParseIdList(&parameters);

        for (int i=0; i<parameters.size(); i++) {
            headPredicate->AddParameter(parameters.at(i));
        }
    }

    CheckTerminal( RIGHT_PAREN);
    tokenPosition++;

    return headPredicate;
}

void Parser::ParseParameterList(std::vector<Parameter*> *parameters) {
    ///PRODUCTION
    ///COMMA parameter parameterList | lambda
    CheckTerminal( COMMA);
    tokenPosition++;

    parameters->push_back(ParseParameter());

    //checks follows-Set of ParseParameterList();
    if (tokens.at(tokenPosition)->GetTokenType() != RIGHT_PAREN) {
        ParseParameterList(parameters);
    }
}

Predicate* Parser::ParsePredicate() {
    ///PRODUCTION
    ///ID LEFT_PAREN name parameterList RIGHT_PAREN
    Predicate* predicate = new Predicate();

    CheckTerminal( ID);
    predicate->SetPredicateName(tokens.at(tokenPosition)->GetInput());
    tokenPosition++;

    CheckTerminal( LEFT_PAREN);
    tokenPosition++;

    predicate->AddParameter(ParseParameter());

    if (tokens.at(tokenPosition)->GetTokenType() != RIGHT_PAREN) {
        std::vector<Parameter*> parameters;
        ParseParameterList(&parameters);

        for (int i=0; i<parameters.size(); i++) {
            predicate->AddParameter(parameters.at(i));
        }
    }

    CheckTerminal( RIGHT_PAREN);
    tokenPosition++;

    return predicate;
}

Parameter* Parser::ParseParameter() {
    ///PRODUCTION
    ///STRING | ID | expression
    PlainParameter* parameter = new PlainParameter;


    if (tokens.at(tokenPosition)->GetTokenType() == STRING) {
        tokenPosition++;
        parameter->SetValue(tokens.at(tokenPosition-1)->GetInput());
        return parameter;
    } else if (tokens.at(tokenPosition)->GetTokenType() == ID) {
        tokenPosition++;
        parameter->SetValue(tokens.at(tokenPosition-1)->GetInput());
        return parameter;
    } else if (tokens.at(tokenPosition)->GetTokenType() == LEFT_PAREN) {
        return ParseExpression();
    } else {
        throw tokens.at(tokenPosition);
    }
}

Parameter* Parser::ParseExpression() {
    ///PRODUCTION
    ///Left_Paren name operator name RIGHT_PAREN
    Expression* expression = new Expression();

    CheckTerminal( LEFT_PAREN);
    tokenPosition++;

    expression->SetLeftParameter(ParseParameter());

    ParseOperator();
    expression->SetOperator(tokens.at(tokenPosition)->GetInput());
    tokenPosition++;

    expression->SetRightParameter(ParseParameter());

    CheckTerminal( RIGHT_PAREN);
    tokenPosition++;

    return expression;
}

void Parser::ParseOperator() {
    ///PRODUCTION
    /// ADD | MULTIPLY

    if (tokens.at(tokenPosition)->GetTokenType() == ADD) {
        //tokenPosition++;
        //return tokens.at(tokenPosition-1)->GetInput();
    } else if (tokens.at(tokenPosition)->GetTokenType() == MULTIPLY){
        //tokenPosition++;
        //return tokens.at(tokenPosition-1)->GetInput();
    } else {
        throw tokens.at(tokenPosition);
    }
}

void Parser::ParsePredicateList(std::vector<Predicate*> *predicates) {
    ///PRODUCTION
    ///COMMA predicate predicateList | lambda

    CheckTerminal( COMMA);
    tokenPosition++;

    predicates->push_back(ParsePredicate());

    //checks follow-set of predicateList
    if (tokens.at(tokenPosition)->GetTokenType() != PERIOD) {
        ParsePredicateList(predicates);
    }
}

void Parser::ParseQuery() {
    ///PRODUCTION
    ///predicate Q_MARK
    Predicate* predicate = nullptr;

    //checks follow-set of ParsePredicate
    if (tokens.at(tokenPosition)->GetTokenType() != Q_MARK) {
        predicate = ParsePredicate();
    }
    CheckTerminal(Q_MARK);
    tokenPosition++;

    datalogProgram->AddQueryPredicate(predicate);
}

void Parser::ParseQueryList() {
    ///PRODUCTION
    ///query queryList | lambda

    ParseQuery();

    //checks follow-set of ParseQueryList
    if (tokens.at(tokenPosition)->GetTokenType() != END_OF_FILE) {
        ParseQueryList();
    }
}

void Parser::CheckTerminal(TokenType tokenType) {
    if (tokens.at(tokenPosition)->GetTokenType() != tokenType) {
        //failed
        throw tokens.at(tokenPosition);
    } else {
        //Match-success do nothing.
    }
}

DatalogProgram *Parser::GetDatalogProgram() {
    return datalogProgram;
}

