#ifndef CMDWHILE_H_
#define CMDWHILE_H_

#include "Command.h"
#include "../conditions.h"
#include<iostream>
#include "../Lexer.h"
#include "../parser.h"
using namespace std;


class CMDwhile:public Command
{
    public:
    void doCommand(std::string);
};
#endif //CMDWHILE_H_

