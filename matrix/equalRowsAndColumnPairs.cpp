/*
Question - Equal Rows And Column Pair

Link - https://leetcode.com/problems/equal-row-and-column-pairs/
*/

#include <bits/stdc++.h>
using namespace std;

int equalPairs(vector<vector<int>>& grid) 
{
    int count = 0;
    int nRows = grid.size();
    int nCols = grid[0].size();
    map<vector<int>,int> st;

    for(int i = 0 ; i < nRows; i++)
    {        
        st[grid[i]]++;       
    }

    for(int i = 0 ; i < nRows; i++)
    {
        vector<int> temp;
        for(int j = 0 ; j < nCols; j++)
        {
            temp.push_back(grid[j][i]);
        }

        count += st[temp];
    }

    return count;        
}

int main()
{
    vector<vector<int>> matrix = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};

    cout<<equalPairs(matrix)<<endl;
    return 0;
}