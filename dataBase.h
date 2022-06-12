#ifndef DB_H_
#define DB_H_
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <mutex>
using namespace std;

class DB
{
    private:
    void initMap();
    static DB* database_;
    unordered_map<string,  float> map;
    void setValue(string, float);
    public:
    DB();
    mutex mtx;
    static DB* GetInstance();
    float getValue(string);
    void updateData(char*, int);
};

#endif //DB_H_