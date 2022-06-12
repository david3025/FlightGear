#ifndef PRINT_H_
#define PRINT_H_

#include "Command.h"
#include "../ShuntingYard.h"

class CMDprint : public Command 
{
 public:
  void doCommand(std::string );

};

#endif //PRINT_H_