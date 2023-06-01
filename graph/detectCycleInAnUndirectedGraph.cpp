/*
Question - Detect Cycle In An Undirected Graph

Link - https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graphv
*/

#include <bits/stdc++.h>
using namespace std;

bool detect(int node , vector<int> adj[], vector<bool> visited)
{
    queue<pair<int,int>> q;
    q.push({node,-1});
    visited[node] = true;

    while(!q.empty())
    {
        int tempNode = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto x : adj[tempNode])
        {
            if(!visited[x])
            {
                q.push({x,tempNode});
                visited[x] = true;
            }
            else
            {
                if(parent != x) return true;
            }
        }
        
    }

    return false;
}

bool isCycle(int V, vector<int> adj[]) 
{
    vector<bool> visited(V,false);

    for(int i = 0 ; i < V; i++)
    {
        if(!visited[0]) 
        {
            if(detect(i,adj,visited)) return true;
        }
    }

    return false;
}

int main()
{
    return 0;
}