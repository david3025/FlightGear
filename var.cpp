#include "var.h"

Var::Var(string name_, string path_):name(name_),path(path_),type(1){};
Var::Var(string name_, double value_):name(name_),value(value_),type(2){};


double Var::getValueFromDB()
{
    return DB::GetInstance()->getValue(name);
}

void Var::UpDateSimulator(double num)
{
    Client::GetInstance("127.0.0.1", 5402)->sendData("set "+ path + " " + to_string(num));
}