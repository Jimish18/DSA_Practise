/*
Question - Two Sum

Link - https://leetcode.com/problems/two-sum/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) 
{
    int n = nums.size();
    vector<int> result;
    unordered_map<int,int> umap;

    for(int i = 0; i < n; i++)
    {
        if(umap.find(target - nums[i]) != umap.end())
        {
            result.push_back(i);
            result.push_back(umap[target- nums[i]]);
            return result;
        }

        umap[nums[i]] = i;
    }        

    return result;
}

int main()
{
    return 0;
}