/*
Question - Minimum Subset Sum Difference (Minimum Sum Partition)

link - https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1?utm_source=gfg&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
*/

#include <bits/stdc++.h>
using namespace std;

int minDifference(int arr[], int n)  
{ 
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }    

    vector<bool> temp(sum+1);
    vector<vector<bool>> dp(n+1,temp);

    for(int i = 0; i < sum+1; i++)
    {
        dp[0][i] = false;
    }

    for(int i = 0; i < n+1; i++)
    {
        dp[i][0] = true;
    }

    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < sum+1; j++)
        {
            if(arr[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else if(arr[i-1] > j)
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int diff = INT_MAX;

    for(int i = 0 ; i <= sum/2;i++)
    {
        if(dp[n][i])
        {
            diff = min(diff,abs((sum-i) - i));
        }
    }

    return diff;
}

int main()
{
    int arr[] = {1, 6, 11, 5};
    // 1, 6, 11, 5 - 4
    int n = 4;
    cout<<minDifference(arr,n)<<endl;
    return 0;
}