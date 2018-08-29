/*
描述：
>> trim("   123   ")
   "123"


相关依赖：
#include <string>
*/


string trim(string str)
{
    if (str.empty())
    {
        return str;
    }
    str.erase(0, str.find_first_not_of(" "));
    str.erase(str.find_last_not_of(" ") + 1);
    return str;
}
