/*
Question - Possible Bipartition

Link - https://leetcode.com/problems/possible-bipartition/
*/

#include <bits/stdc++.h>
using namespace std;

// class Solution {
//     unordered_map<int,vector<int> > gr;
//     vector<int> vis;
//     vector<int> colo;
// public:
//     bool bfs(int u){
//         colo[u]=1;
//         queue<int> que;
//         que.push(u);
//         while(!que.empty()){
//             int i=que.front();
//             que.pop();
//             for(auto v:gr[i]){
//                 if(colo[v]==-1){
//                     colo[v]=1-colo[i];
//                     que.push(v);
//                 }
//                 else if(colo[v]==colo[i]){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
//     bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
//         for(auto d:dislikes){
//             gr[d[0]].push_back(d[1]);
//             gr[d[1]].push_back(d[0]);
//         }
//         colo.resize(N+1,-1);
//         for(int i=1;i<=N;i++){
//             if(colo[i]==-1){
//                 if(!bfs(i)){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };

bool bfs(vector<vector<int>> &adj , vector<int> &color , int i)
{
    queue<int> q;
    q.push(i);
    color[i] = 0;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto x : adj[node])
        {
            if(color[x] == -1)
            {
                color[x] = 1-color[node];
                q.push(x);
            }
            else if(color[x] == color[node]) return false;            
        }
    }

    return true;
}

bool possibleBipartition(int N, vector<vector<int>>& dislikes) 
{
    vector<vector<int>> adj(N+1);

    for(auto x : dislikes)
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }

    vector<int> color(N+1,-1);

    for(int i = 1 ; i < N+1; i++)
    {
        if(color[i] == -1)
        {
            if(!bfs(adj,color,i)) return false;
        }
    }

    return true;
}


int main()
{
    return 0;
}