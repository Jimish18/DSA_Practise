/*
Question - Minimum Insertion Steps To Make a String Palindrome

Link - https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
*/

#include <bits/stdc++.h>
using namespace std;

int minInsertions(string s) 
{
    int n = s.length();
    vector<vector<int>> dp(n+1 , vector<int> (n+1));
    string t = s;
    reverse(t.begin(),t.end());

    for(int i = 0 ;i <=n ;i++)
    {
        for(int j = 0 ; j <= n ; j++)
        {
            if(i == 0 || j== 0) dp[i][j] = 0;
            else
            {
                if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
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