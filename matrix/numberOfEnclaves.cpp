/*
Question - Number Of Enclaves

Link - https://leetcode.com/problems/number-of-enclaves/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dr = {0,0,1,-1};
vector<int> dc = {1,-1,0,0};

int dfs(vector<vector<int>>& grid , vector<vector<bool>> &visited , int i , int j)
{
    if( i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j] || grid[i][j] == 0) return 0;
    
    int count = 1;
    visited[i][j] = true;
    for(int k = 0 ; k < 4 ;  k++)
    {
        count += dfs(grid,visited,i+dr[k],j+dc[k]);
    }

    return count;
}

int numEnclaves(vector<vector<int>>& grid) 
{
    int totalOnes = 0;
    int borderOnes = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n,vector<bool> (m,false));

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0; j < m ; j++)
        {
            if(grid[i][j] == 1) totalOnes++;
        }
    }

    for(int i = 0 ; i < m ; i++)
    {
        if(grid[0][i] == 1 && !visited[0][i])
        {
            borderOnes += dfs(grid,visited,0,i);
        }

        if(grid[n-1][i] == 1 && !visited[n-1][i])
        {
            borderOnes += dfs(grid,visited,n-1,i);
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(grid[i][0] == 1 && !visited[i][0])
        {
            borderOnes += dfs(grid,visited,i,0);
        }

        if(grid[i][m-1] == 1 && !visited[i][m-1])
        {
            borderOnes += dfs(grid,visited,i,m-1);
        }
    }

    return (totalOnes - borderOnes);
}

int main()
{
    return 0;
}