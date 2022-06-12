#include "CMDprint.h"

void CMDprint::doCommand(string arg) 
{
  
  //cout <<"len = "<<len<<endl;
  
  if(arg.at(0) == '"')
  {
      cout <<arg.substr(1, arg.size()-2)<<endl;
  }
  else
  {
      Variables *vars = Variables::GetInstance();
      string name = vars->getValue(arg);
      int res = name.compare("ERROR");
      if(res != 0)  cout << arg << " = " << name << endl;
      if(res == 0)  cout << arg << " = " << Shuntingyard().calculate(arg) << endl;
  }
}

