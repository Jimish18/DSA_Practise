/*
Question - Subarray Sum Divisible By K

Link - https://leetcode.com/problems/subarray-sums-divisible-by-k/
*/

#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) 
{
    unordered_map<int,int> umap;
    int preFix = 0;
    int count = 0;
    int n = nums.size();
    umap[0]++;
    
    for(int i = 0; i < n; i++)
    {
        preFix += nums[i];

        int rem = preFix%k;
        if(rem < 0) rem += k;

        if(umap.find(rem) != umap.end())
        {
            count += umap[rem];            
        }

        umap[rem]++;
    }        

    return count;
}

int main()
{
    return 0;
}