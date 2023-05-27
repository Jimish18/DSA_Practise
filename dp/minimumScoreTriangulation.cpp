/*
Question - Minimum Score Triangulation 

Link - https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/
*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& values, int i, int j, vector<vector<int>> &dp)
{
    if(abs(j-i) == 1) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mn = INT_MAX;

    for(int k = i+1 ; k <= j-1; k++)
    {
        int tempAns = values[i]*values[k]*values[j] + solve(values,i,k,dp) + solve(values,k,j,dp);

        mn = min(tempAns,mn);
    }

    return dp[i][j] = mn;
}

int minScoreTriangulation(vector<int>& values) 
{
    int n = values.size();
    vector<vector<int>> dp(n+1 , vector<int> (n+1,-1)); 

    return solve(values,0,n-1,dp);       
}

int main()
{
    return 0;
}