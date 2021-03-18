#include <iostream>
#include <sstream>

#include "Lexer.h"
#include "Parser.h"
#include "DatalogProgram.h"
#include "Token.h"

#include "string"
#include "Database.h"
#include "Interpreter.h"
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
    Parser parser = Parser(lexer.getTokensVector());

    try {
        parser.Parse();

        DatalogProgram* datalogProgram = parser.GetDatalogProgram();
        //datalogProgram->ToString();

        Database* database = new Database();
        Interpreter* interpreter = new Interpreter(datalogProgram, database);
        interpreter->Run();
    } catch (Token* token) {
        std::cout << "Failure!" << std::endl << "  ";
        std::cout << "(" << token->GetTokenTypeName() << ",\"" << token->GetInput() << "\"," << token->GetLineNumber() << ")" << std::endl;
    }


    return 0;
}
