/*
Question - Top K Frequent Elements

Link - https://leetcode.com/problems/top-k-frequent-elements/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) 
{
    unordered_map<int,int> umap;
    priority_queue<pair<int,int>> maxH;
    int n = nums.size();
    vector<int> result;
    
    for(int i = 0; i < n; i++)
    {
        umap[nums[i]]++;
    }
    
    for(auto x : umap)
    {
        maxH.push({x.second,x.first});
    }
    
    while(k)
    {
        result.push_back(maxH.top().second);
        maxH.pop();
        k--;
    }
    
    return result;
}

int main()
{
    return 0;
}