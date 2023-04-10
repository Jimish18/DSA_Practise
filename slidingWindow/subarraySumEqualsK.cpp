/*
Question - Subarray Sum Equals K

Link - https://leetcode.com/problems/subarray-sum-equals-k/
*/

#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) 
{
    int n = nums.size();
    int count = 0;
    int sum = 0;
    unordered_map<int,int> umap;

    umap[0] = 1;

    for(int i = 0; i < n ; i++)
    {
        sum += nums[i];

        if(umap.find(sum-k) != umap.end())
        {
            count += umap[sum-k];
        } 

        umap[sum]++;

    }

    return count;
}

int main()
{
    return 0;
}