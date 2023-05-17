/*
Question - Shortest Common SuperSequence

Link - https://leetcode.com/problems/shortest-common-supersequence/
*/

#include <bits/stdc++.h>
using namespace std;

string dfs(string &str1, string &str2 , vector<vector<string>> &dp,int i,int j)
{
    if(i < 0) return str2.substr(0,(j-0));
    else if(j < 0) return str1.substr(0,(i-0));

    if(dp[i][j] != "") return dp[i][j];

    if(str1[i-1] == str2[j-1])
    {
        return dp[i][j] = dfs(str1,str2,dp,i-1,j-1) + str1[i-1];
    }
    else
    {
        string s1 = dfs(str1,str2,dp,i-1,j) + str1[i-1];
        string s2 = dfs(str1,str2,dp,i,j-1) + str2[j-1];

        return dp[i][j] = (s1.length() > s2.length()) ? s2 : s1;
    }

    return "";
}

string shortestCommonSupersequence(string str1, string str2) 
{
    int n = str1.length();
    int m = str2.length();
    vector<vector<string>> dp (n+1 , vector<string> (m+1,""));

    return dfs(str1,str2,dp,n,m);
}


int main()
{
    string s = "jimish";
    cout<<s.substr(0,-1)<<endl;
    return 0;
}