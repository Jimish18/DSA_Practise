/*
Question - Longest Palindromic Subsequence

Link - https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1
*/

#include <bits/stdc++.h>
using namespace std;

int longestPalinSubseq(string A) 
{
    string b = A;
    reverse(b.begin(),b.end());

    int n = A.length();

    vector<vector<int>> dp(n+1 , vector<int> (n+1));

    for(int i = 0; i <= n ; i++)
    {
        for(int j = 0; j <= n ; j++)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else
            {
                if(A[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    return dp[n][n];
}

int main()
{
    return 0;
}