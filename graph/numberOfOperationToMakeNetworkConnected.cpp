/*
Question - Number of Operations to Make Network Connected

Link - https://leetcode.com/problems/number-of-operations-to-make-network-connected/
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[] , vector<bool> &visited , int node)
{
    visited[node] = true;

    for(auto x : adj[node])
    {
        if(!visited[x]) dfs(adj,visited,x);
    }
}

int makeConnected(int n, vector<vector<int>>& connections) 
{
    int N = connections.size();

    if(N < n-1) return -1;

    vector<int> adj[n];

    for(auto x : connections)
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }        

    vector<bool> visited(n,false);
    int result = 0;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(adj,visited,i);
            result++;
        }
    }

    return result-1;
}

int main()
{
    return 0;
}