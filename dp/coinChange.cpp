/*
Question - Coin Change

Link - https://leetcode.com/problems/coin-change/
*/

#include <bits/stdc++.h>
using namespace std;


// Memoization Method =>

// int dfs(vector<int>& coins, int amount,int index,vector<vector<long long>> &dp)
// {
//     if(index == 0)
//     {
//         if(amount%coins[index] == 0) return amount/coins[index];
//         else return INT_MAX;
//     }

//     if(dp[index][amount] != -1) return dp[index][amount];
    
//     long long notTake = 0+dfs(coins,amount,index-1,dp);
//     long long take = INT_MAX;

//     if(coins[index] <= amount)
//     {
//         take = 1 + dfs(coins,amount - coins[index],index,dp)%10000000000;
//     }

//     dp[index][amount] = min(take,notTake);

//     return dp[index][amount];
// }

// int coinChange(vector<int>& coins, int amount) 
// {
//     vector<vector<long long>> dp(coins.size(),vector<long long> (amount+1,-1));
//     long long result = dfs(coins,amount,coins.size()-1,dp);

//     return (result > amount) ? -1 : result;
// }

// Tabulation Method
int coinChange(vector<int>& coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n,vector<int> (amount+1,0));

    for(int i = 0; i <= amount; i++)
    {
        if(i%coins[0] == 0)
        {
            dp[0][i] = i/coins[0];
        }
        else
        {
            dp[0][i] = INT_MAX;
        }
    }

    for(int i = 1 ; i < n; i++)
    {
        for(int j = 0; j <= amount; j++)
        {
            long long notTake = 0+dp[i-1][j];
            long long take = INT_MAX;

            if(coins[i] <= j)
            {
                take = 1 + dp[i][j-coins[i]]%10000000000;
            }

            dp[i][j] = min(take,notTake);
        }
    }

    return dp[n-1][amount];
}

int main()
{
    return 0;
}