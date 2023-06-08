/*
Question - Find Evantual Safe State

Link - https://leetcode.com/problems/find-eventual-safe-states/
*/

#include <bits/stdc++.h>
using namespace std;

bool isCycle(vector<vector<int>> &adj , vector<bool> &visited , int node , int prev,vector<bool> &pathVisited)
{
    visited[node] = true;
    pathVisited[node] = true;

    for(auto x : adj[node])
    {
        if(!visited[x]) 
        {
            if(isCycle(adj,visited,x,node,pathVisited)) return true;
        }
        else if(pathVisited[x]) return true;
    }

    pathVisited[node] = false;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
{
    vector<int> ans;
    int n = graph.size();

    for(int i = 0 ; i < n; i++)
    {
        vector<bool> visited(n,false);
        vector<bool> pathVisited(n,false);
        if(!isCycle(graph,visited,i,-1,pathVisited)) ans.push_back(i);
    }
    
    return ans;
}

int main()
{
    return 0;
}