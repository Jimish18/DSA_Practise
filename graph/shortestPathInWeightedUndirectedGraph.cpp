/*
Question - Shortest Path in Weighted undirected graph


Link - https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) 
{
    vector<vector<pair<int,int>>> adj(n+1);
    for(auto x : edges)
    {
        adj[x[0]].push_back({x[1],x[2]});
        adj[x[1]].push_back({x[0],x[2]});
    }

    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> minH;
    vector<int> dist(n+1,1e9) , parent(n+1);
    for(int i = 1 ; i <= n; i++) parent[i] = i;
    dist[1] = 0 ;
    minH.push({0,1});

    while(!minH.empty())
    {
        int node = minH.top().second;
        int wt = minH.top().first;
        minH.pop();

        for(auto x : adj[node])
        {
            int edgeWt = x.second;
            int adjNode = x.first;

            if(wt + edgeWt < dist[adjNode])
            {
                dist[adjNode] = wt + edgeWt;
                minH.push({wt+edgeWt , adjNode});
                parent[adjNode] = node;
            }
        }

    } 

    if(dist[n] == 1e9) return {-1};

    vector<int> path;
    int node = n;

    while(parent[node] != node)
    {
        path.push_back(node);
        node = parent[node];
    }
    
    path.push_back(1);
    reverse(path.begin(),path.end());

    return path;
}

int main()
{
    return 0;
}