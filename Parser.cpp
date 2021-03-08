//
// Created by justi on 2/23/2021.
//

#include <iostream>
#include "Parser.h"

Parser::Parser(){
    tokenPosition = 0;
    datalogProgramPointer = new DatalogProgram();
}

Parser::~Parser() {

}

void Parser::Parse(std::vector<Token*> tokens) {
    ParseDatalogProgram(tokens);
}

void Parser::ParseDatalogProgram(std::vector<Token*> tokens) {
    ///PRODUCTION
    ///NOTE: SCHEMES COLON scheme schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList EOF

    CheckTerminal(tokens, SCHEMES);
    tokenPosition++;
    CheckTerminal(tokens,COLON);
    tokenPosition++;
    ParseScheme(tokens);

    //checks follow-set of ParseSchemeList
    if (tokens.at(tokenPosition)->GetTokenType() != FACTS) {
        ParseSchemeList(tokens);
    }

    CheckTerminal(tokens, FACTS);
    tokenPosition++;
    CheckTerminal(tokens, COLON);
    tokenPosition++;

    //checks follow-set of ParseFactList
    if (tokens.at(tokenPosition)->GetTokenType() != RULES) {
        ParseFactList(tokens);
    }

    //TODO: parse Rules && ask TA for help on this. because I am very confused.
//
//    CheckTerminal(tokens, RULES);
//    tokenPosition++;
//    CheckTerminal(tokens, COLON);
//    tokenPosition++;
//
//    //checks follow-set of ruleList
//    if (tokens.at(tokenPosition)->GetTokenType() != QUERIES) {
//        ParseRuleList(tokens);
//    }

//    CheckTerminal(tokens, QUERIES);
//    CheckTerminal(tokens, COLON);
//    ParseQuery(tokens);
//
//    //checks follow-set of ParseQueryList
//    if (tokens.at(tokenPosition)->GetTokenType() != END_OF_FILE) {
//        ParseQueryList(tokens);
//    }
}

void Parser::ParseSchemeList(std::vector<Token*> tokens) {
    ///PRODUCTION
    ///scheme schemeList | lambda
    ParseScheme(tokens);

    if (tokens.at(tokenPosition)->GetTokenType() != FACTS) {
        ParseSchemeList(tokens);
    }

}

void Parser::ParseScheme(std::vector<Token*> tokens) {
    ///Production
    ///ID LEFT_PAREN ID idList RIGHT_PAREN

    Predicate* predicate = new Predicate();
    Parameter* parameter = new Parameter();

    CheckTerminal(tokens,ID);
    //Creating a predicate with the ID name
    predicate->AddPredicateName(tokens.at(tokenPosition)->GetInput());
    tokenPosition++;

    CheckTerminal(tokens,LEFT_PAREN);
    tokenPosition++;

    //Creating the first parameter of the predicate
    CheckTerminal(tokens,ID);
    parameter->AddParameter(tokens.at(tokenPosition)->GetInput());
    tokenPosition++;

    predicate->AddPredicateParameter(parameter);

    //checks follow-set of parseIdList
    if (tokens.at(tokenPosition)->GetTokenType() != RIGHT_PAREN) {
        //add each token to the schemePredicate vector
        ParseIdList(tokens, predicate);
    }

    CheckTerminal(tokens, RIGHT_PAREN);
    datalogProgramPointer->AddSchemePredicate(predicate);
    tokenPosition++;
}

void Parser::ParseIdList(std::vector<Token*> tokens, Predicate* predicate) {
    ///PRODUCTION
    ///COMMA ID idList | lambda

    Parameter* parameter = new Parameter();
    CheckTerminal(tokens,COMMA);
    tokenPosition++;
    CheckTerminal(tokens,ID);
    parameter->AddParameter(tokens.at(tokenPosition)->GetInput());
    predicate->AddPredicateParameter(parameter);
    tokenPosition++;

    //checks follows-Set of parseIdList
    if (tokens.at(tokenPosition)->GetTokenType() != RIGHT_PAREN) {
        ParseIdList(tokens, predicate);
    }
}

