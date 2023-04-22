/*
Question - Minimum Insertion Steps To Make a String Palindrome

Link - https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
*/

#include <bits/stdc++.h>
using namespace std;

int dfs(string s, string t , int i, int j,vector<vector<int>> &dp)
{
    if(i < 0 || j < 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == t[j])
    {
        return dp[i][j] = 1 + dfs(s,t,i-1,j-1,dp);
    }
    else
    {
        return dp[i][j] = max(dfs(s,t,i,j-1,dp),dfs(s,t,i-1,j,dp));
    }

    return dp[i][j];
}


int minInsertions(string s) 
{
    int n = s.length();
    vector<<vector<int>> dp(n+1 , vector<int> (n+1,-1));
    string t = s;
    reverse(t.begin(),t.end());

    int l = dfs(s , t , n-1,n-1,dp);

    return n-l;

}

int main()
{
    return 0;
}