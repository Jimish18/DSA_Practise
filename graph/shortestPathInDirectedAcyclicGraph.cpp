/*
Question - Shortest Path In Directed Acyclic Graph

Link - https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<pair<int,int>>> &adj , vector<bool> &visited,stack<int> &st, int node)
{
    visited[node] = true;

    for(auto x : adj[node])
    {
        if(!visited[x.first])
        {
            dfs(adj,visited,st,x.first);
        }
    }

    st.push(node);
}

vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
{
    vector<vector<pair<int,int>>> adj(N);

    for(auto x : edges)
    {
        adj[x[0]].push_back({x[1],x[2]});
    }

    vector<bool> visited(N,false);
    stack<int> st;

    for(int i = 0 ; i < N; i++)
    {
        if(!visited[i]) dfs(adj,visited,st,i);
    }

    vector<int> ans(N,1e9);
    ans[0] = 0;

    while(!st.empty())
    {
        int node = st.top();
        st.pop();

        for(auto x : adj[node])
        {
            int v = x.first;
            int wt = x.second;

            if(ans[v] + wt < ans[node]) ans[v] = wt+ans[node];
        }
    }

    for(auto x : ans)
    {
        if(x == 1e9) x = -1;
    }

    return ans;

}

int main()
{
    return 0;
}