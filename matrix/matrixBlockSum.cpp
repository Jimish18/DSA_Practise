/*
Question - Matrix Block Sum

Link - https://leetcode.com/problems/matrix-block-sum/
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) 
{
    int nRows = mat.size();
    int nCols = mat[0].size();
    vector<int> column(nCols,0);
    vector<vector<int>> matrix(nRows,column);

    for(int i = 0 ; i < nRows; i++)
    {
        for(int j = 0 ; j < nCols ; j++)
        {
            int rStart = (i-k)<0 ? 0 : (i-k);
            int rEnd = (i+k) > (nRows-1) ? (nRows-1) : (i+k);

            int cStart = (j-k)<0 ? 0 : (j-k);
            int cEnd = (j+k) > (nCols-1) ? (nCols-1) : (j+k);

            int tempSum = 0;

            for(int l = rStart; l <= rEnd ; l++)
            {
                for(int m = cStart ; m <= cEnd; m++)
                {
                    tempSum += mat[l][m];
                }
            }

            matrix[i][j] = tempSum;
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};

    vector<vector<int>> matrix = matrixBlockSum(mat,2);

    for(int i = 0 ; i < matrix.size(); i++)
    {
        for(int j = 0 ; j < matrix[i].size(); j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}