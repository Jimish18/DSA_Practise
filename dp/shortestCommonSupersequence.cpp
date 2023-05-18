/*
Question - Shortest Common SuperSequence

Link - https://leetcode.com/problems/shortest-common-supersequence/
*/

#include <bits/stdc++.h>
using namespace std;


// Bottom-Up memoization
// string dfs(string &str1, string &str2 , vector<vector<string>> &dp,int i,int j)
// {
//     if(i < 0) return str2.substr(0,(j-0 +1));
//     else if(j < 0) return str1.substr(0,(i-0 +1));

//     if(dp[i][j] != "") return dp[i][j];

//     if(str1[i] == str2[j])
//     {
//         return dp[i][j] = dfs(str1,str2,dp,i-1,j-1) + str1[i];
//     }
//     else
//     {
//         string s1 = dfs(str1,str2,dp,i-1,j) + str1[i];
//         string s2 = dfs(str1,str2,dp,i,j-1) + str2[j];

//         return dp[i][j] = (s1.length() > s2.length()) ? s2 : s1;
//     }

//     return "";
// }

// string shortestCommonSupersequence(string str1, string str2) 
// {
//     int n = str1.length();
//     int m = str2.length();
//     vector<vector<string>> dp (n, vector<string> (m,""));

//     return dfs(str1,str2,dp,n-1,m-1);
// }

// Top Down Tabulation
string shortestCommonSupersequence(string str1, string str2) 
{
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp (n+1, vector<int> (m+1));

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0 ; j <= m ; j++)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else
            {
                if(str1[i-1] == str2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {                    
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }

    int i = n;
    int j = m;
    string result = "";

    while(i > 0 && j > 0)
    {
        if(str1[i-1] == str2[j-1])
        {
            result.insert(result.begin(),str1[i-1]);
            i--;j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) 
        {
            result.insert(result.begin(),str1[i-1]);
            i--;
        }
        else
        {
            result.insert(result.begin(),str2[j-1]);
            j--;
        }
    }

    while(i > 0)
    {
        result.insert(result.begin(),str1[i-1]);
        i--;
    }

    while(j > 0)
    {
        result.insert(result.begin(),str2[j-1]);
        j--;
    }

    

    return result;
}


int main()
{
    string s = "jimish";
    string temp = "imi";
    return 0;
}