/*
Question - Detonate The maximum Bombs

Link - https://leetcode.com/problems/detonate-the-maximum-bombs/
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj , vector<bool> &visited,int &node , int &count)
{
    visited[node] = true;
    count++;

    for(auto x : adj[node])
    {
        if(!visited[x]) dfs(adj,visited,x,count);
    }
}

int maximumDetonation(vector<vector<int>>& bombs) 
{
    int n = bombs.size();
    vector<vector<int>> adj(n);

    for(int i = 0; i < n ; i++)
    {
        long long x1 = bombs[i][0];
        long long y1 = bombs[i][1];
        long long r1 = bombs[i][2];

        for(int j = 0; j < n ; j++)
        {
            if(i != j)
            {
                long long x = abs(x1-bombs[j][0]);
                long long y = abs(y1-bombs[j][1]);

                if(x*x + y*y <= r1*r1) adj[i].push_back(j);
            }
        }
    }   

    int ans = INT_MIN;

    for(int i = 0 ; i < n; i++)
    {
        int count = 0;
        vector<bool> visited(n,false);
        dfs(adj,visited,i,count);
        ans = max(ans,count);
    } 

    return ans;
}

int main()
{
    return 0;
}