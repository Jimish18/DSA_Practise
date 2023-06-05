/*
Question - Number Of Enclaves

Link - https://practice.geeksforgeeks.org/problems/number-of-enclaves/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-enclaves
*/

#include <bits/stdc++.h>
using namespace std;

int numberOfEnclaves(vector<vector<int>> &grid) 
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> visited(n, vector<bool> (m,false));
    queue<pair<int,int>> q;

    for(int i = 0; i < n ; i++)
    {
        if(grid[i][0] && !visited[i][0])
        {
            q.push({i,0});
            visited[i][0] = true;
        }

        if(grid[i][m-1] && !visited[i][m-1])
        {
            q.push({i,m-1});
            visited[i][m-1] = true;
        }
    }

    for(int i = 0; i < m ; i++)
    {
        if(grid[0][i] && !visited[0][i])
        {
            q.push({0,i});
            visited[0][i] = true;
        }

        if(grid[n-1][i] && !visited[n-1][i])
        {
            q.push({n-1,i});
            visited[n-1][i] = true;
        }
    }

    vector<int> dr = {0,0,1,-1};
    vector<int> dc = {1,-1,0,0};

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4 ; i++)
        {
            int nx = x + dr[i];
            int ny = y + dc[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny])
            {
                q.push({nx,ny});
                visited[nx][ny] = true;
            }
        }
    }

    int count = 0;
    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j < m ; j++)
        {
            if(grid[i][j] && !visited[i][j]) count++;
        }
    }

    return count;
}

int main()
{
    return 0;
}