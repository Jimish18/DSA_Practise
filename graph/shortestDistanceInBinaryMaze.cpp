/*
Question - Shortest Distance in a Binary Maze

Link - https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1
*/

#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> source,pair<int, int> destination) 
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> visited(n , vector<bool> (m,false)); 
    queue<pair<pair<int,int>,int>> q;
    q.push({source,0});
    visited[source.first][source.second] = true;

    vector<int> dr = {0,0,1,-1};
    vector<int> dc = {1,-1,0,0};

    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second;
        q.pop();


        if(destination.first == x && destination.second == y) return dist;

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dr[i];
            int ny = y + dc[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny])
            {
                q.push({{nx,ny},dist+1});
                visited[nx][ny] = true;
            }
        }
    }

    return -1;
}

int main()
{
    return 0;
}