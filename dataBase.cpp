#include "dataBase.h"

vector<string> paths = {
"/instrumentation/airspeed-indicator/indicated-speed-kt",
"/sim/time/warp",
"/controls/switches/magnetos",
"/instrumentation/heading-indicator/offset-deg",
"/instrumentation/altimeter/indicated-altitude-ft",
"/instrumentation/altimeter/pressure-alt-ft",
"/instrumentation/attitude-indicator/indicated-pitch-deg",
"/instrumentation/attitude-indicator/indicated-roll-deg",
"/instrumentation/attitude-indicator/internal-pitch-deg",
"/instrumentation/attitude-indicator/internal-roll-deg",
"/instrumentation/encoder/indicated-altitude-ft",
"/instrumentation/encoder/pressure-alt-ft",
"/instrumentation/gps/indicated-altitude-ft",
"/instrumentation/gps/indicated-ground-speed-kt",
"/instrumentation/gps/indicated-vertical-speed",
"/instrumentation/heading-indicator/indicated-heading-deg",
"/instrumentation/magnetic-compass/indicated-heading-deg",
"/instrumentation/slip-skid-ball/indicated-slip-skid",
"/instrumentation/turn-indicator/indicated-turn-rate",
"/instrumentation/vertical-speed-indicator/indicated-speed-fpm",
"/controls/flight/aileron",
"/controls/flight/elevator",
"/controls/flight/rudder",
"/controls/flight/flaps",
"/controls/engines/engine/throttle",
"/controls/engines/current-engine/throttle",
"/controls/switches/master-avionics",
"/controls/switches/starter",
"/engines/active-engine/auto-start",
"/controls/flight/speedbrake",
"/sim/model/c172p/brake-parking",
"/controls/engines/engine/primer",
"/controls/engines/current-engine/mixture",
"/controls/switches/master-bat",
"/controls/switches/master-alt",
"/engines/engine/rpm",

};

DB* DB::database_ = nullptr;

DB* DB::GetInstance(){
    
    if(database_==nullptr)
    {
        database_ = new DB();
    }
    return database_;
}


DB::DB()
{
    initMap();
}

void DB::initMap()
{
    for (auto key: paths)
    {
        map[key] = 0;
    }
}
void DB::setValue(string key, float val)
{
    mtx.lock();
    map[key] = val;
    mtx.unlock();
}

float DB::getValue(string key)
{
    mtx.lock();
    float result = map[key];
    mtx.unlock();
    return result;
}

void DB::updateData(char* buffer, int len)
{
    string text(buffer,len);

    vector<float> nums{};
    string delimiter = ",";
    size_t pos = 0;

    while ((pos = text.find(delimiter)) != string::npos) {
        nums.push_back(stod(text.substr(0, pos)));
        text.erase(0, pos + delimiter.length());
    }
    
    nums.push_back(stod(text.substr(0, pos)));
    //text.erase(0, pos/* + delimiter.length()*/);

    for (size_t i = 0; i < nums.size(); i++)
    {
        setValue(paths[i], nums[i]);
        //cout<<map[paths[i]]<<"\n";
    }
}