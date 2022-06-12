#ifndef SLEEP_H_
#define SLEEP_H_
#include <chrono>
#include <thread>
#include "Command.h"

class CMDsleep : public Command 
{
 public:
  void doCommand(std::string );

};

#endif //SLEEP_H_


