#ifndef VAR_H_
#define VAR_H_

using namespace std;
#include <string>
#include "Client.h"
#include "dataBase.h"
#include <thread>
/*
class Var {
 public:
 
  virtual int getVal(std::string)= 0;// string arg /std::vector<std::string> vector, int index
  virtual ~Var();
  protected:
};
*/

class Var {
  public:
  Var(string, double);   // var ___ = ____
  Var(string, string);  // var ___ = bind ___
  string name;
  string path;
  double value;
  int type; // 1 : bind, 2:var
  

  double getValueFromDB();
  void UpDateSimulator(double);
  
};
#endif //VAR_H_


// אולי לשנות למערך מסוג 1 ומערך מסוג שני על פי 2 הבנאים ???!!
//או שמא לעשות את וואר אבסטרקטי וממנו יורשים שני סוגי וואר???!!
