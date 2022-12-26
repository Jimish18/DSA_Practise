/*
Question - Target Sum

Link - https://leetcode.com/problems/target-sum/
*/

#include <bits/stdc++.h>
using namespace std;




int findTargetSumWays(vector<int>& nums, int target) 
{
    int n = nums.size();
    int sum = 0;
    for(int i = 0 ; i < n; i++)
    {
        sum += nums[i];
    }

    if(sum < target || (sum+target)%2 != 0) return 0;

    int requiredSum = (target+sum)/2;

    vector<int> temp(requiredSum+1);
    vector<vector<int>> dp(n+1,temp);

    for(int i = 0; i < requiredSum+1; i++)
    {
        dp[0][i] = 0;
    }  

    for(int i = 0; i < n+1; i++)
    {
        dp[i][0] = 1;
    }        

    for(int i = 1 ; i < n+1; i++)
    {
        for(int j = 0 ; j < requiredSum+1; j++)
        {
            if(nums[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
            }
            else if(nums[i-1] > j)
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][requiredSum];
}

int main()
{
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    cout<<findTargetSumWays(nums,target)<<endl;
    return 0;
}