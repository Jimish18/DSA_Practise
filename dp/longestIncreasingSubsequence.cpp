/*
Question - Longest Increasing Subsequence

Link - https://leetcode.com/problems/longest-increasing-subsequence/
*/

#include <bits/stdc++.h>
using namespace std;

// Memoization Method
int dfs(vector<int> &nums,int index,int prevIndex,vector<vector<int>> &dp,int n)
{
    if(index == n) return 0;

    if(dp[index][prevIndex+1] != -1) return dp[index][prevIndex+1];

    int length = 0 + dfs(nums,index+1,prevIndex,dp,n);

    if(prevIndex == -1 || nums[index] > nums[prevIndex])
    {
        length = max(length,1 + dfs(nums,index+1,index,dp,n));
    }   

    return dp[index][prevIndex+1] = length;

}

int lengthOfLIS(vector<int>& nums) 
{
    int n = nums.size();
    vector<vector<int>> dp(n,vector<int> (n+1,-1));

    return dfs(nums,0,-1,dp,n);    
}

int main()
{
    return 0;
}