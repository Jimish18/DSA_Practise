/*
Question - Rod Cutting Problem

Link - https://www.codingninjas.com/codestudio/problems/800284?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
*/

#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int> &price, int n ,vector<vector<int>> &dp,int length)
{
    if(n <= 0 || n < length) return 0;

    if(dp[n][length] != -1) return dp[n][length];

    if(length <= n) return dp[n][length] = max((price[length-1] + dfs(price,n-length,dp,length)),dfs(price,n,dp,length+1));
    else return dp[n][length] = dfs(price,n,dp,length+1);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n+1,vector<int> (price.size()+1,-1));

    return dfs(price,n,dp,1);
}

int main()
{
    return 0;
}