#ifndef VARIABLES_H_
#define VARIABLES_H_

using namespace std;
#include "var.h"
#include "dataBase.h"
#include<unordered_map>
class Variables {
  public:
  static Variables *GetInstance();
  void addVar(string ,string);                      // var "name" = bind ___ 
  void addVar(string ,double );            // var ____ = 4
  float getValueFromDB(string);                     // = "name" - 4
  string getValue(string); //to convert expretion in equal command
  Var *getVar(string);

  private:
  Variables(){addVar("NULL","NULL");};
  ~Variables();
  bool theVarExists(string);
  string getPath(string);
  static Variables *variables;
  unordered_map<string, Var *> varTable;
};
#endif //VARIABLES_H_

