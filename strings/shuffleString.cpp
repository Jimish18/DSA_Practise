#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    string restoreString(string s, vector<int>& indices) 
    {
        vector<char> v;
        char array[s.length()];
        
        for(int i = 0 ; i < s.length() ; i++)
        {
            array[indices[i]] = s[i];
        }

        string res = "";

        for(int i = 0 ; i < s.length(); i++)
        {
            res += array[i];
        }

        return res;
    }
};

int main()
{   
    vector<int> indices = {0,1,2};
    Solution s;
    cout<<s.restoreString("abc",indices)<<endl;

    return 0;
}