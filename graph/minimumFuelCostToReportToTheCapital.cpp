/*
Question - Minimum Fuel Cost To Report To The Capital

Link - https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/
*/

#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &adj,int cur,int prev,int &seats,long long &ans)
{
    int people = 1;

    for(auto x : adj[cur])
    {
        if(x == prev) continue;

        people += dfs(adj,x,cur,seats,ans);
    }

    if(cur > 0) ans += (people + seats -1)/seats;

    return people;
}

long long minimumFuelCost(vector<vector<int>>& roads, int seats) 
{
    int n = roads.size();
    long long ans = 0;
    vector<vector<int>> adj(n+1);     

    for(vector<int>& road : roads)
    {
        int u = road[0];
        int v = road[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }   

    dfs(adj,0,-1,seats,ans);

    return ans;
}

int main()
{
    return 0;
}