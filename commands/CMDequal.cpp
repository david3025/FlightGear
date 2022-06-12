#include "CMDequal.h"

pair<string, string> splitByFirstWhitspace(string &s);

void CMDequal::doCommand(string s)
{
    pair<string, string> argument = splitByFirstWhitspace(s);
    string expression = argument.second;
    string destintion = argument.first;
    double valueToSend = Expression(expression).calculExpression();
    //float valueToSend = calculExpretion(expression);

    //cout << arg[0] << " = " << arg[1] << " = " << valueToSend<<endl;
    cout << destintion << " <--- " << expression<<endl;
    string path = Variables::GetInstance()->getVar(destintion)->path;

    std::string command = "set "+ path +" "+ to_string(valueToSend);
    Client::GetInstance("127.0.0.1", 5400)->sendData(command); // TODO: get instance of Client should not receive any parameters from the user after it was initialized in the Connect client command
}


pair<string, string> CMDequal::splitByFirstWhitspace(string &s)
{
    pair<string, string> res;
    string temp;
    size_t i = 0, len = s.length();
    while (s[i] != ' ' )
    {
        temp.push_back(s[i]);
        i++;
    }
    res.first = temp;
	temp = "";
    while (s[i] == ' ' )
    {
        i++;
    }
    while (i < len)
    {
        temp.push_back(s[i]);
        i++;
    }
    res.second = temp;
    return res;
}

/*
int main()


{
    std::string line1 = "wool (5*(throttle+2+h0-3)/4)";
    std::string line2 = "wool (-24/6)";
    std::string line3 = "throttle   ((throttle + h0) /2)";
    std::string line4 = "breaks ((throttle + h0) /2)";
    
    Variables *vars = Variables::GetInstance();
    vars->addVar("breaks","/controls/flight/speedbrake");
    vars->addVar("h0",3);
    vars->addVar("throttle","/controls/engines/engine/throttle");
    DB::GetInstance()->setValue("throttle",4);
    CMDequal equal;
    std::cout << equal.doCommand(line1);
    //std::vector<std::string> wordVector = equal.splitByOperators(line1);
}
    //std::cout<<"after split string to vector : "; 
    //equal.printVector(wordVector);
    //Shuntingyard sh;
    //std::cout<< sh.calculate(line2);
    //equal.convertVarsFromDB(wordVector);
    //equal.printVector(wordVector);
   // std::cout << equal.convertVectorToString(wordVector);
    //std::cout<<"after convert Vars From database  : ";
    equal.convertVarsFromDB(wordVector);
    //equal.printVector(wordVector);

    Variables *vars = Variables::GetInstance();
    vars->addVar("rudder", "/controls/flight/rudder");

    cout<<vars->getValueFromDB("rudder");

    std::string s;
    for (std::vector<std::string>::const_iterator i = wordVector.begin(); i != wordVector.end(); ++i)
        s += *i;
    //std::cout<<"after concatenate to string : "<< s<<std::endl;
    
    
    //std::cout<<"after concatenate to string : "<< s<<std::endl;
    return 0;
}

//g++ CMDequal.cpp Command.cpp ShuntingYard.cpp variables.cpp -pthread dataBase.cpp var.cpp Client.cpp 



*/