/*
Question - count sub Islands

Link - https://leetcode.com/problems/count-sub-islands/
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j,bool &flag)
{
    if(i < 0 || j < 0 || i >= grid1.size() || j >= grid1[0].size() || !grid2[i][j])
    {
        return ;
    }

    if(!grid1[i][j]) flag = false;

    grid2[i][j] = 0;

    dfs(grid1,grid2,i-1,j,flag);
    dfs(grid1,grid2,i+1,j,flag);
    dfs(grid1,grid2,i,j-1,flag);
    dfs(grid1,grid2,i,j+1,flag);
}

int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
{
    int count = 0;
    int n = grid1.size();
    int m = grid1[0].size();


    for(int i = 0; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(grid2[i][j] && grid1[i][j])
            {
                bool flag = true;
                dfs(grid1,grid2,i,j,flag);

                if(flag) count++;
            }
        }
    }        

    return count;
}

int main()
{
    return 0;
}