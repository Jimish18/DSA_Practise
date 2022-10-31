/*
Question - Toeplitz Matrix

Link - https://leetcode.com/problems/toeplitz-matrix/
*/

#include <bits/stdc++.h>
using namespace std;

bool isToeplitzMatrix(vector<vector<int>>& matrix) 
{
    int n = matrix.size();
    int m = matrix[0].size();
    int number = matrix[0][0];

    int i = m-1,j = m-1,k = 0;

    while(i >= 0)
    {   
        j = i;
        k = 0;
        int number = matrix[k][j];
        while(k < n && j < m)
        {
            if(matrix[k][j] != number) return false;
            j++;
            k++;
        }
        i--;
    }

    i = 1;
    
    while(i < n)
    {
        k = i;
        j = 0;
        int number = matrix[k][j];
        while(k < n && j < m)
        {
            if(matrix[k][j] != number) return false;
            j++;
            k++;
        }
        i++;
    }

        return true;
}

int main()
{
    return 0;
}