/*
Question - Triangle

Link - https://leetcode.com/problems/triangle/
*/

#include <bits/stdc++.h>
using namespace std;

// Memoization
// int dfs(vector<vector<int>>& triangle,int i,int j,int n,vector<vector<int>> &dp)
// {
//     if(i == n-1) return triangle[i][j];

//     if(dp[i][j] != -1) return dp[i][j];

//     return dp[i][j] = triangle[i][j] + min(dfs(triangle,i+1,j,n,dp),dfs(triangle,i+1,j+1,n,dp));

// }

// int minimumTotal(vector<vector<int>>& triangle) 
// {
//     int n = triangle.size();
//     int m = triangle[n-1].size();
//     vector<vector<int>> dp(n+1,vector<int> (m+1,-1));

//     return dfs(triangle,0,0,n,dp);        
// }

// Tabulation
int minimumTotal(vector<vector<int>>& triangle) 
{
    int n = triangle.size();
    int m = triangle[n-1].size();
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));

    for(int i = n-1 ; i >= 0 ; i--)
    {
        for(int j = 0; j <= i; j++)
        {
            dp[i][j] = triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
        }
    }

    return dp[0][0];        
}

int main()
{
    return 0;
}