/*
Question - Minimum Number of Vertices to Reach All Nodes

Link - https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
{
    vector<bool> visited(n,false);

    for(auto x : edges)
    {
        visited[x[1]] = true;
    }    

    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i]) ans.push_back(i);
    }

    return ans;
}

int main()
{
    return 0;
}