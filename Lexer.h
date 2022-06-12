#ifndef LEXER_H_
#define LEXER_H_

using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <fstream>//is_open,getline
#include <algorithm>//count

class Lexer {
 public:
  Lexer(string fileName);
  Lexer(vector<string> &vec_from_while);
  vector<pair<string, string>> getSplitVector();

  private:
  void fileToVector(string filename, vector<string> &dest);
  void updateLexerVector(vector<string>&);
  void concatenateToStringWithSplit(const vector<string>& vec, char delim, string& s);
  vector<string> splitByDelimiter(string text,string delimiter);
  vector<pair<string, string>> lexerVector;
};

#endif //LEXER_H_
