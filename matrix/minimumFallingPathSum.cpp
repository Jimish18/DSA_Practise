/*
Question - Minimum Falling Path Sum

Link - https://leetcode.com/problems/minimum-falling-path-sum/
*/

#include <bits/stdc++.h>
using namespace std;

// BruteForce Solution (TLE)
// int pathSum(vector<vector<int>> matrix,int sum,int row,int column)
// {
//     if(row == matrix.size())
//     {
//         return sum;
//     }

//     if(row != 0)
//     {
//         sum+= matrix[row][column];
//     }

//     int left = ((column-1) >=0) ? pathSum(matrix,sum,row+1,column-1):INT_MAX;
//     int bottom = pathSum(matrix,sum,row+1,column);
//     int right = ((column+1) <= matrix.size()-1) ? pathSum(matrix,sum,row+1,column+1):INT_MAX;

//     return min(min(right,left),bottom);
// }

// int minFallingPathSum(vector<vector<int>>& matrix) 
// {
//     int n = matrix[0].size();
//     int minSum = INT_MAX;
//     for(int i = 0 ; i < n ; i++)
//     {
//         int sum = pathSum(matrix,matrix[0][i],0,i);
//         minSum = min(minSum,sum);
//     }

//     return minSum;
// }

// DP solution
int minFallingPathSumHelper(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp)
{
    if(r == 0 and c < matrix[0].size() and c >= 0) return matrix[r][c]; 
    if(c >= matrix[0].size() or c < 0) return INT_MAX;
    
    if(dp[r][c] != INT_MAX) return dp[r][c];
    return dp[r][c] = matrix[r][c] + min(min(minFallingPathSumHelper(matrix, r-1, c+1, dp), minFallingPathSumHelper(matrix, r-1, c, dp)), minFallingPathSumHelper(matrix, r-1, c-1, dp));
    
}
int minFallingPathSum(vector<vector<int>>& matrix) 
{
    int rows = matrix.size(), cols = matrix[0].size();
    vector<vector<int>> dp(rows+1, vector<int>(cols+1, INT_MAX));
    int ans = INT_MAX;
    for(int c=0; c < cols; c++){
        ans = min(ans, minFallingPathSumHelper(matrix, rows-1, c, dp));
    }
    return ans;
}

int main()
{
    vector<vector<int>> v = {{-19,57},{-40,-5}};
    // {{2,1,3},{6,5,4},{7,8,9}}
    // {{-19,57},{-40,-5}}
    cout<<minFallingPathSum(v)<<endl;
    return 0;
}