void Parser::ParseFactList(std::vector<Token*> tokens) {
    ///PRODUCTION
    ///fact factList | lambda

    ParseFact(tokens);
    //checks follow-Set of ParseFact
    if (tokens.at(tokenPosition)->GetTokenType() != RULES) {
        ParseFactList(tokens);
    }
}

void Parser::ParseFact(std::vector<Token*> tokens) {
    ///PRODUCTION
    ///ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
    Predicate* predicate = new Predicate();
    Parameter* parameter = new Parameter();

    CheckTerminal(tokens, ID);
    predicate->AddPredicateName(tokens.at(tokenPosition)->GetInput());
    tokenPosition++;
    CheckTerminal(tokens, LEFT_PAREN);
    tokenPosition++;
    CheckTerminal(tokens, STRING);
    parameter->AddParameter(tokens.at(tokenPosition)->GetInput());
    tokenPosition++;

    predicate->AddPredicateParameter(parameter);

    //checks follow-set of ParseStringList
    if (tokens.at(tokenPosition)->GetTokenType() != RIGHT_PAREN) {
        ParseStringList(tokens, predicate);
    }

    CheckTerminal(tokens, RIGHT_PAREN);
    tokenPosition++;
    CheckTerminal(tokens, PERIOD);
    tokenPosition++;

    datalogProgramPointer->AddFactPredicate(predicate);
}

void Parser::ParseStringList(std::vector<Token *> tokens, Predicate* predicate) {
    ///PRODUCTION
    ///COMMA STRING stringList | lambda
    Parameter* parameter = new Parameter();

    CheckTerminal(tokens, COMMA);
    tokenPosition++;
    CheckTerminal(tokens, STRING);
    parameter->AddParameter(tokens.at(tokenPosition)->GetInput());
    predicate->AddPredicateParameter(parameter);
    tokenPosition++;

    //checks follow-set of ParseStringList
    if (tokens.at(tokenPosition)->GetTokenType() != RIGHT_PAREN) {
        ParseStringList(tokens, predicate);
    }
}

void Parser::ParseRule(std::vector<Token *> tokens) {
    ///PRODUCTION
    ///headPredicate COLON_DASH predicate predicateList PERIOD

    Rule* rule = new Rule();

    //checks follow-set of headPredicate
    if (tokens.at(tokenPosition)->GetTokenType() != COLON_DASH) {
        ParseHeadPredicate(tokens, rule);
    }

    CheckTerminal(tokens, COLON_DASH);
    tokenPosition++;
    ParsePredicate(tokens);
    ParsePredicateList(tokens);
    CheckTerminal(tokens, PERIOD);
}


void Parser::ParseRuleList(std::vector<Token *> tokens) {
    ///PRODUCTION
    ///rule ruleList | lambda

    //checks follow-set for ParseRuleList
    if (tokens.at(tokenPosition)->GetTokenType() != QUERIES) {
        ParseRule(tokens);
    }
}

void Parser::ParseHeadPredicate(std::vector<Token *> tokens, Rule* rule) {
    ///PRODUCTION
    ///ID LEFT_PAREN ID idList RIGHT_PAREN
    CheckTerminal(tokens,ID);
    Predicate* headPredicate = new Predicate();
    headPredicate->AddPredicateName(tokens.at(tokenPosition)->GetInput());
    tokenPosition++;

    rule->AddHeadPredicate(headPredicate);

    CheckTerminal(tokens,LEFT_PAREN);
    tokenPosition++;
    CheckTerminal(tokens,ID);
    Parameter* headParameter = new Parameter();
    headParameter->AddParameter(tokens.at(tokenPosition)->GetInput());
    tokenPosition++;

    headPredicate->AddPredicateParameter(headParameter);

    //checks follow-set for idList
    if (tokens.at(tokenPosition)->GetTokenType() != RIGHT_PAREN) {
        ParseIdList(tokens, headPredicate);
    }

    CheckTerminal(tokens, RIGHT_PAREN);
    tokenPosition++;
    datalogProgramPointer->AddRulePredicate(rule);
}

