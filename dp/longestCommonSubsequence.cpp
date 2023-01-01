/*
Question - Longest Common Subsequence

Link - https://leetcode.com/problems/longest-common-subsequence/
*/

#include <bits/stdc++.h>
using namespace std;

// Tabulation Top-Down Approach
// int longestCommonSubsequence(string text1, string text2) 
// {
//     int m = text1.size(), n = text2.size();
//     int dp[m+1][n+1];
    
//     for(int i = 0; i <= m; i++) 
//     {
//         for(int j = 0; j <= n; j++) 
//         {
//             if(i == 0 || j == 0) dp[i][j] = 0; // one or more of the lengths is 0
//             else if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1]; // found a common character
//             else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // take the best of both scenarios
//         }
//     }
//     return dp[m][n];
// }

// Memoization Bottom-up Approach
int dfs(string text1, string text2,int i,int j,vector<vector<int>> &dp)
{
    if(i == 0 || j == 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(text1[i-1] == text2[j-1])
    {
        return dp[i][j] = 1 + dfs(text1,text2,i-1,j-1,dp);
    }
    else if(text1[i-1] != text2[j-1])
    {
        return dp[i][j] = max(dfs(text1,text2,i,j-1,dp),dfs(text1,text2,i-1,j,dp));
    }

    return dp[i][j];
}

int longestCommonSubsequence(string text1, string text2) 
{
    int n = text1.length();
    int m = text2.length();
    vector<vector<int>> dp(n+1,vector<int> (m+1,-1));

    return dfs(text1,text2,n,m,dp);        
}

int main()
{
    return 0;
}