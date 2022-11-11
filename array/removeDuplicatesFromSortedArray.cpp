/*
Question - Remove Duplicates From Sorted Array

Link - https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) 
{
    int n = nums.size();
    int count = 0;
    for(int i = 1; i < n; i++){
        if(nums[i] == nums[i-1]) count++;
        else nums[i-count] = nums[i];
    }
    return n-count;
}

int main()
{
    return 0;
}
