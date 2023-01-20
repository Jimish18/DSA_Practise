/*
Question - Non-Decreasing Subsequence

Link - https://leetcode.com/problems/non-decreasing-subsequences/
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>& nums,set<vector<int>> &temp,vector<int> &ds,int prev,int curr,int n)
{
    if(curr == n)
    {
        if(ds.size() >= 2)
        {
            temp.insert(ds);
        }
        return;
    }    

    if(prev == -1 || nums[prev] <= nums[curr])
    {
        ds.push_back(nums[curr]);
        dfs(nums,temp,ds,curr,curr+1,n);
        ds.pop_back();        
    }  

    dfs(nums,temp,ds,prev,curr+1,n); 
    
}

vector<vector<int>> findSubsequences(vector<int>& nums) 
{
    set<vector<int>> temp;
    vector<vector<int>> result;
    vector<int> ds;
    int n = nums.size();

    dfs(nums,temp,ds,-1,0,n); 

    for(auto x : temp)
    {
        result.push_back(x);
    } 

    return result;   
}

int main()
{
    return 0;
}