/*
Question - Egg Drop With 2 Eggs and N Floors


Link - https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/description/
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int n,int e,vector<vector<int>> &dp)
{
    if(n == 0 || n == 1) return n;
    if(e == 1) return n;

    if(dp[n][e] != -1) return dp[n][e];

    int mn = INT_MAX;

    for(int k = 1; k <= n; k++)
    {
        int temp = 1 + max(solve(k-1,e-1,dp),solve(n-k,e,dp));

        mn = min(temp,mn);
    }

    return dp[n][e] = mn;
}

int twoEggDrop(int n) 
{
    vector<vector<int>> dp(n+1 , vector<int> (3 , -1));
    return solve(n,2,dp);
}

int main()
{
    return 0;
}