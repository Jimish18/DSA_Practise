/*
Question - minimize Deviation In Array

Link - https://leetcode.com/problems/minimize-deviation-in-array/
*/

#include <bits/stdc++.h>
using namespace std;

int minimumDeviation(vector<int>& nums) 
{
    int n = nums.size();
    priority_queue<int> maxH;
    int minValue = INT_MAX;

    for(int i = 0 ; i < n ; i++)
    {
        if(nums[i] % 2 == 1) nums[i] *= 2;
        maxH.push(nums[i]);
        minValue = min(minValue,nums[i]);
    }

    int minDeviation = INT_MAX;

    while(true)
    {
        int maxValue = maxH.top();
        maxH.pop();

        minDeviation = min(minDeviation,(maxValue-minValue));

        if(maxValue %2 == 1)
        {
            break;
        }

        maxValue /= 2;
        minValue = min(minValue,maxValue);
        maxH.push(maxValue);
    }

    return minDeviation;

}

int main()
{
    return 0;
}