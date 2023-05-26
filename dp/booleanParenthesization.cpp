/*
Question - Boolean Perenthesization

Link - https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
*/

#include <bits/stdc++.h>
using namespace std;

int mod = 1003;
int solve(string s,int i,int j,unordered_map<string,int> &dp,bool isTrue)
{
    if(i > j) return 0;

    if(i == j)
    {
        if(isTrue) return s[i] == 'T';
        else return s[i] == 'F';
    }

    string temp  = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));

    if(dp.find(temp) != dp.end()) return dp[temp]%mod;

    int ways = 0;

    for(int k = i+1; k <= j-1; k=k+2)
    {
        int lt = solve(s,i,k-1,dp,true)%mod;
        int lf = solve(s,i,k-1,dp,false)%mod;
        int rt = solve(s,k+1,j,dp,true)%mod;
        int rf = solve(s,k+1,j,dp,false)%mod;

        if(s[k] == '&')
        {
            if(isTrue) ways += (lt*rt)%mod;
            else ways += ((lf*rt) + (lt*rf) + (lf*rf))%mod;
        }
        else if(s[k] == '|')
        {
            if(isTrue) ways += ((lt*rf)%mod + (lf*rt)%mod + (lt*rt)%mod)%mod;
            else ways += (lf*rf)%mod;
        }
        else
        {
            if(isTrue) ways += ((lt*rf)%mod + (lf*rt)%mod)%mod;
            else ways += ((lf*rf)%mod + (lt*rt)%mod)%mod;
        }
    }

    return dp[temp] = ways%mod;
}

int countWays(int N, string S)
{
    int n = S.length();
    unordered_map<string,int> dp;

    return solve(S,0,n-1,dp,true)%mod;
}

int main()
{
    return 0;
}