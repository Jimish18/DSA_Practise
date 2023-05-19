/*
Question - Longest Repeating Subsequence

Link - https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
*/

#include <bits/stdc++.h>
using namespace std;

int LongestRepeatingSubsequence(string str)
{
    string temp = str;
    
    int n = str.length();
    vector<vector<int>> dp(n+1 , vector<int> (n+1));
    
    for(int i = 0 ; i <= n; i++)
    {
        for(int j = 0 ; j <= n; j++)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else
            {
                if((str[i-1] == temp[j-1]) && (i != j)) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    int i = n;
    int j = n;
    string ans = "";

    while(i != 0 && j != 0)
    {
        if((str[i-1] == temp[j-1]) && i != j)
        {
            ans.insert(ans.begin(),str[i-1]);
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        } 
    }

    cout<<ans<<endl;
    
    return dp[n][n];
}


int main()
{
    string temp = "AABEBCDD";
    cout<<LongestRepeatingSubsequence(temp)<<endl;
    return 0;
}