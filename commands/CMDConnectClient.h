#ifndef CONNECTCLIENTCMD_H_
#define CONNECTCLIENTCMD_H_

#include "Command.h"
#include <thread>

#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
class CMDConnectClient:public Command
{
    public:
    void doCommand(std::string);
};
#endif //CONNECTCLIENTCMD_H_

