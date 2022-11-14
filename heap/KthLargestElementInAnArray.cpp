/*
Question - Kth Largest Element in an Array

link - https://leetcode.com/problems/kth-largest-element-in-an-array/
*/

#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) 
{
    priority_queue<int,vector<int>,greater<int>> minH;
    
    int n = nums.size();
    
    for(int i = 0; i < n; i++)
    {
        minH.push(nums[i]);
        
        if(minH.size() > k)
        {
            minH.pop();
        }
    }
    
    return minH.top();
}

int main()
{
    return 0;
}