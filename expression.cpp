#include "expression.h"
vector<string> Expression::splitByOperators(string &inputString)
{
    vector<string> wordVector;
    stringstream stringStream(inputString);
    size_t prev = 0, pos;

    while ((pos = inputString.find_first_of(" +-*/()", prev)) != std::string::npos)
    {
        if (pos > prev)
            wordVector.push_back(inputString.substr(prev, pos-prev));
        
        prev = pos+1;

        if(inputString.at(pos) == ' ') continue;

        string temp_string(1,inputString.at(pos)); //TODO : explain this better at interview.
        wordVector.push_back(temp_string);
    }

    return wordVector;
}

bool Expression::isNumber(const string& str)
{
        for (char const &c : str) {
        if (std::isdigit(c) == 0 && c != '.' ) return false;
    }
    return true;
}

void Expression::convertVarsFromDB(vector<string>& vec)
{
    string operators = "-/*+()";
    
    for (size_t i = 0; i < vec.size(); i++)
    {

        if(!isNumber(vec[i]) && !strstr(operators.c_str(),vec[i].c_str())){

            Variables* variables = Variables::GetInstance();
            vec[i] = variables->getValue(vec[i]);
            
        }
    }
    
}
string Expression::convertVectorToString( std::vector<std::string> wordVector)
{
    string s;
    for (vector<string>::const_iterator i = wordVector.begin(); i != wordVector.end(); ++i){
        s += *i;
    }
    return s;
}
double Expression::calculExpression()
{
    if(isNumber(expression)) return stod(expression);

    expression = "(" +expression+ ")";
    vector<string> wordVector = splitByOperators(expression);
    convertVarsFromDB(wordVector);

    return Shuntingyard().calculate(convertVectorToString(wordVector));
}
