/*
Question - Find The Substring With Maximum Cost

Link - https://leetcode.com/problems/find-the-substring-with-maximum-cost/description/
*/

#include <bits/stdc++.h>
using namespace std;

int maximumCostSubstring(string s, string chars, vector<int>& vals) 
{
    vector<int> mapp(26);
    for(int i = 0; i < 26; i++) mapp[i] = i+1;

    for(int i = 0; i < vals.size(); i++)
    {
        mapp[chars[i]-'a'] = vals[i];
    }       

    vector<int> calc(s.length());

    for(int i = 0; i < s.length(); i++)
    {
        calc[i] = mapp[s[i]-'a'];
    }

    int ans = 0;
    int temp = 0;

    for(int i = 0; i < calc.size(); i++)
    {
        temp += calc[i];

        if(temp < 0) temp = 0;

        ans = max(ans,temp);
    }

    return ans;
}

int main()
{
    return 0;
}