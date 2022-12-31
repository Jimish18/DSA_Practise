/*
Question - Coin Change 2

Link - https://leetcode.com/problems/coin-change-ii/
*/

#include <bits/stdc++.h>
using namespace std;

// Memoization Method =>
// int dfs(int amount, vector<int>& coins,int index,vector<vector<int>> &dp)
// {
//     if(amount == 0) return 1;
//     if(index == 0)
//     {
//         if(amount%coins[index] == 0) return 1;
//         else return 0;
//     }

//     if(dp[index][amount] != -1) return dp[index][amount];

//     if(coins[index] <= amount)
//     {
//         return dp[index][amount] = dfs(amount - coins[index],coins,index,dp) + dfs(amount,coins,index-1,dp);
//     }
//     else
//     {
//         return dp[index][amount] = dfs(amount,coins,index-1,dp);
//     }

//     return dp[index][amount];
// }

// int change(int amount, vector<int>& coins) 
// {
//     int n = coins.size();
//     vector<vector<int>> dp(n,vector<int> (amount+1,-1));

//     return dfs(amount,coins,n-1,dp);
// }

// Tabulation
int change(int amount, vector<int>& coins) 
{
    int n = coins.size();
    vector<vector<int>> dp(n,vector<int> (amount+1,0));

    for(int i = 0 ; i <= amount; i++)
    {
        if(i%coins[0] == 0) dp[0][i] = 1;
        else dp[0][i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j <= amount; j++)
        {
            if(coins[i] <= j)
            {
                dp[i][j] = dp[i][j-coins[i]] + dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n-1][amount];
}
int main()
{
    return 0;
}