/*
Question - Replace O's With X's

Link - https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    vector<vector<bool>> visited(n , vector<bool> (m,false));
    queue<pair<int,int>> q;

    for(int i = 0; i < n; i++)
    {
        if(mat[i][0] == 'O') 
        {
            q.push({i,0});
            visited[i][0] = true;
        }

        if(mat[i][m-1] == 'O') 
        {
            q.push({i,m-1});
            visited[i][m-1] = true;
        }

    }

    for(int i = 0; i < m; i++)
    {
        if(mat[0][i] == 'O') 
        {
            q.push({0,i});
            visited[0][i] = true;
        }

        if(mat[n-1][i] == 'O') 
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

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dr[i];
            int ny = y + dc[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && mat[nx][ny] == 'O')
            {
                q.push({nx,ny});
                visited[nx][ny] = true;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m ; j++)
        {
            if(mat[i][j] == 'O' && !visited[i][j]) mat[i][j] = 'X';
        }
    }

    return mat;
}

int main()
{
    return 0; 
}