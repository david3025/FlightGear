#include "CMDvar.h"

void CMDVar::doCommand(std::string strArgs)
{
    vector<string> args = Command::splitByDelimiter(strArgs, " ");
    
    string left_name = args[0];

    Variables *variables = Variables::GetInstance();

    if (!args[2].compare("bind")) /// segmention falt   rudder = bind "/controls/flight/rudder"
    {
        string path = args[3];
        size_t len = path.size();

        //remove "" from begin and end
        path.erase(0,1);
        path.erase(len-2,1);

        variables->addVar(left_name, path);
        cout <<"\nCMDvar (bind): "<<left_name<<" <---- "<<path<<endl;
    }
    else if(!args[1].compare("="))                                                //h0 = heading
    {
        args = Command::splitByDelimiter(strArgs, "=");
        //string right_name = args[2];
        double value = Expression(args[1]).calculExpression();
        //float value = variables->getValueFromDB(right_name);
        variables->addVar(left_name, value);
        cout <<"\nCMDvar (var): "<<left_name<<" = "<<value<<endl;
    }

}
