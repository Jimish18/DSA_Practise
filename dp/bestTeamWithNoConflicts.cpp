/*
Question - Best Team With No Conflicts

Link - https://leetcode.com/problems/best-team-with-no-conflicts/
*/

#include <bits/stdc++.h>
using namespace std;

int dfs(vector<pair<int,int>> &temp,int prev,int curr,vector<vector<int>> &dp)
{
    if(curr >= temp.size()) return 0;
    if(dp[curr][prev+1] != -1) return dp[curr][prev+1];

    if(prev == -1 || temp[prev].second <= temp[curr].second)
    {
        return dp[curr][prev+1] = max(temp[curr].second + dfs(temp,curr,curr+1,dp),dfs(temp,prev,curr+1,dp));
    }
    else
    {
        return dp[curr][prev+1] = dfs(temp,prev,curr+1,dp);
    }

    return dp[curr][prev+1];
}

int bestTeamScore(vector<int>& scores, vector<int>& ages) 
{
    vector<pair<int,int>> temp;
    int n = scores.size();

    for(int i = 0 ; i < n; i++)
    {
        temp.push_back({ages[i],scores[i]});
    }       

    sort(temp.begin(),temp.end());

    vector<vector<int>> dp(n+1,vector<int> (n+2,-1));

    return dfs(temp,-1,0,dp);
}

int main()
{
    return 0;
}