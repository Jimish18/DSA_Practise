/*
Question - Scramble String

Link - https://leetcode.com/problems/scramble-string/
*/

#include <bits/stdc++.h>
using namespace std;

unordered_map<string,bool> dp;
bool dfs(string s1,string s2)
{
    if(s1.length() == 1) return s1==s2;

    if(s1 == s2) return true;

    string key = s1+s2;
    if(dp.find(key) != dp.end()) return dp[key];

    // pruning : Avoid Unnecessary Recursion Calls
    int n = s1.length();
    vector<int> f1(26),f2(26);

    for(int i = 0 ; i < n ; i++)
    {
        f1[s1[i]-'a']++;
        f2[s2[i]-'a']++;
    }

    if(f1 != f2) return dp[key] = false;

    for(int i = 1 ; i < n ; i++)
    {
        if((dfs(s1.substr(0,i),s2.substr(0,i)) && dfs(s1.substr(i),s2.substr(i))) 
        || (dfs(s1.substr(0,i),s2.substr(n-i)) && dfs(s1.substr(i),s2.substr(0,n-i)))) 
        return dp[key] = true;
    }
    return dp[key] = false;
}

bool isScramble(string s1, string s2) 
{
    return dfs(s1,s2);   
}

int main()
{
    return 0;
}