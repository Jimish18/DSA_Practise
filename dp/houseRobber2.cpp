/*
Question - House Robber II

Link - https://leetcode.com/problems/house-robber-ii/
*/

#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int> nums,int index,vector<int> &dp)
{
    if(index < 0) return 0;

    if(dp[index] != -1) return dp[index];

    return dp[index] = max(nums[index] + dfs(nums,index-2,dp),dfs(nums,index-1,dp));
    
}

int rob(vector<int>& nums) 
{
    int n = nums.size();

    if(n == 1) return nums[0];
    vector<int> dp1(n,-1);
    vector<int> dp2(n,-1);
    vector<int> temp1;
    vector<int> temp2; 



    for(int i = 0; i < n; i++)
    {
        if(i != 0) temp1.push_back(nums[i]);
        if(i != n-1) temp2.push_back(nums[i]);
    }

    return max(dfs(temp1,n-2,dp1),dfs(temp2,n-2,dp2));        
}

int main()
{
    return 0;
}