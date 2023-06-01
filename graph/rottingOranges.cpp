/*
Question - Rotting Oranges

Link - https://leetcode.com/problems/rotting-oranges/
*/

#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(n , vector<bool> (m,false));

    int time = 0;

    vector<int> dr = {0,0,1,-1};
    vector<int> dc = {1,-1,0,0};

    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 2 && !visited[i][j])
            {
                visited[i][j] = true;
                q.push({i,j});

                while(!q.empty())
                {
                    int nn = q.size();

                    time++;

                    for(int k = 0; k < nn; k++)
                    {
                        pair<int,int> temp = q.front();
                        q.pop();
                        int x = temp.first;
                        int y = temp.second;

                        for(int l = 0 ; l < 4; l++)
                        {
                            int newX = x + dr[l];
                            int newY = y + dc[l];

                            if(newX < n && newX >= 0 && newY < m && newY >= 0 && !visited[newX][newY] && grid[newX][newY] == 1)
                            {
                                visited[newX][newY] = true;
                                grid[newX][newY] = 2;
                                q.push({newX,newY});
                            }
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 1) return -1;
        }
    }
    
    return time;
}

int main()
{
    return 0;
}