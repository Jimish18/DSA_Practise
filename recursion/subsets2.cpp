/*
Question - Subsets II

Link - https://leetcode.com/problems/subsets-ii/
*/

#include <bits/stdc++.h>
using namespace std;

void addSubsetsWithDup(vector<vector<int>> &result,vector<int> &nums,vector<int> &ds,int index)
{
    result.push_back(ds);

    for(int i = index ; i < nums.size(); i++)
    {
        if(i != index && nums[i] == nums[i-1]) continue;

        ds.push_back(nums[i]);
        addSubsetsWithDup(result,nums,ds,i+1);
        ds.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) 
{
    vector<vector<int>> result;
    vector<int> ds;
    sort(nums.begin(),nums.end());

    addSubsetsWithDup(result,nums,ds,0);

    return result;        
}

int main()
{
    return 0;
}