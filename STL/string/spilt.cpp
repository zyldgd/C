/*
相关依赖

#include <string>
#include <vector>
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
