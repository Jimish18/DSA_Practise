/*
Question - Partition Equal Subset Sum

Link - https://leetcode.com/problems/partition-equal-subset-sum/
*/

#include <bits/stdc++.h>
using namespace std;

// DP Tabulation
// bool canPartition(vector<int>& nums) 
// {
//     int sum = 0; 
//     int n = nums.size();

//     for(int i = 0 ; i < n ; i++)
//     {
//         sum += nums[i];
//     }        

//     if(sum%2 != 0) return false;
//     else
//     {   
//         sum /= 2;
//         vector<bool> temp(sum+1);
//         vector<vector<bool>> dp(n+1,temp);

//         for(int i = 0; i < n+1; i++)
//         {
//             dp[i][0] = true;
//         }

//         for(int i = 0; i < sum+1; i++)
//         {
//             dp[0][i] = false;
//         }

//         for(int i = 1; i < n+1; i++)
//         {
//             for(int j = 1; j < sum+1; j++)
//             {
//                 if(nums[i-1] <= j)
//                 {
//                     dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
//                 }
//                 else if(nums[i-1] > j)
//                 {
//                     dp[i][j] = dp[i-1][j];
//                 }
//             }
//         }
            
//         return dp[n][sum];  
//     }

//     return false;

// }

// Memoization Method
int helper(vector<int>& nums,int n,int sum,vector<vector<int>> &dp)
{
    if(sum == 0) return true;
    if(n == 0) return false;

    if(dp[n][sum] != -1) return dp[n][sum];

    if(nums[n] <= sum)
    {
        return dp[n][sum] = helper(nums,n-1,sum - nums[n],dp) || helper(nums,n-1,sum,dp);
    }
    else if(nums[n] > sum)
    {
        return dp[n][sum] = helper(nums,n-1,sum,dp);
    }

    return -1;
}

bool canPartition(vector<int>& nums) 
{
    int sum = 0; 
    int n = nums.size();

    for(int i = 0 ; i < n ; i++)
    {
        sum += nums[i];
    }        

    if(sum%2 != 0) return false;
    else
    {
        sum /= 2;
        vector<int> temp(sum+1,-1);
        vector<vector<int>> dp(n+1,temp);
        return helper(nums,n-1,sum,dp);   
    }
    return true;
}

int main()
{
    return 0;
}