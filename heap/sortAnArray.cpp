/*
Question - Sort An Array

Link - https://leetcode.com/problems/sort-an-array/
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force (Using Heap)
vector<int> sortArray(vector<int>& nums) 
{
    priority_queue<int,vector<int>,greater<int>> minH;
    int n = nums.size();
    
    for(int i = 0; i < n; i++)
    {
        minH.push(nums[i]);    
    }
    
    nums.clear();
    
    while(!minH.empty())
    {
        nums.push_back(minH.top());
        minH.pop();
    }
    
    return nums;
}

int main()
{
    return 0;
}