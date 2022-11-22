/*
Question - Shortest Bridge

Link - https://leetcode.com/problems/shortest-bridge/
*/

#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> dc = {0,0,1,-1};
vector<int> dr = {1,-1,0,0};

void dfs(int i , int j , queue<pair<int,int>> &q,vector<vector<int>>& grid)
{
    if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0 || grid[i][j] == -1) return;

    grid[i][j] = -1;

    q.push({i,j});

    for(int k = 0 ; k < 4 ; k++)
    {
        int newRow = i + dr[k];
        int newCol = j + dc[k];

        dfs(newRow,newCol,q,grid);
    }
    
}

int shortestBridge(vector<vector<int>>& grid) 
{
    n = grid.size();
    m = grid[0].size();
    bool flag  = false;
    int level = 0;

    queue<pair<int,int>> q;
    int N;

    for(int i = 0; i < n && !flag; i++)
    {
        for(int j = 0 ; j < m && !flag; j++)
        {
            if(grid[i][j]) dfs(i,j,q,grid);
            flag = true;
        }
    }

    while(!q.empty())
    {
        level++;
        N = q.size();

        for(int i = 0; i < N ; i++)
        {
            auto temp = q.front();
            q.pop();

            int row = temp.first;
            int col = temp.second;

            grid[row][col] = -1;

            for(int j = 0; j < 4; j++)
            {
                int newRow = row + dr[j];
                int newCol = col + dc[j];

                if(newRow >= 0 && newCol >= 0 && newRow < n && newCol < m)
                {
                    if(grid[newRow][newCol] == 1) return level;

                    if(grid[newRow][newCol] == 0) q.push({newRow,newCol});
                }
            }
        }
    }

    return -1;            
}

int main()
{
    return 0;
}