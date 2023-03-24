/*
Question - Reorder Routes to Make All Paths Lead to the City Zero

Link - https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
*/

#include <bits/stdc++.h>
using namespace std;

int minReorder(int n, vector<vector<int>>& connections) 
{
    vector<vector<pair<int,int>>> adj(n);   

    for(auto x : connections)
    {
        adj[x[0]].push_back({x[1],1});
        adj[x[1]].push_back({x[0],0});
    }

    queue<pair<int,int>> q;
    q.push({0,0});

    vector<bool> visited(n,false);
    int result = 0;


    while(!q.empty())
    {
        pair<int,int> temp = q.front();
        q.pop();

        visited[temp.first] = true;
        result += temp.second;

        for(auto &x : adj[temp.first])
        {
            if(visited[x.first]) continue;

            q.push(x);
        }
    }

    return result;
}

int main()
{
    return 0;
}