/*
Question - Print Longest Common Subsequence
*/

#include <bits/stdc++.h>
using namespace std;

// Memoization
// string print(string s1,string s2,int i,int j,vector<vector<string>> &dp)
// {
//     if(i == 0 || j == 0) return "";

//     if(dp[i][j] != "") return dp[i][j];

//     if(s1[i-1] == s2[j-1])
//     {
//         return dp[i][j] +=  print(s1,s2,i-1,j-1,dp) + s1[i-1];
//     }
//     else
//     {
//         string temp1 = print(s1,s2,i,j-1,dp);
//         string temp2 = print(s1,s2,i-1,j,dp);
//         return dp[i][j] += temp1.length() > temp2.length() ? temp1 : temp2;        
//     }

//     return dp[i][j];
// }

// string printLCS(string s1,string s2)
// {
//     int n = s1.length();
//     int m = s2.length();
//     vector<vector<string>> dp(n+1,vector<string> (m+1,""));

//     return print(s1,s2,n,m,dp);
// }

// Tabulation (Approach 1)
// string printLCS(string s1,string s2)
// {
//     int n = s1.length();
//     int m = s2.length();
//     vector<vector<string>> dp(n+1,vector<string> (m+1));

//     for(int i = 0; i <= n ; i++)
//     {
//         for(int j = 0 ; j <= m ; j++)
//         {
//             if(i == 0 || j == 0) dp[i][j] = "";
//             else if(s1[i-1] == s2[j-1])
//             {
//                 dp[i][j] = dp[i-1][j-1] + s1[i-1];
//             }
//             else
//             {
//                 string temp1 = dp[i][j-1];
//                 string temp2 = dp[i-1][j];

//                 dp[i][j] = temp1.length() > temp2.length() ? temp1 : temp2;
//             }
//         }
//     }

//     return dp[n][m];
// }

// Tabulation (Approach 2)
string printLCS(string s1,string s2)
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n+1,vector<int> (m+1));
    string result = "";

    for(int i = 0; i <= n ; i++)
    {
        for(int j = 0 ; j <= m ; j++)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1] ;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    int i = n,j = m;

    while(i != 0 && j != 0)
    {
        if(dp[i][j])
        {
            if(s1[i-1] == s2[j-1])
            {
                result.insert(result.begin(),s1[i-1]);
                i--;j--;
            }
            else
            {
                if(dp[i][j-1] > dp[i-1][j]) j--;
                else i--;
                
            }

        }
    }

    return result;
}

int main()
{
    string s1 = "acbcf";
    string s2 = "abcdaf";
    string result = printLCS(s1,s2);

    cout<<result<<endl;
    return 0;
}