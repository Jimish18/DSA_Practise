/*
Question - 01 Matrix

Link - https://leetcode.com/problems/01-matrix/
*/

#include <bits/stdc++.h>
using namespace std; 

vector<int> dr = {0,0,1,-1};
vector<int> dc = {1,-1,0,0};


vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
{
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> ans(n , (vector<int> (m)));
    vector<vector<bool>> visited(n,vector<bool> (m,false));
    queue<pair<pair<int,int>,int>> q;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m ; j++)
        {
            if(mat[i][j] == 0)
            {
                visited[i][j] = true;
                q.push({{i,j},0});
            }
        }
    } 

    while(!q.empty())
    {
        int nn = q.size();

        for(int i = 0 ; i < nn; i++)
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            ans[x][y] = dis;

            for(int j = 0; j < 4; j++)
            {
                int newX = x + dr[j];
                int newY = y + dc[j];

                if(newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY])
                {
                    visited[newX][newY] = true;
                    q.push({{newX,newY},dis+1});
                }
            }


        }
    }   

    return ans;
}

int main()
{
    return 0;
}