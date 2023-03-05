/*
Question - Jump Game II

Link - https://leetcode.com/problems/jump-game-ii/
*/

#include <bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) 
{
    int n = nums.size();
    int jumps = 0;
    int curReach = 0;
    int curMax = 0;

    for(int i = 0; i < n-1; i++)
    {
        if(i + nums[i] > curMax)
        {
            curMax = i+nums[i];
        }

        if(i == curReach)
        {
            jumps++;
            curReach = curMax;
        }
    }

    return jumps;
}

// Memoization
int dfs(vector<int> &nums,int index,vector<int> &dp)
{
    if(index >= nums.size()-1) return 0;

    if(dp[index] != -1) return dp[index];

    int minMoves = INT_MAX;

    for(int i = index+1; i <= index + nums[index]; i++)
    {
        minMoves = min(minMoves,1+dfs(nums,i,dp));
    }

    return dp[index] = minMoves;
    
}

int jump(vector<int>& nums) 
{
    int n = nums.size();
    vector<int> dp(n+1,-1);

    return dfs(nums,0,dp);
}

int main()
{
    return 0;
}