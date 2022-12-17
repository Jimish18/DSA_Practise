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



long long mod = 1e9+7;
	
long long helper(vector<long long> &arr,int index,int sum,vector<vector<long long>> &dp)
{
    if(sum == 0) return 1;
    if(sum < 0 || index < 0) return 0;

    if(dp[index][sum] != -1) return dp[index][sum];

    if(arr[index] <= sum)
    {
         dp[index][sum] = helper(arr,index-1,sum-arr[index],dp) + helper(arr,index-1,sum,dp);
         return dp[index][sum]%mod;
    }  
    else if(arr[index] > sum)
    {
        dp[index][sum] = helper(arr,index-1,sum,dp);
        return dp[index][sum]%mod;
        
    }
    
    return -1;

}


int perfectSum(int arr[], int n, int sum)
{
    
    vector<long long> temp(sum+1,-1);
    vector<vector<long long>> dp(n+1,temp);
    vector<long long> tempArr ;

    for(int i = 0 ; i < n; i++)
    {
        if(arr[i]) tempArr.push_back(arr[i]);
    }

    long long setWithZeros = pow(2,(n-tempArr.size()));
    setWithZeros = setWithZeros%mod;

    helper(tempArr,tempArr.size()-1,sum,dp);

    long long count = dp[(tempArr.size())-1][sum]*setWithZeros;

    return (count)%mod;
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