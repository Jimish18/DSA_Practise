/*
Question - PalinDrome Partitioning

Link - https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &str , int i ,int j)
{
    while(i <= j)
    {
        if(str[i++] != str[j--]) return false;
    }

    return true;
}

int solve(string str,int i , int j , vector<vector<int>> &dp)
{
    if(i >= j) return 0;

    if(isPalindrome(str,i,j)) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mn = INT_MAX;

    for(int k = i ; k <= j-1; k++)
    {
        int left = (dp[i][k] != -1) ? dp[i][k] : solve(str,i,k,dp);
        int right = (dp[k+1][j] != -1) ? dp[k+1][j] : solve(str,k+1,j,dp);

        int tempAns = 1 + solve(str,i,k,dp) + solve(str,k+1,j,dp);

        mn = min(mn,tempAns);
    } 

    return dp[i][j] = mn;
}

int palindromicPartition(string str)
{
    vector<vector<int>> dp(str.length()+1 , vector<int> (str.length()+1 , -1));

    return solve(str,0,str.length()-1,dp);
}

int main()
{
    return 0;
}