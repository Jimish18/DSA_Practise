/*
Question - Number Of Islands 

Link - https://leetcode.com/problems/number-of-islands/
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& grid,int i,int j)
{
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0')
    {
        return ;
    }

    if(grid[i][j])
    {
        grid[i][j] = '0';
    }

    dfs(grid,i,j-1);
    dfs(grid,i,j+1);
    dfs(grid,i+1,j);
    dfs(grid,i-1,j);
}

int numIslands(vector<vector<char>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    int total = 0;

    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == '1')
            {
                dfs(grid,i,j);

                total++;
            }
        }
    }   

    return total;     
}

int main()
{
    return 0;
}