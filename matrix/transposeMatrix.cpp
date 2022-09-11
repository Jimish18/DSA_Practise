/*
Question - Transpose Matrix

Link - https://leetcode.com/problems/transpose-matrix/
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix) 
{
    vector<vector<int>> transposeMatrix;
        int newRowSize = matrix[0].size();
        int newColumnSize = matrix.size();

    for(int i = 0 ; i < newRowSize; i++)
    {
        vector<int> temp;
        for(int j = 0 ; j < newColumnSize; j++)
        {            
            temp.push_back(matrix[j][i]); 
        }

        transposeMatrix.push_back(temp);
    }

    return transposeMatrix;
}

int main()
{
    vector<vector<int>> matrix;
    int row;
    cin>>row;
    int column;
    cin>>column;

    for(int i = 0 ; i < row; i++)
    {
        vector<int> temp;
        for(int j = 0 ; j < column; j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
    }
    vector<vector<int>> tp = transpose(matrix);

    for(int i = 0 ; i < tp.size(); i++)
    {
        for(int j = 0 ; j < tp[i].size(); j++)
        {
            cout<<tp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}