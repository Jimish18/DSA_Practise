/*
Question - Spiral Matrix III

Link - https://leetcode.com/problems/spiral-matrix-iii/
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) 
{
    vector<int> v(cols,0);
    vector<vector<int>> matrix(rows,v);

    return matrix;      
}

int main()
{
    vector<vector<int>> v = spiralMatrixIII(3,4,0,1);

    for(int i = 0 ; i< v.size(); i++)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}