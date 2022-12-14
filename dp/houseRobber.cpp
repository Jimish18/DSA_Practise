/*
Question - House Robber

Link - https://leetcode.com/problems/house-robber/
*/

#include <bits/stdc++.h>
using namespace std;

int countRobbery(vector<int>& nums,int n,vector<int> &dp)
{
    if(n < 0) return 0;

    if(dp[n] != -1) return dp[n];

    return dp[n] = max(nums[n] + countRobbery(nums,n-2,dp) , countRobbery(nums,n-1,dp));
}

int rob(vector<int>& nums) 
{
    int n = nums.size();
    vector<int> dp(n,-1);

    countRobbery(nums,n-1,dp);

    return dp[n-1];
}


int main()
{
    return 0;
}