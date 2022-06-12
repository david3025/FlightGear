#ifndef CONDITIONS_H_
#define CONDITIONS_H_

#include <iostream>
//#include "ShuntingYard.h"
#include "variables.h"
#include <sstream> //stringStream
#include <algorithm> // find


using namespace std;
class conditions
{
    public:
    conditions(){};
    ~conditions(){};
    //void print_condition();
    bool isConditionIsTrue(string stringOfCondition);
    protected:
    void removeFromString(string::iterator, string::iterator, char);

};

#endif //CONDITIONS_H_
