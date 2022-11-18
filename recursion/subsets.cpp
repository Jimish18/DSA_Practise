/*
Question - Subsets

Link - https://leetcode.com/problems/subsets/
*/

#include <bits/stdc++.h>
using namespace std;

void addSubsets(vector<vector<int>> &result,vector<int> &nums,vector<int> &ds,int index)
{
    if(index == nums.size())
    {
        result.push_back(ds);
        return;
    }

    ds.push_back(nums[index]);
    addSubsets(result,nums,ds,index+1);
    ds.pop_back();

    addSubsets(result,nums,ds,index+1);
}

vector<vector<int>> subsets(vector<int>& nums) 
{
    vector<vector<int>> result;
    vector<int> ds;

    addSubsets(result,nums,ds,0);

    return result;
}

int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = subsets(nums);

    for(int i = 0 ; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    
    return 0;
}