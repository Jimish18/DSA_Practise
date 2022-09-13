/*
Question - Find Valid Matrix Given Rows And Column

Link - https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) 
{        
    int numberOfRows = rowSum.size();
    int numberOfColumns = colSum.size();
    vector<int> v(numberOfColumns,0);
    vector<vector<int>> matrix(numberOfRows,v);
    
    
    for(int i = 0 ; i < numberOfRows; i++)
    {
        for(int j = 0 ; j < numberOfColumns; j++)
        {
            int element = min(rowSum[i],colSum[j]);
            matrix[i][j] = element;
            rowSum[i] -= element;
            colSum[j] -= element;                
        }
    }
    
    return matrix;
}

int main() {
    
    vector<int> rowSum = {3,8};
    vector<int> colSum = {4,7};
    
    vector<vector<int>> matrix = restoreMatrix(rowSum,colSum);
    
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0 ; j < matrix[i].size(); j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}