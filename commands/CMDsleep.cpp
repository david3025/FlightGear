#include "CMDsleep.h"

void CMDsleep::doCommand(string arg) 
{
  cout <<"sleeping...("<<arg<<")\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(stoi(arg)));
}