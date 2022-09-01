/*
Question - Search In Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) 
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, 
or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1

Constraints:
1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-10^4 <= target <= 10^4

*/

#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) 
{
    int s = 0 ; 
    int e = nums.size()-1;
    int n = nums.size();
    int m = s + (e-s)/2;

    while(s <= e)
    {
        if(target == nums[m])
        {
            return m;
        }

        if(nums[s] <= nums[m] )
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

    return -1;
}

int main()
{
    vector<int> v ={4,5,6,7,0,1,2};
    
    cout<<search(v,4)<<endl;

    return 0;
}