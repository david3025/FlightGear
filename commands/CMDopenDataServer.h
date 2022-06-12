#ifndef OPENDATASERVERCMD_H_
#define OPENDATASERVERCMD_H_

#include "Command.h"
#include <thread>
#include "../Server.h"

class CMDopenDataServer:public Command
{
    public:
    void doCommand(std::string);
};
#endif //OPENDATASERVERCMD_H_