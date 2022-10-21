/*
Question - contains Duplicate II

Link - https://leetcode.com/problems/contains-duplicate-ii/
*/

#include <bits/stdc++.h>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) 
{
    unordered_map<int,int> umap;
    int n = nums.size();
    
    for(int i = 0 ; i < n; i++)
    {
        if(umap.find(nums[i]) != umap.end())
        {
            if(abs(umap[nums[i]]-i) <= k)
            {
                return true;
            }
        }
        umap[nums[i]] = i;
    }
    
    return false;
}


int main()
{
    return 0;
}