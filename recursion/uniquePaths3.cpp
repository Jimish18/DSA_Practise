/*
Question - Unique Paths III

Link - https://leetcode.com/problems/unique-paths-iii/
*/

#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& grid,int i,int j,int zeros)
{
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1) return 0;

    if(grid[i][j] == 2) return (zeros == -1) ? 1 : 0;

    zeros--;
    grid[i][j] = -1;

    int totalPaths = dfs(grid,i,j-1,zeros) + dfs(grid,i,j+1,zeros) + dfs(grid,i+1,j,zeros) + dfs(grid,i-1,j,zeros);

    zeros++;
    grid[i][j] = 0; //backtrack

    return totalPaths;
    
}

int uniquePathsIII(vector<vector<int>>& grid) 
{
    int zeros = 0;
    int sx,sy;
    int n = grid.size();
    int m = grid[0].size();

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m ; j++)
        {
            if(grid[i][j] == 0) zeros++;
            else if(grid[i][j] == 1)
            {
                sx = i;
                sy = j;
            }
        }
    }

    return dfs(grid,sx,sy,zeros);

}

int main()
{
    return 0;
}