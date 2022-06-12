#include "CMDwhile.h"

void CMDwhile::doCommand(std::string strArgs)
{   
    vector<string> vec = Command::splitByDelimiter(strArgs,"$");

    string condition = vec[0];
    vec.erase(vec.begin());

    bool isCondIsTrue = conditions().isConditionIsTrue(condition);

    vector<pair<string,string>> lexer_vector = Lexer(vec).getSplitVector();
    Parser *subParser = new Parser();

    while(isCondIsTrue)
    {
        subParser->plyParser(lexer_vector);

        isCondIsTrue = conditions().isConditionIsTrue(condition);
    }

    delete subParser;
}