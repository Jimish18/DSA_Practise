/*
Question - Spiral Matrix II

Link - https://leetcode.com/problems/spiral-matrix-ii/
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int n) 
{
    vector<int> v(n,0);
    vector<vector<int>> matrix(n,v);

    int rowStart = 0;
    int rowEnd = n-1;
    int columnStart = 0;
    int columnEnd = n-1;

    int element = 1;

    while(rowStart <= rowEnd && columnStart <= columnEnd)
    {
        // For row start
        for(int col = columnStart ; col <= columnEnd ; col++)
        {
            matrix[rowStart][col] = element;
            element++;
        }
        if(++rowStart > rowEnd)
        {
            break;
        }

        // for column end
        for(int row = rowStart; row <= rowEnd; row++)
        {
            matrix[row][columnEnd] = element;
            element++;
        }
        if(--columnEnd < columnStart)
        {
            break;
        }

        // for row end
        for(int col = columnEnd ; col >= columnStart; col--)
        {
            matrix[rowEnd][col] = element;
            element++;
        }
        if(--rowEnd < rowStart)
        {
            break;
        }

        // for column start
        for(int row = rowEnd; row >= rowStart; row--)
        {
            matrix[row][columnStart] = element;
            element++;
        }
        if(columnStart++ > columnEnd)
        {
            break;
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = generateMatrix(5);

    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[0].size(); j++)
        {
            cout<<matrix[i][j]<<" ";
        }    
        cout<<endl;

    }
    return 0;
}