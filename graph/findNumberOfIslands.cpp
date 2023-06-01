/*
Question - Find Number Of Islands

Link - https://www.codingninjas.com/codestudio/problems/630512?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dr = {0,0,1,-1,1,1,-1,-1};
vector<int> dc = {1,-1,0,0,1,-1,-1,1};

void dfs(int** &arr, int n, int m,int i,int j)
{
    if(i < n && i >= 0 && j >= 0 && j < m && arr[i][j])
    {
        arr[i][j] = 0;

        for(int k = 0; k < 8; k++)
        {
            int newX = i + dr[k];
            int newY = j + dc[k];

            dfs(arr,n,m,newX,newY);
        }
    }
}

int getTotalIslands(int** arr, int n, int m)
{
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m ; j++)
        {
            if(arr[i][j]) 
            {
                count++;
                dfs(arr,n,m,i,j);
            }
        }
    }

    return count;
}


int main()
{
    return 0;
}