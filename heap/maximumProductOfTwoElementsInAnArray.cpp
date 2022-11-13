/*
Question - Maximum Product of Two Elements in an Array

Link - https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
*/

#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) 
{
    priority_queue<int> maxh;
    int n = nums.size();

    for(int i = 0 ; i < n; i++)
    {
        maxh.push(nums[i]);
    }        

    int a = maxh.top();
    maxh.pop();
    int b = maxh.top();

    return (a-1)*(b-1);
}

int main()
{
    return 0;
}