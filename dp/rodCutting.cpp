/*
Question - Rod Cutting

Link - https://practice.geeksforgeeks.org/problems/rod-cutting0840/1
*/

#include <bits/stdc++.h>
using namespace std;

// int cutRod(int price[], int n) 
// {
//     vector<int> nums;
//     for(int i = 0 ; i < n; i++)
//     {
//         nums.push_back(i+1);
//     }

//     vector<int> temp(n+1);
//     vector<vector<int>> dp(n+1,temp);

//     for(int i = 0; i < n+1; i++)
//     {
//         dp[0][i] = 0;
//     }

//     for(int i = 0; i < n+1; i++)
//     {
//         dp[i][0] = 0;
//     }

//     for(int i = 1 ; i < n+1; i++)
//     {
//         for(int j = 1; j < n+1; j++)
//         {
//             if(nums[i-1] <= j)
//             {
//                 dp[i][j] = max(price[i-1] + dp[i][j-nums[i-1]],dp[i-1][j]);
//             }
//             else
//             {  
//                 dp[i][j] = dp[i-1][j];
//             }
//         }
//     }

//     return dp[n][n];
// }

int dfs(int prices[],vector<int> &length,int n,vector<int> &dp,int length)
{
    
}

int cutRod(int price[], int n) 
{
    vector<int> temp(n+1,-1);
    vector<vector<int>> dp(n+1,temp);
    vector<int> length;

    for(int i = 0; i < n; i++)
    {
        length.push_back(i+1);
    }

    dfs(price,n,dp,1);

    return dp[n];
}



int main()
{
    return 0;
}