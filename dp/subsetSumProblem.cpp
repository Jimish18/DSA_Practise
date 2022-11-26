/*
Question - Subset Sum Problem

Link - https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?utm_source=gfg&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
*/

#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int>arr, int sum)
{
    vector<bool> temp(sum+1);
    int n = arr.size();
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

    return dp[n][sum];
}

int main()
{
    vector<int> v = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    cout<<isSubsetSum(v,sum)<<endl;
    return 0;
}