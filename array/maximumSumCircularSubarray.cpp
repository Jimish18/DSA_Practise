/*
Question - Maximum Sum Circular Subarray

Link - https://leetcode.com/problems/maximum-sum-circular-subarray/
*/

#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> v)
{
    int sum = 0;
    int maxSum = 0;

    for(int i = 0 ; i < v.size(); i++)
    {
        sum += v[i];
        maxSum = max(sum,maxSum);
        if(sum < 0)
        {
            sum = 0;
        }
    }

    return maxSum;
}

int maxSubarraySumCircular(vector<int>& nums) 
{
    int nonWrapSum = kadane(nums);
    int wrapSum;
    int totalSum = 0;
    
    for(int i = 0; i < nums.size(); i++)
    {
        totalSum += nums[i];
        nums[i] = -nums[i];
    }

    wrapSum = totalSum + kadane(nums);

    return max(nonWrapSum,wrapSum);
}

int main()
{
    vector<int> v = {-3,-2,-3};
    cout<<kadane(v)<<endl;
    return 0;
}