#include "conditions.h"


bool conditions::isConditionIsTrue(string stringOfCondition)
{
    string DelimitierOfEqual = "==";
    string DelimitierOfBigOrEqual = ">=";
    string DelimitierOfSmallOrEqual = "<=";
    string DelimitierOfSmall = "<";
    string DelimitierOfBig = ">";
    string DelimitierOfNotEqual = "!=";
    int signOfOperator = -1;


    size_t limit = 0;
    string tokenOfFirsExpression, tokenOfSecondExpression;
    removeFromString(stringOfCondition.begin(), stringOfCondition.end(), ' ');
    //=
    if ((limit = stringOfCondition.find(DelimitierOfEqual)) != string::npos) 
    {

        tokenOfFirsExpression = stringOfCondition.substr(0, limit);
        tokenOfSecondExpression = stringOfCondition.substr(limit + 2, stringOfCondition.size() - 1);
        stringOfCondition.erase(0, limit + stringOfCondition.length());
        signOfOperator = 1;
    }
    //>=
    else if ((limit = stringOfCondition.find(DelimitierOfBigOrEqual)) != string::npos) 
    {

        tokenOfFirsExpression = stringOfCondition.substr(0, limit);
        tokenOfSecondExpression = stringOfCondition.substr(limit + 2, stringOfCondition.size() - 1);
        stringOfCondition.erase(0, limit + stringOfCondition.length());
        signOfOperator = 2;
    }
    //<=
    else if ((limit = stringOfCondition.find(DelimitierOfSmallOrEqual)) != string::npos)
   {
        tokenOfFirsExpression = stringOfCondition.substr(0, limit);
        tokenOfSecondExpression = stringOfCondition.substr(limit + 2, stringOfCondition.size() - 1);
        stringOfCondition.erase(0, limit + stringOfCondition.length());
        signOfOperator = 3;
    }
    //!=
    else if ((limit = stringOfCondition.find(DelimitierOfNotEqual)) != string::npos) 
    {
        tokenOfFirsExpression = stringOfCondition.substr(0, limit);
        tokenOfSecondExpression = stringOfCondition.substr(limit + 2, stringOfCondition.size() - 1);
        stringOfCondition.erase(0, limit + stringOfCondition.length());
        signOfOperator = 4;
    }
    //<
    else if ((limit = stringOfCondition.find(DelimitierOfSmall)) != string::npos) 
    {
       
        tokenOfFirsExpression = stringOfCondition.substr(0, limit);
        tokenOfSecondExpression = stringOfCondition.substr(limit + 1, stringOfCondition.size() - 1);
        //cout<<"condition: |"<<stringOfCondition<<"|\n"<<"limit: |"<<limit<<"|\n"<<"tokenOfFirsExpression |"<<tokenOfFirsExpression<<"|\n"<<"tokenOfSecondExpression |"<<tokenOfSecondExpression<<endl;
        stringOfCondition.erase(0, limit + stringOfCondition.length());
        signOfOperator = 5;
        
    }//>
    else if ((limit = stringOfCondition.find(DelimitierOfBig)) != string::npos) 
    {
        tokenOfFirsExpression = stringOfCondition.substr(0, limit);
        tokenOfSecondExpression = stringOfCondition.substr(limit + 1, stringOfCondition.size() - 1);
        stringOfCondition.erase(0, limit + stringOfCondition.length());
        signOfOperator = 6;
    }
    
    float valueOfVar = Variables::GetInstance()->getValueFromDB(tokenOfFirsExpression); // 3
    float num = stof(tokenOfSecondExpression);                                          // 10

    //cout << "\nvalueOfVar: "<<valueOfVar<<"\n"<<"num: "<<num<<"\n"<<"signOfOperator: "<<signOfOperator<<endl;
    switch (signOfOperator) {
        case 1: //==
            if (valueOfVar == num)
                return true;
            break;
        case 2: // >=
            if (valueOfVar >= num)
                return true;
            break;
        case 3: // <=
            if (valueOfVar <= num)
                return true;
            break;

        case 4: // <
            if (valueOfVar != num)
                return true;
            break;

        case 5: // >
            if (valueOfVar < num)
                return true;
            break;

        case 6: // !=
            if (valueOfVar > num)
                return true;
            break;
        default:break;
    }
    return false;
}

void conditions::removeFromString(string::iterator first, string::iterator last, char value)
{
    first = std::find(first, last, value);
    if (first != last)
        for(string::iterator i = first; ++i != last; )
            if (!(*i == value))
                *first++ = std::move(*i);
}
