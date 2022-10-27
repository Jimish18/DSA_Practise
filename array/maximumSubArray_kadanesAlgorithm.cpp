/*
Question - Maximum Subarray (Kadane's Algorithm)

Link - https://leetcode.com/problems/maximum-subarray/
*/

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) 
{
    int currentMax = 0;
    int maxSum = INT_MIN;
    int pos = 0 ;

    for(int i = 0; i < nums.size(); i++)
    {
        currentMax += nums[i];

        maxSum = max(maxSum,currentMax);

        if(currentMax < 0)
        {
            currentMax = 0;
            pos = i+1;
        }
    }     

    return maxSum;
}

int main()
{
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};

    cout<<maxSubArray(v)<<endl;

    return 0;
}