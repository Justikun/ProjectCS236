#include <iostream>
#include <sstream>

#include "Lexer.h"
#include "Parser.h"
#include "DatalogProgram.h"
#include "Token.h"

#include "string"

int main(int argc, char* argv[]) {

    //reads file input
    std::ifstream inputFile(argv[1]);

    //checks weather the file opened
    if(!inputFile) {
        std::cout << "File did not open\n";
        return 0;
    }

    //reads the file input into a string called inputString
    std::string inputString((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

    Lexer lexer = Lexer();

    lexer.Run(inputString);
//    lexer.printTokens();
//    lexer.printTokensSize();
    lexer.copyToOutPut();
    std::cout << std::endl;
    Parser parser = Parser(lexer.getTokensVector());

    try {
        parser.Parse();
    } catch (Token* token) {
        std::cout << "Failure!" << std::endl << "  ";
        token->PrintTokenAsString();
        std::cout << std::endl;
        //std::cout << "catch: " << token->GetInput() << std::endl;
    }

    DatalogProgram* datalogProgram = parser.GetDatalogProgram();

    datalogProgram->ToString();


    return 0;
}
