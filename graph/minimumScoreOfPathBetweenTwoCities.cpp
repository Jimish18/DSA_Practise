/*
Question - Minimum Score of a Path Between Two Cities

Link - https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
*/

#include <bits/stdc++.h>
using namespace std;

int minScore(int n, vector<vector<int>>& roads) 
{
    vector<vector<int>> adj[n+1];

    for(auto x : roads)
    {
        adj[x[0]].push_back({x[1],x[2]});
        adj[x[1]].push_back({x[0],x[2]});
    }        

    vector<bool> visited(n+1,false);
    queue<vector<int>> q;
    int result = INT_MAX;

    visited[1] = true;
    q.push({1,INT_MAX});
    
    while(!q.empty())
    {
        int node = q.front()[0];
        q.pop();

        for(auto x : adj[node])
        {
            result = min(result,x[1]);
            if(!visited[x[0]])
            {
                visited[x[0]] = true;
                q.push({x[0],x[1]});
            }
        }
    }

    return result;

}

int main()
{
    return 0;
}