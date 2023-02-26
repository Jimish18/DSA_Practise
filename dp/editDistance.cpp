/*
Question - Edit Distance
 
Link - https://leetcode.com/problems/edit-distance/
*/

#include <bits/stdc++.h>
using namespace std;

int dfs(string word1, string word2,int i,int j,vector<vector<int>> &dp)
{
    if(i < 0 || j < 0)
    {
        if(i < 0 && j < 0) return 0;
        else if(i < 0) return j+1;
        else if (j < 0) return i + 1;
    }

    if(dp[i][j] != -1) return dp[i][j];

    while(word1[i] == word2[j])
    {
        i--;j--;        
    }

    dp[i][j] = min(1 + dfs(word1,word2,i,j-1,dp) , min(1 + dfs(word1,word2,i-1,j,dp) , 1 + dfs(word1,word2,i-1,j-1,dp)));

    return dp[i][j];
}

int minDistance(string word1, string word2) 
{
    int result = 0;
    int n = word1.length();
    int m = word2.length();
    vector<vector<int>> dp(n+1,vector<int> (m+1,-1));

    return dfs(word1,word2,n-1,m-1,dp);
}

int main()
{
    return 0;