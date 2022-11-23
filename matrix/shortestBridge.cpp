/*
Question - Shortest Bridge

Link - https://leetcode.com/problems/shortest-bridge/
*/

#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> dr = {1,-1,0,0};
vector<int> dc = {0,0,1,-1};

void dfs(int i , int j , queue<pair<int,int>> &q,vector<vector<int>>& grid,vector<vector<bool>> &visit)
{
    visit[i][j] = true;
    q.push({i,j});

    for(int k = 0 ; k < 4; k++)
    {
        int newRow = i + dr[k];
        int newCol = j + dc[k];

        if(newCol < 0 || newRow < 0 || newRow >= n || newCol >= m || visit[newRow][newCol] == true || grid[newRow][newCol] == 0) continue;

        dfs(newRow,newCol,q,grid,visit);
    }
    
}

int shortestBridge(vector<vector<int>>& grid) 
{
    n = grid.size();
    m = grid[0].size();
    vector<bool> temp (m,false);
    vector<vector<bool>> visit(n,temp);
    bool flag  = false;
    int level = 0;

    queue<pair<int,int>> q;
    int N;

    for(int i = 0; i < n && !flag; i++)
    {
        for(int j = 0; j < m && !flag ; j++)
        {
            if(grid[i][j] == 1)
            {
                dfs(i,j,q,grid,visit);
                flag = true;
            }
        }
    }       

    while(!q.empty())
    {
        N = q.size();
        level++;

        for(int i = 0 ; i < N; i++)
        {
            auto temp = q.front();
            q.pop();

            int row = temp.first;
            int col = temp.second;

            for(int j = 0 ; j < 4; j++)
            {
                int newRow = row + dr[j];
                int newCol = col + dc[j];

                if(newRow < 0 || newCol < 0 || newRow >= n || newCol >= m || visit[newRow][newCol] == true) continue;

                if(grid[newRow][newCol] == 1) return (level-1);

                q.push({newRow,newCol});
                visit[newRow][newCol] = true;
            }
        }
    }    

    return -1;   
}

int main()
{
    vector<vector<int>> v = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
    // {1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}
    // {0,1,0},{0,0,0},{0,0,1}
    cout<<shortestBridge(v)<<endl;

    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0 ; j < v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}