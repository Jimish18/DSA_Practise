/*
Question - Minimum Number of Deletions

Link - https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
*/

#include <bits/stdc++.h>
using namespace std;

int minDeletions(string str, int n) 
{ 
    string temp = str;
    reverse(temp.begin(),temp.end());
    
    vector<vector<int>> dp(n+1 , vector<int> (n+1));
    
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n ; j++)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else
            {
                if(str[i-1] == temp[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    
    return (n-dp[n][n]);
} 

int main()
{
    return 0;
}