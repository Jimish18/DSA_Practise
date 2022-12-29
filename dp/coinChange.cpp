/*
Question - Coin Change

Link - https://leetcode.com/problems/coin-change/
*/

#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int>& coins, int amount, vector<vector<int>> &dp,int index)
{
    if(amount == 0) return 0;
    if(index == coins.size()-1) return 0;


    if(dp[index][amount] != -1) return dp[index][amount];

    if(coins[index] <= amount)
    {
        return dp[index][amount] = min(1+dfs(coins,amount-coins[index],dp,index),dfs(coins,amount,dp,index+1));
    }
    else
    {
        return dp[index][amount] = dfs(coins,amount,dp,index+1);
    }

    return dp[coins.size()][amount];
}

int coinChange(vector<int>& coins, int amount) 
{
    int n = coins.size();
    vector<int> temp(amount+1,-1);
    vector<vector<int>> dp(n+1,temp);

    return dfs(coins,amount,dp,0);
}

int main()
{
    return 0;
}