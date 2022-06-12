#include "parser.h"

Parser::Parser()
{
    initMap();
}
void Parser::plyParser(vector<pair<string, string>> vectorFromLexer)
{
    size_t Size = vectorFromLexer.size();
    for (size_t i = 0; i < Size; i++)
    {
        string command = vectorFromLexer[i].first;
        string args = vectorFromLexer[i].second;

        if(commandsMap.count(command))
        {
            Command *cmd = commandsMap[command];
            cmd->doCommand(args);
        }
    }
}
void Parser::initMap()
{
    commandsMap["openDataServer"] = new CMDopenDataServer();
    commandsMap["connect"] = new CMDConnectClient();
    commandsMap["var"] = new CMDVar();
    commandsMap["="] = new CMDequal();
    commandsMap["sleep"] = new CMDsleep();
    commandsMap["while"] = new CMDwhile();
    commandsMap["print"] = new CMDprint();
}
Parser::~Parser()
{
    unordered_map<string, Command *>::iterator it = commandsMap.begin();
    while (it != commandsMap.end())
    {
        delete it->second;
        it++;
    }
}
