/*
Question - Print Longest Common Subsequence
*/

#include <bits/stdc++.h>
using namespace std;

string print(string s1,string s2,int i,int j,vector<vector<string>> &dp)
{
    if(i == 0 || j == 0) return "";

    if(dp[i][j] != "") return dp[i][j];

    if(s1[i-1] == s2[j-1])
    {
        return dp[i][j] +=  print(s1,s2,i-1,j-1,dp) + s1[i-1];
    }
    else
    {
        string temp1 = print(s1,s2,i,j-1,dp);
        string temp2 = print(s1,s2,i-1,j,dp);
        return dp[i][j] += temp1.length() > temp2.length() ? temp1 : temp2;        
    }

    return dp[i][j];
}

string printLCS(string s1,string s2)
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<string>> dp(n+1,vector<string> (m+1,""));

    return print(s1,s2,n,m,dp);
}

int main()
{
    string s1 = "acbcf";
    string s2 = "abcdaf";
    string result = printLCS(s1,s2);

    cout<<result<<endl;
    return 0;
}