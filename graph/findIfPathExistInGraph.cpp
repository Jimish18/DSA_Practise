/*
Question - Find If Path Exist In Graph

Link - https://leetcode.com/problems/find-if-path-exists-in-graph/
*/

#include <bits/stdc++.h>
using namespace std;

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
{
    unordered_map<int,vector<int>> umap;

    for(auto x : edges)
    {
        umap[x[0]].push_back(x[1]);
        umap[x[1]].push_back(x[0]);
    }   

    vector<bool> visited(umap.size()+1,false);
    queue<int> q;
    q.push(source);

    visited[source] = true;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        vector<int> v = umap[x];
        for(auto x : v)
        {
            if(!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
        }

        if(visited[destination]) return true;
    }

    return false;
}

int main()
{
    return 0;
}