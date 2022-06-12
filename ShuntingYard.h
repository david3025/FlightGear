#ifndef ShuntingYard_H_
#define ShuntingYard_H_

#include <iostream>
#include <sstream>
#include <list>
#include <stack>
#include <map>
#include <string>
#include <vector>
#include <iterator>
#include <stdlib.h>
#include <string>

using namespace std;

class Shuntingyard
{
    private:
    bool isParenthesis(const string& token);
    bool isOperator(const string& token);
    bool isAssociative(const string& token, const int& type);
    int cmpPrecedence(const string& token1, const string& token2);
    bool infixToRPN(const vector<string>& inputTokens,
                 vector<string>& strArray);
    std::vector<string> getExpressionTokens( const string& expression);
    public:
    Shuntingyard(){};
    ~Shuntingyard(){};
    double calculate( const string& expression);
};
#endif //ShuntingYard_H_