void Parser::ParseParameterList(std::vector<Token *> tokens) {
    ///PRODUCTION
    ///COMMA parameter parameterList | lambda

    CheckTerminal(tokens, COMMA);
    tokenPosition++;
    ParseParameter(tokens);

    //checks follow-set of parameter
    if (tokens.at(tokenPosition)->GetTokenType() != RIGHT_PAREN) {
        ParseParameterList(tokens);
    }
}

void Parser::ParsePredicate(std::vector<Token *> tokens) {
    ///PRODUCTION
    ///ID LEFT_PAREN parameter parameterList RIGHT_PAREN

    Predicate* bodyPredicate = new Predicate();

    CheckTerminal(tokens, ID);
    bodyPredicate->AddPredicateName(tokens.at(tokenPosition)->GetInput());
    tokenPosition++;
    CheckTerminal(tokens, LEFT_PAREN);

    ParseParameter(tokens);

    //checks follow-set for ParsePredicateList
    if (tokens.at(tokenPosition)->GetTokenType() != PERIOD) {
        ParseParameterList(tokens);
    }

    CheckTerminal(tokens,RIGHT_PAREN);
}


void Parser::ParseParameter(std::vector<Token*> tokens) {
    ///PRODUCTION
    ///STRING | ID | expression
    Parameter* bodyParameter = new Parameter();

    if (tokens.at(tokenPosition)->GetTokenType() == STRING) {
        bodyParameter->AddParameter(tokens.at(tokenPosition)->GetInput());
        tokenPosition++;
    } else if (tokens.at(tokenPosition)->GetTokenType() == ID) {
        bodyParameter->AddParameter(tokens.at(tokenPosition)->GetInput());
        tokenPosition++;
    } else if (tokens.at(tokenPosition)->GetTokenType() == LEFT_PAREN) {
        ParseExpression(tokens);
    } else {
        throw tokens.at(tokenPosition);
    }
}


void Parser::ParseExpression(std::vector<Token *> tokens) {
    ///PRODUCTION
    ///Left_Paren parameter operator parameter RIGHT_PAREN
    CheckTerminal(tokens,LEFT_PAREN);
    ParseParameter(tokens);
    ParseOperator(tokens);

    //checks follow-set of parameter
    if (tokens.at(tokenPosition)->GetTokenType() != RIGHT_PAREN) {
        ParseParameter(tokens);
    }

    CheckTerminal(tokens, RIGHT_PAREN);

}

void Parser::ParseOperator(std::vector<Token *> tokens) {
    ///PRODUCTION
    /// ADD | MULTIPLY

    if (tokens.at(tokenPosition)->GetTokenType() == ADD) {
        tokenPosition++;
    } else if (tokens.at(tokenPosition)->GetTokenType() == MULTIPLY){
        tokenPosition++;
    } else {
        throw tokens.at(tokenPosition);
    }
}

void Parser::ParsePredicateList(std::vector<Token *> tokens) {
    ///PRODUCTION
    ///COMMA predicate predicateList | lambda

    CheckTerminal(tokens, COMMA);
    ParsePredicate(tokens);

    //checks follow-set of predicateList
    if (tokens.at(tokenPosition)->GetTokenType() != PERIOD) {
        ParsePredicateList(tokens);
    }
}

void Parser::ParseQuery(std::vector<Token *> tokens) {
    ///PRODUCTION
    ///predicate Q_MARK

    //checks follow-set of ParsePredicate
    if (tokens.at(tokenPosition)->GetTokenType() != Q_MARK) {
        ParsePredicate(tokens);
    }
    CheckTerminal(tokens, Q_MARK);
}

void Parser::ParseQueryList(std::vector<Token *> tokens) {
    ///PRODUCTION
    ///query queryList | lambda

    ParseQuery(tokens);

    //checks follow-set of ParseQueryList
    if (tokens.at(tokenPosition)->GetTokenType() != END_OF_FILE) {
        ParseQueryList(tokens);
    }
}

void Parser::CheckTerminal(std::vector<Token*> tokens, TokenType tokenType) {
    if (tokens.at(tokenPosition)->GetTokenType() != tokenType) {
        //failed
        throw tokens.at(tokenPosition);
    } else {
        //Match-success do nothing.
    }
}

DatalogProgram *Parser::GetDatalogProgram() {
    return datalogProgramPointer;
}

