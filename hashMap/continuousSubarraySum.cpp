/*
Question - Continuous Subarray Sum

Link - https://leetcode.com/problems/continuous-subarray-sum/
*/

#include <bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k)
{
    unordered_map<int,int> umap;

    if(nums.size() < 2)
    {
        return false;
    }       

    umap[0] = -1;

    int preFixSum = 0;

    for(int i = 0 ; i < nums.size(); i++)
    {
        preFixSum += nums[i];

        preFixSum %= k;

        if(umap.find(preFixSum) != umap.end())
        {
            if(i - umap[preFixSum] > 1)
            {
                return true;
            }
        }
        else
        {
            umap[preFixSum] = i;
        }
    }

    return false;
}

int main()
{
    return 0;
}