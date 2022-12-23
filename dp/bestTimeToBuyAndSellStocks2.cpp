/*
Question - Best Time to Buy and Sell Stock II

Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
*/

#include <bits/stdc++.h>
using namespace std;

int helper(vector<int>& prices,int buy,int index,vector<vector<int>> &dp)
{
    if(index >= prices.size()) return 0;

    if(dp[index][buy] != -1) return dp[index][buy];

    if(buy == 1)
    {
        return dp[index][buy] = max(-prices[index] + helper(prices,0,index+1,dp),
        0+helper(prices,1,index+1,dp));
    }

    return dp[index][buy] = max(prices[index] + helper(prices,1,index+1,dp) , 
    0 + helper(prices,0,index+1,dp));
}

int maxProfit(vector<int>& prices) 
{
    int n = prices.size();
    vector<vector<int>> dp(n+1,vector<int>(3,-1));
    return helper(prices,1,0,dp);
}