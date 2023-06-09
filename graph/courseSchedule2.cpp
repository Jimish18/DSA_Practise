/*
Question - Course Schedule II

Link - https://leetcode.com/problems/course-schedule-ii/
*/

#include <bits/stdc++.h>
using namespace std;

//     bool isCycle(vector<vector<int>> &adj , vector<bool> &visited , vector<bool> &pathVisited , int node)
// {
//     visited[node] = true;
//     pathVisited[node] = true;

//     for(auto x : adj[node])
//     {
//         if(!visited[x])
//         {
//             if(isCycle(adj,visited,pathVisited,x)) return true;
//         }
//         else if(pathVisited[x]) return true;
//     }

//     pathVisited[node] = false;
//     return false;
// }


// // Topological Sort DFS Question
// void dfs(vector<vector<int>> &adj , vector<bool> &visited , int node , stack<int> &st)
// {
//     visited[node] = true;

//     for(auto x : adj[node])
//     {
//         if(!visited[x]) dfs(adj,visited,x,st);
//     }

//     st.push(node);
// }


// vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
// {
//     vector<vector<int>> adj(numCourses);
    
//     for(auto x : prerequisites)
//     {
//         adj[x[0]].push_back(x[1]);
//     }

//     vector<bool> visited(numCourses,false);
//     vector<bool> pathVisited(numCourses,false);

//     for(int i = 0; i < numCourses; i++)
//     {
//         if(isCycle(adj,visited,pathVisited,i)) return {};
//     }

//     vector<bool> vis2(numCourses,false);
//     stack<int> st;

//     for(int i = 0; i < numCourses; i++)
//     {
//         if(!vis2[i])
//         {
//             dfs(adj,vis2,i,st);
//         }
//     }

//     vector<int> ans;

//     while(!st.empty())
//     {
//         ans.insert(ans.begin(),st.top());
//         st.pop();
//     }

//     return ans;
// }

// Using TopoSort's Kahn's Algorithm 
// Easiest Way
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
{
    vector<vector<int>> adj(numCourses);
    
    for(auto x : prerequisites)
    {
        adj[x[0]].push_back(x[1]);
    }

    vector<int> inDegree(numCourses , 0);

    for(int i = 0 ; i < numCourses; i++)
    {
        for(auto x : adj[i])
        {
            inDegree[x]++;
        }
    }

    queue<int> q;

    for(int i = 0; i < numCourses; i++)
    {
        if(inDegree[i] == 0) q.push(i);
    }

    vector<int> topoOrder;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topoOrder.insert(topoOrder.begin(),node);

        for(auto x : adj[node])
        {
            inDegree[x]--;

            if(inDegree[x] == 0) q.push(x);
        }        
    }

    if(topoOrder.size() != numCourses) return {};

    return topoOrder;
}

int main()
{
    return 0;
}