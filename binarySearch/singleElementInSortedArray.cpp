/*
Question - Single Element In Sorted Array

You are given a sorted array consisting of only integers where every element appears exactly twice, 
except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105
*/

#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) 
{
    if(nums.size() == 1)
    {
        return nums[0];
    }
    int result;
    int s = 0;
    int e = nums.size()-1;
    int mid = s + (e-s)/2;
    int n = nums.size();

    while(s <= e)
    {
        if(nums[(mid+n-1)%n] != nums[mid] && nums[(mid+1)%n] != nums[mid])
        {
            return nums[mid];
        }
        if((e-mid)%2 == 0)
        {
            if(nums[(mid+n-1)%n] == nums[mid])
            {
                e = mid%n;
            }
            else
            {
                s = mid%n;
            }
        }
        else
        {
            if(nums[(mid+n-1)%n] == nums[mid])
            {
                s = (mid+1)%n;
            }
            else
            {
                e = (mid+n-1)%n;
            }
        }

        mid = s + (e-s)/2;
    }

    return -1;
}

int main()
{
    vector<int> v = {1,2,2,4,4,6,6};
    cout<<singleNonDuplicate(v)<<endl;

    return 0;
}