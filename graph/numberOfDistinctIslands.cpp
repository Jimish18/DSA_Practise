/*
Question - Number of distinct Islands

Link - https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dr = {0,0,1,-1};
vector<int> dc = {1,-1,0,0};

void dfs(vector<vector<int>>& grid,vector<vector<bool>> &visited , int i, int j,vector<pair<int,int>> &ds,int i0,int j0)
{
    int n = grid.size();
    int m = grid[0].size();

    visited[i][j] = true;
    ds.push_back({i-i0,j-j0});

    for(int k = 0 ; k < 4 ; k++)
    {
        int nx = i + dr[k];
        int ny = j + dc[k];

        if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] && !visited[nx][ny])
        {
            dfs(grid,visited,nx,ny,ds,i0,j0);
        }
    }
}

int countDistinctIslands(vector<vector<int>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n , vector<bool> (m,false));
    set<vector<pair<int,int>>> st;

    for(int i = 0; i < n ;i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] && !visited[i][j])
            {
                vector<pair<int,int>> ds;
                dfs(grid,visited,i,j,ds,i,j);
                st.insert(ds);
            }
        }
    }

    return st.size();
}

int main()
{
    return 0;
}