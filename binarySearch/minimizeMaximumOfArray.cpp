/*
Question - Minimize Maximum of Array

Link - https://leetcode.com/problems/minimize-maximum-of-array/
*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(long long val,vector<int> &nums)
{
    vector<long long> arr(nums.begin(),nums.end());
    int n = nums.size();

    for(int i = 0; i < n-1 ; i++)
    {
        if(arr[i] > val) return false;
        arr[i+1] -= (val-arr[i]);
    }

    return (arr[n-1] <= val);
}

int minimizeArrayValue(vector<int>& nums) 
{ 
    int start = 0;
    int end = 1e9;

    while(start < end)
    {
        int mid = (start+end) >> 1;
        if(isPossible(m,nums)) end = mid;
        else start = mid+1;
    }

    return start;
}


int main()
{
    return 0;
}