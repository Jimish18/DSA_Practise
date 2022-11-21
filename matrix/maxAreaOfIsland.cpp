/*
Question - Max Area Of Island

Link - https://leetcode.com/problems/max-area-of-island/
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& grid,int i,int j,int &area)
{
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || !grid[i][j])
    {
        return;
    }


    if(grid[i][j])
    {
        area++;

        grid[i][j] = 0;
    }

    dfs(grid,i-1,j,area);
    dfs(grid,i+1,j,area);
    dfs(grid,i,j+1,area);
    dfs(grid,i,j-1,area);

}

int maxAreaOfIsland(vector<vector<int>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    int maxArea = 0;
    int area = 0;    

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j])
            {
                dfs(grid,i,j,area);

                maxArea = max(maxArea,area);
                area = 0;
            }
        }
    }   

    return maxArea;     
}

int main()
{
    return 0;
}
