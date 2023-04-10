/*
Question - Count Number OF Nice Subarrays

Link - https://leetcode.com/problems/count-number-of-nice-subarrays/
*/

#include <bits/stdc++.h>
using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) 
{
    int n = nums.size();

    for(int i = 0; i < n ; i++)
    {
        if(nums[i]&1) nums[i] = 1;
        else nums[i] = 0;
    }
    unordered_map<int,int> umap;
    int sum = 0;
    int count = 0;

    for(int i = 0 ; i < n ; i++)
    {
        sum += nums[i];
        if(sum == k) count++;
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