#include "CMDopenDataServer.h"


void CMDopenDataServer::doCommand(std::string strArgs)
{
    std::vector<std::string> splitArgs = Command::splitByDelimiter(strArgs, " ");
    
    Server* server =  Server::GetInstance(stoi(splitArgs[0]));
    cout<<"open server"<<endl;
    server->openServer();
};