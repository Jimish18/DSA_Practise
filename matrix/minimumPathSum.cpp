/*
Question - Minimum Path Sum

Link - https://leetcode.com/problems/minimum-path-sum/

*/

#include <bits/stdc++.h>
using namespace std;

// BruteForce Recursive Approach (TLE)
// int minimumPathSum(vector<vector<int>> grid,int row,int col,int sum)
// {
//     sum += grid[row][col];
//     if(row == grid.size()-1 && col == grid[0].size()-1)
//     {
//         return sum;
//     }

//     // take right    
//     int rigthSum = (col == grid[0].size()-1) ? minimumPathSum(grid,row+1,col,sum) : minimumPathSum(grid,row,col+1,sum);

//     // take to bottom    
//     int bottomSum = (row == grid.size()-1) ? minimumPathSum(grid,row,col+1,sum) : minimumPathSum(grid,row+1,col,sum);

//     return min(rigthSum,bottomSum);

// }

// int minPathSum(vector<vector<int>>& grid) 
// {
//     int minSum = minimumPathSum(grid,0,0,0);

//     return minSum;
// }

// DP approach
int minPathSum(vector<vector<int>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    vector<int> v(m,0);
    vector<vector<int>> dp(n,v);

    dp[0][0] = grid[0][0];

    for(int i = 1 ; i < n; i++)
    {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    for(int i = 1 ; i < m; i++)
    {
        dp[0][i] = dp[0][i-1] + grid[0][i];
    }

    for(int i = 1 ; i < n ; i++)
    {
        for(int j = 1 ; j < m ; j++)
        {
            dp[i][j] = min(dp[i][j-1],dp[i-1][j]) + grid[i][j];
        }
    }

    return dp[n-1][m-1];
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6}};

    // {{1,3,1},{1,5,1},{4,2,1}}
    // {{1,2,3},{4,5,6}}

    cout<<minPathSum(matrix)<<endl;
    return 0;
}