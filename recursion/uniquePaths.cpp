/*
Quetion - Unique Paths

Link - https://leetcode.com/problems/unique-paths/
*/

#include <bits/stdc++.h>
using namespace std;

// Combinatrics Approach
// int uniquePaths(int m, int n) 
// {
//     int N = n+m-2;
//     int r = m-1;
//     double res = 1;

//     for(int i = 1; i <= r ; i++)
//     {
//         res = res*(N-r+i)/i;
//     }
        
//     return (int)res;          
// }

// int uniquePaths(int m, int n) 
// {
//     if(m == 1 || n == 1)
//         return 1;
//     m--;
//     n--;
//     if(m < n) {              // Swap, so that m is the bigger number
//         m = m + n;
//         n = m - n;
//         m = m - n;
//     }
//     long res = 1;
//     int j = 1;
//     for(int i = m+1; i <= m+n; i++, j++){       // Instead of taking factorial, keep on multiply & divide
//         res *= i;
//         res /= j;
//     }
        
//     return (int)res;          
// }

// Recursive Way - TLE
// int countUniquePaths(int m,int n,int i,int j)
// {
//     if(i == m-1 && j == n-1)
//     {
//         return 1;
//     }

//     if(i >= m || j >= n)
//     {
//         return 0;
//     }

//     return countUniquePaths(m,n,i+1,j) + countUniquePaths(m,n,i,j+1);
// }

// int uniquePaths(int m, int n) 
// {
//     return countUniquePaths(m,n,0,0);          
// }

// Memoization
// int dfs(int m,int n,vector<vector<int>> &dp,int i,int j)
// {
//     if(i >= m || j >= n) return 0;
//     if(i == m-1 && j == n-1) return 1;

//     if(dp[i][j] != -1) return dp[i][j];

//     return dp[i][j] = dfs(m,n,dp,i+1,j) + dfs(m,n,dp,i,j+1);
// }

// int uniquePaths(int m, int n) 
// {
//     vector<vector<int>> dp(m+1,(vector<int> (n+1,-1)));

//     return dfs(m,n,dp,0,0);
// }

// DP - Tabulation 
int uniquePaths(int m, int n) 
{
    vector<vector<int>> dp(m,(vector<int> (n,0)));
    
    dp[0][0] = 1;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i > 0) dp[i][j] = dp[i][j] + dp[i-1][j];
            if(j > 0) dp[i][j] = dp[i][j] + dp[i][j-1];
        }
    }

    return dp[m-1][n-1];
}



int main()
{
    cout<<uniquePaths(3,2)<<endl;
    return 0;
}