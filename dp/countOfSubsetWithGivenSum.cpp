/*
Question - Count of Subset With a given Sum
*/

#include <bits/stdc++.h>
using namespace std;

int countSubsetWithGivenSum(vector<int> nums,int sum)
{
    int n = nums.size();
    vector<int> temp(sum+1);
    vector<vector<int>> dp(n+1,temp);

    for(int i = 0; i < sum+1; i++)
    {
        dp[0][i] = 0;
    }

    for(int i = 0 ; i < n+1; i++)
    {
        dp[i][0] = 1;
    }

    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < sum+1; j++)
        {
            if(nums[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j - nums[i-1]] + dp[i-1][j];
            }
            else if(nums[i-1] > j)
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];

}

int main()
{
    vector<int> v = {2,5};
    // {2,3,5,6,8,10}   10
    int sum = 5;
    cout<<countSubsetWithGivenSum(v,sum)<<endl;
    return 0;
}