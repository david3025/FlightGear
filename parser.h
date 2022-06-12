#ifndef PARSER_H_
#define PARSER_H_
using namespace std;
#include <unordered_map>
#include "vector"
#include "commands/Command.h"
#include "commands/CMDopenDataServer.h"
#include "commands/CMDConnectClient.h"
#include "commands/CMDvar.h"
#include "commands/CMDequal.h"
#include "commands/CMDsleep.h"
#include "commands/CMDwhile.h"
#include "commands/CMDprint.h"
 
class Parser {
  public:
  Parser();
  virtual ~Parser();
  void plyParser(vector<pair<string,string>> vectorFromLexer);
  private:
  void initMap();
  unordered_map<string, Command *> commandsMap; // TODO: should be private
 
};

#endif //PARSER_H_