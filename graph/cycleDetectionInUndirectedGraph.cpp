/*
Question - Cycle Detection In Undirected Graph

Link - https://www.codingninjas.com/codestudio/problems/1062670?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
*/

#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &adj , vector<bool> &visited,int node , int prev)
{
    visited[node] = true;
    for(auto x : adj[node])
    {
        if(!visited[x])
        {
            if(dfs(adj,visited,x,node)) return true;
        }
        else
        {
            if(prev != x) return true;
        }
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> adj(n+1);
    vector<bool> visited(n+1,false);

    for(auto x : edges)
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }

    for(int i = 1; i < n+1 ; i++)
    {
        if(!visited[i])
        {
            if(dfs(adj,visited,i,-1)) return "YES";
        }
    }

    return "NO";
}

int main()
{
    return 0;
}