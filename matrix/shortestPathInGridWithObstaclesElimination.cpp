/*
Question - Shortest Path in a Grid with Obstacles Elimination

Link - https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
*/

#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>>& grid, int k) 
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<bool>>> valid(n,vector<vector<bool> >(m,vector<bool>(k+1)));

    if(n == 1 && m == 1) return 0;

    queue<vector<int>> q;
    vector<int> dc = {-1,1,0,0};
    vector<int> dr = {0,0,1,-1};
    q.push({0,0,k});
    int level = 0;
    int N;

    while(!q.empty()) 
    {
        N = q.size();

        for(int i = 0; i < N; i++)
        {
            vector<int> temp = q.front();
            q.pop();
            int row = temp[0];
            int col = temp[1];

            if(row == n-1 && col == m-1) return level;

            for(int j = 0 ; j < 4 ; j++)
            {
                int newRow = row + dr[j];
                int newCol = col + dc[j];
                int count = temp[2];

                if(newRow >= 0 && newCol >= 0 && newRow < n && newCol < m)
                {
                    
                    if(grid[newRow][newCol] == 0 && !valid[newRow][newCol][count])
                    {
                        q.push({newRow,newCol,count});
                        valid[newRow][newCol][count] = true;
                    }

                    if(grid[newRow][newCol] == 1 && count > 0 && !valid[newRow][newCol][count-1])
                    {
                        q.push({newRow,newCol,count-1});
                        valid[newRow][newCol][count-1] = true;
                    }
                }
            }
        }
        level++;
    }  

    return -1;     
}

int main()
{
    return 0;
}

