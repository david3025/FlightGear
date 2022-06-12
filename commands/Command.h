#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
#include <vector>
#include "../variables.h"

class Command {
 public:
 
  virtual void doCommand(std::string)= 0;// string arg /std::vector<std::string> vector, int index
  virtual ~Command();
  protected:
  vector<string> splitByDelimiter(string,string);
};

#endif //COMMAND_H_

