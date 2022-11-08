/*
Question - Find Minimum in Rotated Sorted Array

Link - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
*/

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) 
{
    int n = nums.size();
    int start = 0;
    int end = n-1;
    int mid = start + (end - start)/2;

    while(start <= end)
    {
        if(nums[mid] <= nums[(mid+n-1)%n] && nums[mid] <= nums[(mid+1)%n])
        {
            return nums[mid];
        }
        else if(nums[mid] <= nums[end])
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }

        mid = start + (end - start)/2;
    }

    return -1;
}

int main()
{
    return 0;
}