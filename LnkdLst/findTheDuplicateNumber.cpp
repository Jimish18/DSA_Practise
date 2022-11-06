/*
Question - Find the Duplicate Number

Link - https://leetcode.com/problems/find-the-duplicate-number/
*/

#include <bits/stdc++.h>
using namespace std;

// brute Force Approach
// int findDuplicate(vector<int>& nums) 
// {
//    sort(nums.begin(),nums.end());
//    for(int i = 1 ; i < n; i++)
//    {
//         if(nums[i] == nums[i-1])
//         {
//             return nums[i];
//         }
//    }     

//    return -1;
// }

// Linked List Cycle Method
int findDuplicate(vector<int>& nums) 
{
    int fast = nums[0];
    int slow = nums[0];
   
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow != fast);

    fast = nums[0];

    while(fast != slow)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main()
{
    return 0;
}