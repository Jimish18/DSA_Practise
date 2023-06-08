/*
Question - Course Schedule II

Link - https://leetcode.com/problems/course-schedule-ii/
*/

#include <bits/stdc++.h>
using namespace std;

bool isCycle(vector<vector<int>> &adj , vector<bool> &visited , vector<bool> &pathVisited , int node)
{
    visited[node] = true;
    pathVisited[node] = true;

    for(auto x : adj[node])
    {
        if(!visited[x])
        {
            if(isCycle(adj,visited,pathVisited,x)) return true;
        }
        else if(pathVisited[x]) return true;
    }

    pathVisited[node] = false;
    return false;
}

void dfs(vector<vector<int>> &adj , vector<bool> &visited , int node , stack<int> &st)
{
    visited[node] = true;

    for(auto x : adj[node])
    {
        if(!visited[x]) dfs(adj,visited,x,st);
    }

    st.push(node);
}


vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
{
    vector<vector<int>> adj(numCourses);
    
    for(auto x : prerequisites)
    {
        adj[x[0]].push_back(x[1]);
    }

    vector<bool> visited(numCourses,false);
    vector<bool> pathVisited(numCourses,false);

    for(int i = 0; i < numCourses; i++)
    {
        if(isCycle(adj,visited,pathVisited,i)) return {};
    }

    vector<bool> vis2(numCourses,false);
    stack<int> st;

    for(int i = 0; i < numCourses; i++)
    {
        if(!vis2[i])
        {
            dfs(adj,vis2,i,st);
        }
    }

    vector<int> ans;

    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

int main()
{
    return 0;
}