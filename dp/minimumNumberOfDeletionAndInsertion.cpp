/*
Question - Minimum Number Of Insertion And Deletion

Link - https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
*/

#include <bits/stdc++.h>
using namespace std;

int minOperations(string str1, string str2) 
{ 
    int n = str1.length();
    int m = str2.length();

    vector<vector<int>> dp(n+1 , vector<int> (m+1));

    for(int i = 0 ; i <= n ; i++)
    {
        for(int j = 0 ; j <= m ;j++)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else
            {
                if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    int lcs = dp[n][m];

    return ((n-lcs) + (m-lcs));
    
} 


int main()
{
    return 0;
}