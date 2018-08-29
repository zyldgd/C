/*
描述：
>> split("123-465-789","-")
   {"123", "456", "789"}


相关依赖:
#include <string>
#include <vector>

(trim.cpp)[https://github.com/zyldgd/C_CPP/edit/master/STL/string/trim.cpp]
*/

vector<string> split(string str, string pattern)
{
    vector<string> ans;
    str += pattern;
    int fIndex = str.find_first_of(pattern);
    while (-1 != fIndex)
    {
        string addStr = trim(str.substr(0, fIndex));
        if (!addStr.empty())
        {
            ans.push_back(addStr);
        }
        str.erase(0, fIndex + 1);
        fIndex = str.find_first_of(pattern);
    }
    return ans;
}
