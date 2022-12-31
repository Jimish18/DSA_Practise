/*
Question - Unique Paths 2

Link - https://leetcode.com/problems/unique-paths-ii/
*/

#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& obstacleGrid,int i,int j,vector<vector<int>> &dp)
{
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0 || obstacleGrid[i][j] == 1) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = dfs(obstacleGrid,i-1,j,dp) + dfs(obstacleGrid,i,j-1,dp);
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
{
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size(); 

    vector<vector<int>> dp(n+1,vector<int> (m+1,-1));

    return dfs(obstacleGrid,n-1,m-1,dp);        
}

int main()
{
    return 0;
}