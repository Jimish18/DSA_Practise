/*
Question - Super Egg Drop

Link - https://leetcode.com/problems/super-egg-drop/
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int k, int n,vector<vector<int>> &dp)
{
    if(n == 0 || n == 1) return n;
    if(k == 1) return n;

    if(dp[k][n] != -1) return dp[k][n];

    int mn = INT_MAX;
    
    int start = 1;
    int end = n;


    while(start <= end)
    {
        int mid = (start + end)/2;
        int left = solve(k-1,mid-1,dp);
        int right = solve(k,n-mid,dp);

        int temp = 1 + max(left,right);

        if(left < right) start = mid+1;
        else end = mid-1;

        mn = min(mn,temp);        
    }

    return dp[k][n] = mn;
}

int superEggDrop(int k, int n) 
{
    vector<vector<int>> dp(k+1 , vector<int> (n+1,-1));
    return solve(k,n,dp);      
}

int main()
{
    return 0;
}