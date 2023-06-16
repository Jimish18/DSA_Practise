/*
Quesion - Implementing Dijkstra Algorithm

Link - https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
*/

#include <bits/stdc++.h>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> ans(V,1e9);
    priority_queue<pair<int,int> , vector<pair<int,int>>,greater<pair<int,int>>> minH;
    minH.push({0,S});
    ans[S] = 0; 

    while(!minH.empty())
    {
        int node = minH.top().second;
        int wt = minH.top().first;
        minH.pop();

        for(auto x : adj[node])
        {
            int edgeWt = x[1];
            int adjNode = x[0];

            if(wt + edgeWt < ans[adjNode])
            {
                ans[adjNode] = wt + edgeWt;
                minH.push({wt+edgeWt,adjNode});
            }
        }
    }

    return ans;
}

int main()
{
    return 0;
}