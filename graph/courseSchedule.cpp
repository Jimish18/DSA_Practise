/*
Question - Course Schedule

Link - https://leetcode.com/problems/course-schedule/
*/

#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<bool> &visited,vector<bool> &pathVisited,vector<vector<int>> &adj,int node)
{
    visited[node] = true;
    pathVisited[node] = true;

    for(auto x : adj[node])
    {
        if(!visited[x])
        {
            if(dfs(visited,pathVisited,adj,x)) return true;
        }
        else if(pathVisited[x]) return true;
    }

    pathVisited[node] = false;
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
{
    vector<bool> visited(numCourses,false);
    vector<bool> pathVisited(numCourses,false);
    vector<vector<int>> adj;

    for(auto x : prerequisites)
    {
        adj[x[0]].push_back(x[1]);
    }

    for(int i = 0; i < numCourses; i++)
    {
        if(!visited[i])
        {
            if(dfs(visited,pathVisited,adj,i)) return true;
        }
    }

    return false;
}

int main()
{
    return 0;
}