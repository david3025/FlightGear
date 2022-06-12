#include "parser.h"
#include "Lexer.h"


//whiletext
int main()
{
    Lexer *lexer = new Lexer("textFile.txt");
    Parser *parser = new Parser();
    parser->plyParser(lexer->getSplitVector());

    delete lexer;
    delete parser;
   }

/*
g++ main.cpp Client.cpp CMDConnectClient.cpp CMDopenDataServer.cpp CMDvar.cpp Command.cpp dataBase.cpp Lexer.cpp parser.cpp Server.cpp var.cpp variables.cpp CMDequal.cpp ShuntingYard.cpp CMDsleep.cpp CMDwhile.cpp conditions.cpp  -pthread 
 */
