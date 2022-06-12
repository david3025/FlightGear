#include "CMDConnectClient.h"


void launchFlightGearAPP();

void CMDConnectClient::doCommand(std::string strArgs)
{
    vector<string> splitArgs = Command::splitByDelimiter(strArgs, " ");
    Client* client =  Client::GetInstance(splitArgs[0],stoi(splitArgs[1]));
    client->app_thr = thread(launchFlightGearAPP);
    //Variables::GetInstance()->app_thr = std::thread(launchFlightGearAPP);
    sleep(10);
    client->Connect();
    
    //Client* client =  Client::GetInstance(splitArgs[0],stoi(splitArgs[1]));
};

// move to private
void launchFlightGearAPP()
{
    system("fgfs --telnet=socket,in,10,127.0.0.1,5402,tcp --generic=socket,out,10,127.0.0.1,9999,tcp,generic_small");
    sleep(15);
}




            

