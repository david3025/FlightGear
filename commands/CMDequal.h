#ifndef EQUALCMD_H_
#define EQUALCMD_H_

#include "Command.h"
#include "../Client.h"
#include "../expression.h"


class CMDequal:public Command
{
    public:
    void doCommand(string);
    private:
    pair<string, string> splitByFirstWhitspace(string &s);

    double calculExpretion(string);
    std::vector<std::string> splitByOperators(const std::string);
    bool isNumber(const std::string&);
    void convertVarsFromDB(std::vector<std::string>&);
    string convertVectorToString( std::vector<std::string>);
    //for testing
    void printVector(const std::vector<std::string>);
};
#endif //EQUALCMD_H_