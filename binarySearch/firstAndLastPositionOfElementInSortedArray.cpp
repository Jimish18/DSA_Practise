/*
Question - Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position 
of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non-decreasing array.
-10^9 <= target <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> nums,int target)
{
    int start = 0;
    int end = nums.size()-1;
    int mid = start + (end-start)/2;
    int ans = -1;

    while(start <= end)
    {
        if(nums[mid] == target)
        {
            ans = mid;
            end = mid-1;
        }
        else if(target < nums[mid])
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }

        mid = start + (end - start)/2;
    }

    return ans;
}

int lastOccurence(vector<int> nums,int target)
{
    int start = 0;
    int end = nums.size()-1;
    int mid = start + (end-start)/2;
    int ans = -1;

    while(start <= end)
    {
        if(nums[mid] == target)
        {
            ans = mid;
            start = mid+1;
        }
        else if(target < nums[mid])
        {
            end = mid-1;
        }
        else
        {
            start = (mid+1);
        }

        mid = start + (end - start)/2;
    }

    return ans;
}

vector<int> searchRange(vector<int>& nums, int target) 
{
   int first = firstOccurence(nums,target);
   int last = lastOccurence(nums,target);

   return {first,last}; 
}

int main()
{
    vector<int> v = {};
    
    for(int i = 0 ; i < searchRange(v,0).size(); i++)
    {
        cout<<searchRange(v,0)[i]<<" ";
    }

    return 0;
}