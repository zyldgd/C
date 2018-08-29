/*
描述:
>> join({"123", "456"}, "---") 
   "123---456"

相关依赖:
#include <string>
#include <vector>

*/
string join(vector<string>strs, string pattern)
{
    if (strs.empty())
    {
        return "";
    }
    else if(strs.size()==1)
    {
        return strs.front();
    }
    else
    {
        string ans = strs.front();
        for (int i = 1; i<strs.size(); i++)
        {
            ans += " " + strs[i];
        }
        return ans;
    }
}
