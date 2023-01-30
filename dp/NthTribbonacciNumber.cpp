/*
Question - Nth Tribonnacci Number

Link - https://leetcode.com/problems/n-th-tribonacci-number/
*/

#include <bits/stdc++.h>
using namespace std;

int dfs(int n , vector<int> &dp)
{
    if(dp[n] != -1) return dp[n];

    return dp[n] = dfs(n-3,dp) + dfs(n-2,dp) + dfs(n-1,dp);
}

int tribonacci(int n) 
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dfs(n,dp);
    return dp[n];        
}

int main()
{
    return 0;
}