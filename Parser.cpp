//
// Created by justi on 2/23/2021.
//

#include <iostream>
#include "Parser.h"

Parser::Parser(){
    tokenPosition = 0;
}

Parser::~Parser() {

}

void Parser::Parse(std::vector<Token*> tokens) {
    ParseDatalogProgram(tokens);
//    std::cout << "SUCCESS";
}

void Parser::ParseDatalogProgram(std::vector<Token*> tokens) {
    ///PRODUCTION
    ///NOTE: SCHEMES COLON scheme schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList EOF

    CheckTerminal(tokens, SCHEMES);
    CheckTerminal(tokens,COLON);
    ParseScheme(tokens);
    //checks follow-set of ParseSchemeList
    if (tokens.at(tokenPosition)->GetTokenType() != FACTS) {
        ParseSchemeList(tokens);
    }

    CheckTerminal(tokens, FACTS);
    CheckTerminal(tokens, COLON);
    //checks follow-set of ParseFactList
    if (tokens.at(tokenPosition)->GetTokenType() != RULES) {
        ParseFactList(tokens);
    }

    CheckTerminal(tokens, RULES);
    CheckTerminal(tokens, COLON);
    //checks follow-set of ruleList
    if (tokens.at(tokenPosition)->GetTokenType() != QUERIES) {
        ParseRuleList(tokens);
    }

    CheckTerminal(tokens, QUERIES);
    CheckTerminal(tokens, COLON);
    ParseQuery(tokens);

    //checks follow-set of ParseQueryList
    if (tokens.at(tokenPosition)->GetTokenType() != END_OF_FILE) {
        ParseQueryList(tokens);
    }

    std::cout << "Success!" << std::endl;

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
<<<<<<< HEAD

    //Creating a predicate with the ID name
    Predicate *predicate = new Predicate();
    std::vector<Predicate*> parameters;
    CheckTerminal(tokens,ID);
    predicate->AddPredicateName(tokens.at(tokenPosition-1)->GetInput());
=======
    CheckTerminal(tokens,ID);
>>>>>>> parent of 2713c90 (project2 part one running smoothly)
    CheckTerminal(tokens,LEFT_PAREN);

    //Creating the first parameter of the predicate
    CheckTerminal(tokens,ID);
    std::string parameterString = tokens.at(tokenPosition-1)->GetInput();
    Parameter *parameter = new Parameter();
    parameter->AddParameter(parameterString);

    //Adding parameter to predicate
    predicate->AddPredicateParameter(parameter);

    //checks follow-set of parseIdList
    if (tokens.at(tokenPosition)->GetTokenType() != RIGHT_PAREN) {
        //add each token to the schemePredicate vector
        ParseIdList(tokens);
    }

    CheckTerminal(tokens, RIGHT_PAREN);
<<<<<<< HEAD
    parameters.push_back(predicate);
=======
>>>>>>> parent of 2713c90 (project2 part one running smoothly)
}

Parameter* Parser::ParseIdList(std::vector<Token*> tokens) {
    ///PRODUCTION
    ///COMMA ID idList | lambda

    //TODO: CONVERT THIS FUNCTION TO RETURN THE PARAMETER WHICH ADDS IT TO A SCHEME Parameter VECTOR
    // , THEN THE VECTOR IS THEN PUSHED TO CREATE A PREDICATE OBJECT

    CheckTerminal(tokens,COMMA);
    CheckTerminal(tokens,ID);
    std::string parameterString = tokens.at(tokenPosition-1)->GetInput();

    Parameter *parameter = new Parameter();
    parameter->AddParameter(parameterString);

    //checks follows-Set of parseIdList
    if (tokens.at(tokenPosition)->GetTokenType() != RIGHT_PAREN) {
        ParseIdList(tokens);
        return parameter;
    }

}

void Parser::ParseFactList(std::vector<Token *> tokens) {
    ///PRODUCTION
    ///fact factList | lambda

    ParseFact(tokens);
    //checks follow-Set of ParseFact
    if (tokens.at(tokenPosition)->GetTokenType() != RULES) {
        ParseFactList(tokens);
    }
}

void Parser::ParseFact(std::vector<Token *> tokens) {
    ///PRODUCTION
    ///ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD

    CheckTerminal(tokens, ID);
    CheckTerminal(tokens, LEFT_PAREN);
    CheckTerminal(tokens, STRING);
    //checks follow-set of ParseStringList
    if (tokens.at(tokenPosition)->GetTokenType() != RIGHT_PAREN) {
        ParseStringList(tokens);
    }
    CheckTerminal(tokens, RIGHT_PAREN);
    CheckTerminal(tokens, PERIOD);
}

void Parser::ParseStringList(std::vector<Token *> tokens) {
    ///PRODUCTION
    ///COMMA STRING stringList | lambda
    CheckTerminal(tokens, COMMA);
    CheckTerminal(tokens, STRING);

    //checks follow-set of ParseStringList
    if (tokens.at(tokenPosition)->GetTokenType() != RIGHT_PAREN) {
        ParseStringList(tokens);
    }
}

void Parser::ParseRule(std::vector<Token *> tokens) {
    ///PRODUCTION
    ///headPredicate COLON_DASH predicate predicateList PERIOD

    //checks follow-set of headPredicate
    if (tokens.at(tokenPosition)->GetTokenType() != COLON_DASH) {
        ParseHeadPredicate(tokens);
    }

    CheckTerminal(tokens, COLON_DASH);
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

void Parser::ParseHeadPredicate(std::vector<Token *> tokens) {
    ///PRODUCTION
    ///ID LEFT_PAREN ID idList RIGHT_PAREN
    CheckTerminal(tokens,ID);
    CheckTerminal(tokens,LEFT_PAREN);
    CheckTerminal(tokens,ID);

    //checks follow-set for idList
    if (tokens.at(tokenPosition)->GetTokenType() != RIGHT_PAREN) {
        ParseIdList(tokens);
    }

    CheckTerminal(tokens, RIGHT_PAREN);
}

void Parser::ParsePredicate(std::vector<Token *> tokens) {
    ///PRODUCTION
    ///ID LEFT_PAREN parameter parameterList RIGHT_PAREN

    CheckTerminal(tokens, ID);
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

    if (tokens.at(tokenPosition)->GetTokenType() == STRING) {
        tokenPosition++;
    } else if (tokens.at(tokenPosition)->GetTokenType() == ID) {
        tokenPosition++;
    } else if (tokens.at(tokenPosition)->GetTokenType() == ID) {
        ParseExpression(tokens);
    } else {
        throw tokens.at(tokenPosition);
    }
}

void Parser::ParseParameterList(std::vector<Token *> tokens) {
    ///PRODUCTION
    ///COMMA parameter parameterList | lambda

    CheckTerminal(tokens, COMMA);
    ParseParameter(tokens);

    //checks follow-set of parameter
    if (tokens.at(tokenPosition)->GetTokenType() != RIGHT_PAREN) {
        ParseParameterList(tokens);
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
        //Match-success
        tokenPosition++;
    }
}

