/*
Question - Perfect Sum Problem

Link - https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1
*/

#include <bits/stdc++.h>
using namespace std;

// long long cnt = 0;

// void dfs(int arr[],int index,int sum)
// {
//     if(sum == 0)
//     {
//         cnt++;
//         return ;
//     }

//     if(index < 0) return;

//     dfs(arr,index-1,sum-arr[index]);
//     dfs(arr,index-1,sum);   

// }

// int perfectSum(int arr[], int n, int sum)
// {
//     long long mod = 1e9+7;

//     dfs(arr,n-1,sum);

//     return cnt%mod;
// }



// int helper(int arr[],int index,int sum,vector<vector<int>> &dp)
// {
//     if(sum == 0) return 1;
//     if(sum < 0 || index < 0) return 0;

//     if(dp[index][sum] != -1) return dp[index][sum];

//     if(arr[index] <= sum)
//     {
//         return dp[index][sum] = helper(arr,index-1,sum-arr[index],dp) + helper(arr,index-1,sum,dp);
//     }  
//     else if(arr[index] > sum)
//     {
//         return dp[index][sum] = helper(arr,index-1,sum,dp);
//     }

//     return -1;

// }


// int perfectSum(int arr[], int n, int sum)
// {
//     long long mod = 1e9+7;
//     vector<int> temp(sum+1,-1);
//     vector<vector<int>> dp(n+1,temp);

//     helper(arr,n-1,sum,dp);

//     return (dp[n-1][sum])%mod;
// }

int topDown(int arr[],int sum,vector<vector<int>> &dp,int n)
{

    for(int i = 0 ; i < sum+1; i++)
    {
        dp[0][i] = 0;
    }
    for(int i = 0 ; i < n+1; i++)
    {
        dp[i][0] = 1;
    }


    for(int i = 1 ; i < n+1; i++)
    {
        for(int j = 1; j < sum+1; j++)
        {
            if(arr[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else 
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
;
}


int perfectSum(int arr[], int n, int sum)
{
    long long mod = 1e9+7;
    vector<int> temp(sum+1);
    vector<vector<int>> dp(n+1,temp);
    

    return (topDown(arr,sum,dp,n))%mod;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    // {2, 3, 5, 6, 8, 10}
    int sum = 10;
    int n = 5;
    cout<<perfectSum(arr,n,sum)<<endl;
    return 0;
}