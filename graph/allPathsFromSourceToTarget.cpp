/*
Question - All Paths From Source To Target

Link - https://leetcode.com/problems/all-paths-from-source-to-target/
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& graph,vector<vector<int>> &result,vector<int> temp,int node,int n)
{
    for(auto x : graph[node])
    {
        temp.push_back(x);

        if(x == n-1)
        {
            result.push_back(temp);
        }

        dfs(graph,result,temp,x,n);
        temp.pop_back();
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
{
    vector<vector<int>> result;
    int n = graph.size();
    vector<int> temp;
    
    temp.push_back(0);
    dfs(graph,result,temp,0,n);

    return result;    
}

int main()
{
    return 0;
}