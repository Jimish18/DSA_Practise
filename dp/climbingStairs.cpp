/*
Question - Climbing Stairs

Link - https://leetcode.com/problems/climbing-stairs/
*/


#include <bits/stdc++.h>
using namespace std;

int countAttemt(int n,vector<int> &dp)
{
    if(n <= 0) return;

    if(dp[n-1] != 0)
    {
        dp[n] = dp[n-1];
        return;
    } 

    if(n >= 2)
    {
        dp[n] = dp[n-1] + dp[n-2];
    }
    else if(n >= 1)
    {
        dp[n] = dp[n-1] + 1;
    }
}

int climbStairs(int n) 
{
    // Tabulation
    // vector<int> dp(n+2);
    // dp[0] = 0;
    // dp[1] = 1;
    // dp[2] = 2;

    // for(int i = 3; i < n+1; i++)
    // {
    //     dp[i] = dp[i-1]+dp[i-2];
    // }

    // Memoization
    vector<int> dp(n+2,-1);


    return dp[n];
}


int main()
{
    return 0;
}