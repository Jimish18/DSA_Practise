/*
Question - Search a 2D Matrix II

Link - https://leetcode.com/problems/search-a-2d-matrix-ii/
*/

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int n = matrix.size();
    int m = matrix[0].size();
    int i = 0,j = m-1;

    while(i < n && j >= 0)
    {
        if(matrix[i][j] == target) return true;

        if(target < matrix[i][j]) j--;
        else if(target > matrix[i][j]) i++;
        
    }
    return false;        
}

int main()
{
    vector<vector<int>> v = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<searchMatrix(v,13)<<endl;
    return 0;
}