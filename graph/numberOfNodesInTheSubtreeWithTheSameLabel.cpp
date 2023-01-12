/*
Question - Number of Nodes in the Sub-Tree With the Same Label

Link - https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
*/

#include <bits/stdc++.h>
using namespace std;

unordered_map<char,int> dfs(int prev,int node ,string &labels,vector<vector<int>> &adj,vector<int> &result)
{
    unordered_map<char,int> umap;

    for(auto &x : adj[node])
    {
        if(x != prev)
        {
            unordered_map<char,int> temp = dfs(node,x,labels,adj,result);
            for(auto y : temp)
            {
                umap[y.first] += y.second;
            }
            temp.clear();
        }
    }

    umap[labels[node]]++;
    result[node] = umap[labels[node]];

    return umap;
}

vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) 
{
    vector<vector<int>> adj(n);

    for(auto &x : edges)
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }   

    vector<int> result(n);

    dfs(-1,0,labels,adj,result);

    return result;     
}

int main()
{
    return 0;
}