/*
Question - Course Schedule

Link - https://leetcode.com/problems/course-schedule/
*/

#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &adj ,vector<int> &visited,int node)
{
    visited[node] = true;

    for(auto x : adj[node])
    {
        if(visited[x]) return false;
        else return dfs(adj,visited,x);
    }

    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
{
    vector<int> visited(numCourses,false);
    vector<vector<int>> adj(numCourses);

    for(auto x : prerequisites)
    {
        adj[x[0]].push_back(x[1]);
    }

    for(int i = 0; i < numCourses; i++)
    {
        if(!dfs(adj,visited,i)) return false;
    }

    return true;
}

int main()
{
    return 0;
}