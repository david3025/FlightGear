

#ifndef EXPRESSION_H_
#define EXPRESSION_H_
#include <sstream>
#include <vector>
#include "ShuntingYard.h"
#include "variables.h"

class Expression
{
    public:
    Expression(string exp):expression(exp){};
    ~Expression(){};
    double calculExpression();

    private:
    string expression;
    string convertVectorToString( vector<string>);
    void convertVarsFromDB(vector<string>&);
    bool isNumber(const string&);
    vector<string> splitByOperators(string &);
};
#endif //EXPRESSION_H_