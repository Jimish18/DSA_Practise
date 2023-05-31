/*
Question - Number Of Provinces

Link - https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &ad,int node,vector<bool> &visited)
{
    visited[node] = true;

    for(auto x : ad[node])
    {
        if(!visited[x]) dfs(ad,x,visited);
    }
}

int numProvinces(vector<vector<int>> adj, int V) 
{
    vector<vector<int>> ad(V+1);

    for(int i = 0 ; i < adj.size(); i++)
    {
        for(int j = 0 ; j < adj[i].size(); j++)
        {
            if(i != j && adj[i][j]) ad[i+1].push_back(j+1);
        }
    }

    vector<bool> visited(V+1,false);
    int count = 0;

    for(int i = 1 ; i < V+1; i++)
    {
        if(!visited[i])
        {
            count++;
            dfs(ad,i,visited);
        }
    }

    return count;
}

int main()
{
    return 0;
}