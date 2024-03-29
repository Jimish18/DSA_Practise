/*
Question - Set Matrix Zeroes

Link - https://leetcode.com/problems/set-matrix-zeroes/
*/
#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) 
{
    bool row = false, col = false;
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[0].size(); j++)
        {
            if(matrix[i][j] == 0) 
            {
                if(i == 0) row = true;
                if(j == 0) col = true;
                matrix[0][j] = matrix[i][0] = 0;
            }
        }
    }
    for(int i = 1; i < matrix.size(); i++)
    {
        for(int j = 1; j < matrix[0].size(); j++)
        {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
        }
    }
    if(col)
    {
        for(int i = 0; i < matrix.size(); i++) matrix[i][0] = 0;
    }
    if(row)
    {
        for(int j = 0; j < matrix[0].size(); j++) matrix[0][j] = 0;
    }
}

// Space Complexity = O(m+n)
// void setZeroes(vector<vector<int>>& matrix) 
// {
//     set<int> zCol;
//     set<int> zRow;
//     int n = matrix.size();
//     int m = matrix[0].size();

//     for(int i = 0 ; i < n; i++)
//     {
//         for(int j = 0; j < m ; j++)
//         {
//             if(matrix[i][j] == 0)
//             {
//                 zCol.insert(j);
//                 zRow.insert(i);
//             }
//         }
//     }

//     for(auto x : zCol)
//     {
//         for(int i = 0; i < n ; i++)
//         {
//             matrix[i][x] = 0;
//         }
//     }

//     for(auto x : zRow)
//     {
//         for(int i = 0; i < m ; i++)
//         {
//             matrix[x][i] = 0;
//         }
//     }
// }

int main()
{
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    // {{0,1,2,0},{3,4,5,2},{1,3,1,5}}
    // {{1,1,1},{1,0,1},{1,1,1}}

    for(int i = 0 ; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size() ; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    setZeroes(matrix);

    cout<<"After Setting Zeroes"<<endl;

    for(int i = 0 ; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size() ; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}