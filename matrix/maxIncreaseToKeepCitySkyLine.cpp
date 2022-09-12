/*
Question - Max Increase to Keep City skyline 

Link - https://leetcode.com/problems/max-increase-to-keep-city-skyline/
*/

#include <bits/stdc++.h>
using namespace std; 

int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) 
{
    int maxCount = 0;
    int n = grid.size();
    vector<int> columnMax(n,0);
    vector<int> rowMax(n,0);

    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            columnMax[j] = max(columnMax[j],grid[i][j]);
            rowMax[i] = max(rowMax[i],grid[i][j]);
        }
    }  

    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            maxCount += min(rowMax[i],columnMax[j]) - grid[i][j];
        }
    }   

    return maxCount;
}


int main()
{
    vector<vector<int>> matrix = {{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};

    cout<<maxIncreaseKeepingSkyline(matrix)<<endl;
    return 0;
}