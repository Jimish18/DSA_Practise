/*
Question - Number Of Provinces

Link - https://leetcode.com/problems/number-of-provinces/
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<bool> &visited , vector<vector<int>> &adj, int node)
{
    visited[node] = true;

    for(auto x : adj[node])
    {
        if(!visited[x]) dfs(visited,adj,x);
    }
}

int findCircleNum(vector<vector<int>>& isConnected) 
{
    int n = isConnected.size();
    vector<bool> visited(n+1,false);
    vector<vector<int>> adj(n+1);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < n; j++)
        {
            if(i != j && isConnected[i][j])
            {
                adj[i+1].push_back(j+1);
            }
        }
    }      

    int count = 0;
    for(int i = 1 ; i < n+1; i++)
    {
        if(!visited[i])
        {
            count++;
            dfs(visited,adj,i);
        }
    }

    return count;
      
}

int main()
{
    return 0;
}