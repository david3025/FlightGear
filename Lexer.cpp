#include "Lexer.h"


Lexer::Lexer(string fileName)
{
  vector<string> vec;
  fileToVector(fileName, vec);
  updateLexerVector(vec);
}

Lexer::Lexer(vector<string> &vec_from_while)
{
  updateLexerVector(vec_from_while);
}

void Lexer::fileToVector(string fileName, vector<string> & vector)
{
    ifstream in;
    in.open(fileName.c_str());

    if(!in)
    {
        cerr << "cannot open the File : "<<fileName<<endl;
    }
    string buffer;
    while (getline(in, buffer))
    {
       vector.push_back(buffer);
    }
    in.close();
}

void Lexer::updateLexerVector(vector<string>& vec)
{
  vector<string> tableOfCommands = 
  {"openDataServer", "connect", "var", "=", "sleep", "print"};

  size_t i = 0, size = vec.size();

  while (i < size)
  {
      string line = vec[i], command = "",args = "";

      vector<string> lineSplit = splitByDelimiter(line, " ");

      if (count(tableOfCommands.begin(), tableOfCommands.end(), lineSplit[0]))
      {
        command = lineSplit[0];
        lineSplit.erase(lineSplit.begin());
        concatenateToStringWithSplit(lineSplit, ' ', args);
      }

      else if(count(tableOfCommands.begin(), tableOfCommands.end(), lineSplit[1])) // " = "
      {
        command = "=";
        lineSplit = splitByDelimiter(line, "=");
        args = lineSplit[0] + " " + lineSplit[1];
      }

      else if(lineSplit[0] == "while")
      {
          command = "while";
          size_t size = vec[i].size();
          string tempStr = vec[i].substr(6, size-8);
          args += tempStr;
          i++;
          size_t numOfCurlyBrackets = 1;

          while (numOfCurlyBrackets)
          {
            if((vec[i] == "{"))
            {
                numOfCurlyBrackets++;
                i++;
            }
            else if((vec[i] == "}"))
            {
                numOfCurlyBrackets--;
                i++;
            }
            else
            {
                size = vec[i].size();
                tempStr = "$" + vec[i].substr(4, size);
                args += tempStr;
                i++;
            }
          }
      }

      lexerVector.push_back({command, args});
      i++;
  }
}

vector<pair<string,string>> Lexer::getSplitVector()
{
  return lexerVector;
}


vector<string> Lexer::splitByDelimiter(string text,string delimiter)
{ 
    vector<string> words{};
    size_t pos = 0;

    while ((pos = text.find(delimiter)) != string::npos)
    {
        words.push_back(text.substr(0, pos));
        text.erase(0, pos + delimiter.length());
    }
    words.push_back(text.substr(0, pos));
    return words;
}


void Lexer::concatenateToStringWithSplit(const vector<string>& vec, char delim, string& s)
{
    for (vector<string>::const_iterator str_iter = vec.begin(); str_iter != vec.end(); ++str_iter)
    {
        s += (*str_iter);

        if ( str_iter + 1 != vec.end() )
        {
            s += delim;
        }
    }
}

// {1,2,3,4} 7
//
//  0 1 2 3 4 5 6 7
//0 1 0 0 0 0 0 0 0
//1 1 1 0 0 0 0 0 0         
//2 1 1 1 1 0 _ 0 _     
//3 1 1 1 1 1 1 0 _       
//4 1 1 1 1 1 1 1 1       
//


/*
void Lexer::testLexer()
{
   size_t size = lexerVector.size();
   for (size_t i = 0; i < size; i++) {
    cout <<i<<") "<< "fitst:"<<lexerVector[i].first<<"|"<<"\n\tsecond:"<<lexerVector[i].second <<"|"<< endl;
  }
}
vector<pair<string,string>> Lexer::getSplitVector()
{
  return lexerVector;
}
*/
