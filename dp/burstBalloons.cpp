/*
Question - Burst Balloons 

Link - https://leetcode.com/problems/burst-balloons/description/
*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums,int i,int j,vector<vector<int>> &dp)
{   
    if(i > j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mx = INT_MIN;

    for(int k = i; k <= j; k++)
    {
        int tempAns = solve(nums,i,k-1,dp) + solve(nums,k+1,j,dp) + (nums[i-1]*nums[k]*nums[j+1]) ;

        mx = max(mx,tempAns);
    }

    return dp[i][j] = mx;
}

int maxCoins(vector<int>& nums) 
{
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(),1);
    vector<vector<int>> dp(n+2 , vector<int> (n+2, -1));

    return solve(nums,1,n,dp);
}

int main()
{
    return 0;
}