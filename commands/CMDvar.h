#ifndef CMDVAR_H_
#define CMDVAR_H_

#include "Command.h"
#include "../expression.h"
#include<iostream>
using namespace std;


class CMDVar:public Command
{
    public:
    void doCommand(std::string);
};
#endif //CMDVAR_H_