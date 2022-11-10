/*
Question - Majority Element (element greater than N/2)

Link - https://leetcode.com/problems/majority-element/
*/

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) 
{
    int candidate = 0;
    int count = 0;
    int n = nums.size();
    
    for(int i = 0; i < n; i++)
    {
        if(count == 0)
        {
            candidate = nums[i];
        }

        if(nums[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }  

    return candidate;      
}

int main()
{

    return 0;
}