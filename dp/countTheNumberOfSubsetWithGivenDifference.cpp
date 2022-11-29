/*
Question - Count The Number Of Subsets With a Given Difference

*/

#include <bits/stdc++.h>
using namespace std;

int countSubsetsWithGivenDiff(vector<int> nums,int diff)
{
    int sum = 0;
    int n = nums.size();

    for(int i = 0 ; i < n ; i++)
    {
        sum+= nums[i];
    }

    int requiredSum = (diff+sum)/2;

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
        for(int j = 1 ; j < requiredSum+1; j++)
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
    vector<int> nums = {1,1,2,3};
    int diff = 1;
    cout<<countSubsetsWithGivenDiff(nums,diff)<<endl;
    return 0;
}