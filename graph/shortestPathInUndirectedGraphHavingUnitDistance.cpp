/*
Question - Shortest path in Undirected Graph having unit distance

Link - https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src)
{
    vector<vector<int>> adj(N);

    for(auto x : edges)
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }

    vector<int> dist(N);

    for(int i = 0 ; i < N; i++) 
    {
        dist[i] = 1e9;
    }
    dist[src] = 0;
    queue<int> q;
    q.push(src);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto x : adj[node])
        {
            if(dist[node] + 1  < dist[x])
            {
                dist[x] = 1 + dist[node];
                q.push(x);
            }
        }
    }

    vector<int> ans(N,-1);

    for(int i = 0; i < N; i++)
    {
        if(dist[i] != 1e9) ans[i] = dist[i];
    }

    return ans;
}

int main()
{
    return 0;
}