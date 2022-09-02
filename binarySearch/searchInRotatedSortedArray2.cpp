/*
Question - Search in Rotated Sorted Array 2

There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) 
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] 
(0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, 
or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
 

Constraints:

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
nums is guaranteed to be rotated at some pivot.
-10^4 <= target <= 10^4
 

Follow up: This problem is similar to Search in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?
*/

#include <bits/stdc++.h>
using namespace std;

bool search(vector<int>& nums, int target) 
{
    int s = 0 ; 
    int e = nums.size()-1;
    int n = nums.size();
    int m = s + (e-s)/2;

    while(s <= e)
    {
        if(target == nums[m])
        {
            return true;
        }

        if(nums[s] == nums[m] && nums[e] == nums[m])
        {
            s++;
            e--;
        }
        else if(nums[s] <= nums[m] )
        {
            if(nums[s] <= target && target <= nums[m] )
            {
                e = m-1;
            }
            else
            {
                s = m+1;
            }
        }
        else
        {
            if(target >= nums[m] && target <= nums[e])
            {
                s = m+1;
            }
            else
            {
                e = m-1;
            }
        }

        m = s + (e-s)/2;
    }

    return false;
}

int main()
{
    vector<int> v ={1,0,1,1,1};
    
    cout<<search(v,0)<<endl;

    return 0;
}