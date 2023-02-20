/*
Question - Search Insert Position

Link - https://leetcode.com/problems/search-insert-position/
*/

#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) 
{
    return (lower_bound(nums.begin(),nums.end(),target) - nums.begin());      
}

int main()
{
    return 0;
}