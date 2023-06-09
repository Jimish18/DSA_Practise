/*
Question - Find Evantual Safe State

Link - https://leetcode.com/problems/find-eventual-safe-states/
*/

#include <bits/stdc++.h>
using namespace std;

// bool isCycle(vector<vector<int>> &adj , vector<bool> &visited , int node , int prev,vector<bool> &pathVisited)
// {
//     visited[node] = true;
//     pathVisited[node] = true;

//     for(auto x : adj[node])
//     {
//         if(!visited[x]) 
//         {
//             if(isCycle(adj,visited,x,node,pathVisited)) return true;
//         }
//         else if(pathVisited[x]) return true;
//     }

//     pathVisited[node] = false;
//     return false;
// }

// vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
// {
//     vector<int> ans;
//     int n = graph.size();

//     for(int i = 0 ; i < n; i++)
//     {
//         vector<bool> visited(n,false);
//         vector<bool> pathVisited(n,false);
//         if(!isCycle(graph,visited,i,-1,pathVisited)) ans.push_back(i);
//     }
    
//     return ans;
// }

vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
{
    int n = graph.size();
    vector<vector<int>> adj(n);

    for(int i = 0 ; i < n ; i++)
    {
        int m = graph[i].size();

        for(int j = 0 ; j < m ; j++)
        {
            adj[graph[i][j]].push_back(i);
        }
    }

    vector<int> indegree(n,0);
    for(int i = 0 ; i < n ; i++)
    {
        for(auto x : adj[i])
        {
            indegree[x]++;
        }
    }

    queue<int> q;
    for(int i = 0 ; i < n; i++)
    {
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> ans;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto x : adj[node])
        {
            indegree[x]--;

            if(indegree[x] == 0) q.push(x);
        }
    }

    return ans;
}

int main()
{
    return 0;
}