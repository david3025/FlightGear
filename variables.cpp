#include "variables.h"

bool Variables::theVarExists(string name)
{
    std::unordered_map<std::string, Var *>::iterator it;
    it = varTable.find(name);
    if (it != varTable.end()) 
    {
        return true;
    }
    return false;
}

Variables* Variables::GetInstance(){
    
    if(variables==nullptr)
    {
        variables = new Variables();
    }
    return variables;
}

Variables* Variables::variables= nullptr;

void Variables::addVar(string name,string path)
{
    Var* newVar = new Var(name, path);
    varTable[name] = newVar;

}
void Variables::addVar(string name,double number)
{
    Var* newVar = new Var(name, number);
    varTable[name] = newVar;

}

string Variables::getPath(string name)
{
    return varTable[name]->path;
}
/*
void Variables::sendToSimulator(string name, float value)
{
    varTable[name]->UpDateSimulator(value);
}

*/
float Variables::getValueFromDB(string name)
{
    return DB::GetInstance()->getValue(getPath(name));
}


Variables::~Variables()
{
    unordered_map<string, Var *>::iterator it = varTable.begin();
    while (it != varTable.end())
    {
        delete it->second;
        it++;
    }
}


/*
Var *Variables::getVar(string name)
{
    std::unordered_map<std::string, Var *>::iterator it;
    it = varTable.find(name);
    if (it != varTable.end()) 
    {
        return varTable[name];
    }
    else
    {
        return nullptr;
    }

}


*/


Var *Variables::getVar(string name)
{
    if (theVarExists(name)) 
    {
        return varTable[name];
    }
    
    return varTable["NULL"];
    
}
/*
string Variables::getValue(string name)
{
    Var * var = getVar(name);
    if (var->type == 1)
    {
        return to_string(getValueFromDB(name));
    }
    else if(var->type == 2)
    {
        return to_string(var->value);
    }
    else
    {
        return "ERROR";
    }
}*/

string Variables::getValue(string name)
{
    Var * var = getVar(name);
    if(var->name != "NULL")
    {
        if (var->type == 1)
        {
            return to_string(getValueFromDB(name));
        }
        else if(var->type == 2)
        {
            return to_string(var->value);
        }
    }
    
    return "ERROR";
    
}