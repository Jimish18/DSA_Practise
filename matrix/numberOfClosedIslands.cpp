/*
Question - Number Of Closed Islands

Link - https://leetcode.com/problems/number-of-closed-islands/
*/

#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& grid,vector<vector<bool>> &visited, int i , int j,int n , int m)
{
    if(i >= 0 && i < n && j >= 0 && j < m)
    {
        if(grid[i][j] == 1) return true;

        if(!visited[i][j])
        {
            visited[i][j] = true;
            bool left = dfs(grid,visited,i,j-1,n,m);
            bool right = dfs(grid,visited,i,j+1,n,m);
            bool up = dfs(grid,visited,i-1,j,n,m);
            bool down = dfs(grid,visited,i+1,j,n,m);

            if(left && right && up && down) return true;
            else false;
        }
        else return true;
    }
    
    return false;
}

int closedIsland(vector<vector<int>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n,vector<bool> (m,false));
    int count = 0;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0; j < m ; j++)
        {
            if(!visited[i][j] && grid[i][j] == 0)
            {
                bool isIsland = dfs(grid,visited,i,j,n,m);
                if(isIsland) count++;
            }
        }
    }  

    return count;      
}

int main()
{
    return 0;
}