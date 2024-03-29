/*
Question - Perfect Squares 

Link - https://leetcode.com/problems/perfect-squares/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int solve(int n)
{
    if(n <= 3) return n;

    if(dp[n] != -1) return dp[n];

    int ans = n;

    for(int i = 1 ; i*i <= n; i++)
    {
        ans = min(ans,1+solve(n-i*i));
    }
    dp[n] = ans;

    return ans;    
}

int numSquares(int n) 
{
    dp.resize(n+1,-1);
    int ans = solve(n);

    return ans;
}

int main()
{
    return 0;
}