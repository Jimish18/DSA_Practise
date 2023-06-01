/*
Question - Shortest Path in Binary Matrix

Link - https://leetcode.com/problems/shortest-path-in-binary-matrix/
*/

#include <bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
{
    if(grid[0][0]) return -1;
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,int>> q;
    q.push({0,0});
    vector<vector<bool>> visited(n , vector<bool> (m,false));
    visited[0][0] = true;

    vector<int> dr = {0,0,1,-1,1,1,-1,-1};
    vector<int> dc = {1,-1,0,0,-1,1,1,-1};

    int distance = 0;

    while(!q.empty())
    {
        int nn = q.size();
        distance++;

        for(int i = 0; i < nn; i++)
        {
            pair<int,int> temp = q.front();
            q.pop();
            int x = temp.first;
            int y = temp.second;

            if(x == n-1 && y == m-1) return distance;

            for(int i = 0 ; i < 8 ; i++)
            {
                int newX = x + dr[i];
                int newY = y + dc[i];

                if(newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY] && grid[newX][newY] == 0)
                {
                    q.push({newX,newY});
                    visited[newX][newY] = true;
                }
            }


        }
    }

    return (visited[n-1][m-1]) ? distance : -1;
}

int main()
{
    return 0;
}