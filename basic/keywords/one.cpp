#include <iostream>
#include <string>
#include <cmath>

using namespace std;


// a - z : 0 - 25
int s2i(string str)
{
    int ans = 0;
    for (int i = str.size()-1; i >= 0; i--)
    {
        ans += (str[i] - 'a')*pow(26, str.size()-1-i);
    }
    return ans;
}


string i2s(int n)
{
    string temp;
    string ans;
    int z;
    int y;
    
    while (n!=0)
    {
        z = n / 26;
        y = n % 26;
        temp.push_back((char)('a' + y));
        n = z;
    }

    for (int i = 0; i < temp.size(); i++)
    {
        ans.push_back(temp[temp.size()-i-1]);
    }
    return ans;
}



int main()
{
    string a;
    string b;
    while (cin>>a>>b)
    {
        cout << i2s(s2i(a)+s2i(b)) <<endl;
    }
    system("pause");
    return 0;
}
