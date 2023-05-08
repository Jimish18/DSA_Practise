/*
Question - Matrix Diagonal Sum

Link - https://leetcode.com/problems/matrix-diagonal-sum/description/
*/

#include <bits/stdc++.h>
using namespace std;

int diagonalSum(vector<vector<int>>& mat) 
{
    int sum = 0;
    int n = mat.size();
    int i = 0;
    int j = 0;
    int k = n-1;

    while(i < n && j < n)
    {
        if(j == k) sum += mat[i][j];
        else sum += mat[i][j] + mat[i][k];
        i++;j++;k--;
    }

    return sum;            
}

int main()
{
    return 0;
}