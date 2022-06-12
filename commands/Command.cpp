#include "Command.h"
/*
int Command::doCommand(std::string arg)
{
    return 0;
}
*/
vector<string> Command::splitByDelimiter(string text,string delimiter)
  { 
      vector<string> words{};

      size_t pos = 0;
      while ((pos = text.find(delimiter)) != string::npos) {
          words.push_back(text.substr(0, pos));
          text.erase(0, pos + delimiter.length());
      }
      words.push_back(text.substr(0, pos));
      text.erase(0, pos + delimiter.length());
      return words;
  }
  Command::~Command(){};