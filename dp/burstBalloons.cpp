/*
Question - Burst Balloons 

Link - https://leetcode.com/problems/burst-balloons/description/
*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums,int prev , int cur ,int next)
{   
    int n = nums.size();
    if(cur >= n) return 0;
    if(cur < 0) return 0;

    int take1 = (((prev < 0) ? 1 : nums[prev])*(nums[cur])*((next >= n) ? 1 : nums[next])) + solve(nums,prev,cur+1,next+1);
    int take2 = (((prev < 0) ? 1 : nums[prev])*(nums[cur])*((next >= n) ? 1 : nums[next])) + solve(nums,prev-1,cur-1,next)

    int notTake = solve(nums,prev+1,cur+1,next+1);

    return max(max(take1,take2),notTake);
}

int maxCoins(vector<int>& nums) 
{
    return solve(nums,-1,0,1);
}

int main()
{
    return 0;
}