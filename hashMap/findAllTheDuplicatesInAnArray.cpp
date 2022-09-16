/*
Question - Find All The Duplicates In An Array

Link - https://leetcode.com/problems/find-all-duplicates-in-an-array/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) 
{
    if(nums.empty())
    {
        return {};
    }

    vector<int> duplicates;
    for(int i = 0 ; i < nums.size(); i++)
    {
        if(nums[abs(nums[i])-1] < 0)
        {
            duplicates.push_back(abs(nums[i]));
        }
        nums[abs(nums[i])-1] = -1*nums[abs(nums[i])-1];
    } 

    return duplicates;       
}

int main()
{
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> duplicates = findDuplicates(nums);

    for(int i = 0 ; i < duplicates.size(); i++)
    {
        cout<<duplicates[i]<<" ";
    }
    cout<<endl;
    return 0;
}