/*
Question - Minimum Time to Collect All Apples in a Tree

Link - https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
*/

#include <bits/stdc++.h>
using namespace std;

int dfs(int prev,int curr,vector<vector<int>> &adj,vector<bool>& hasApple)
{
    int ans = 0;

    for(auto x : adj[curr])
    {
        if(x != prev)
        {
            int res = dfs(curr,x,adj,hasApple);
            if(res > 0 || hasApple[x])
            {
                ans += (res+2);
            }
        }
    }

    return ans;
}

int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
{
    vector<vector<int>> adj(n);

    for(auto &x : edges)
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }       

    return dfs(-1,0,adj,hasApple); 
}



int main()
{
    return 0;
}