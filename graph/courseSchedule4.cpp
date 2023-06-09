/*
Question - Course Schedule IV

Link - https://leetcode.com/problems/course-schedule-iv/
*/

#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &adj, vector<bool> &visited, int src , int des)
{
    visited[src] = true;

    if(src == des) return true;

    for(auto x : adj[src])
    {
        if(!visited[x])
        {
            if(dfs(adj,visited,x,des)) return true;
        }
    }

    return false;
}

vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
{
    vector<vector<int>> adj(numCourses);

    for(auto x : prerequisites)
    {
        adj[x[0]].push_back(x[1]);
    }                  

    int n = queries.size();
    vector<bool> ans(n);

    for(int i = 0; i < n ; i++)
    {
        int src = queries[i][0];
        int des = queries[i][1];

        vector<bool> visited(numCourses,false);
        ans[i] = dfs(adj,visited,src,des);
    }

    return ans;
}

int main()
{
    return 0;
}