/*
Question - Longest Increasing Subsequence

Link - https://leetcode.com/problems/longest-increasing-subsequence/
*/

#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) 
{
    vector<int> temp;
    temp.push_back(nums[0]);
    int n = nums.size();
    int length = 1;

    for(int i = 1 ; i < n-1; i++)
    {
        if(nums[i] > temp.back())
        {
            temp.push_back(nums[i]);
            length++;
        }
        else
        {
            int idx = lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
            temp[idx] = nums[i];
        }
    }

    return length;
}

int main()
{
    return 0;
}