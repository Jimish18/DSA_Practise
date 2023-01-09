/*
Question - Longest Common Substring

Link - https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
*/

#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstr (string S1, string S2, int n, int m)
{
    vector<vector<int>> dp(n+1,vector<int> (m+1));    
    int len = 0;

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <=m; j++)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(S1[i-1] == S2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                len = max(len,dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }    
    return len;
}

int main()
{

    return 0;
}