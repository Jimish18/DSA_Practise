/*
Question - Spiral Matrix III

Link - https://leetcode.com/problems/spiral-matrix-iii/
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) 
{
    vector<vector<int>> matrixCoOrdinates = {{rStart,cStart}};
    int dx = 0,dy = 1,temp;

    for(int i = 0 ; matrixCoOrdinates.size() < (rows*cols); i++)
    {
        for(int j = 0 ; j < (i/2)+1 ; j++)
        {
            rStart += dx;
            cStart += dy;

            if(0 <= rStart && rStart < rows && 0 <= cStart && cStart < cols)
            {
                matrixCoOrdinates.push_back({rStart,cStart});
            }
        }

        temp = dx;
        dx = dy;
        dy = -temp;
    }    

    return matrixCoOrdinates;      
}



int main()
{
    vector<vector<int>> v = spiralMatrixIII(1,4,0,0);

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