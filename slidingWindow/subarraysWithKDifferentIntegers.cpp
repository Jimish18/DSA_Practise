/*
Question - Subarrays With K Different Integers

Link - https://leetcode.com/problems/subarrays-with-k-different-integers/
*/

#include <bits/stdc++.h>
using namespace std;

int subarraysHavingAtmostKDistinctInteger(vector<int> &nums,int k)
{
    int n = nums.size();
    int i = 0;
    int count = 0;
    unordered_map<int,int> umap;

    for(int j = 0; j < n ; j++)
    {
        umap[nums[j]]++;
                
        if(umap.size() > k)
        {
            while(umap.size() > k)
            {
                umap[nums[i]]--;

                if(umap[nums[i]] == 0) umap.erase(nums[i]);
                i++;
            }            
        }

        count += j-i+1;
        
    }

    return count;
}

int subarraysWithKDistinct(vector<int>& nums, int k) 
{
    return (subarraysHavingAtmostKDistinctInteger(nums,k) - subarraysHavingAtmostKDistinctInteger(nums,k-1));
            
}

int main()
{
    return 0;
}