/*
Question - Minimum Cost To Cut a Stick

Link - https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
*/

#include <bits/stdc++.h>
using namespace std;

int mincost(int start, int end, vector<int>& cuts, int cuts_start, int cuts_end,vector<vector<int>> &dp)
    {
        if(cuts_start>cuts_end) return 0;
        
        if(dp[cuts_start][cuts_end]!=-1) return dp[cuts_start][cuts_end];
        
        int minimum = INT_MAX;

        for(int i=cuts_start; i<=cuts_end; i++)
        {
            minimum = min(minimum, (end-start)+mincost(start, cuts[i], cuts, cuts_start, i-1,dp)+mincost(cuts[i], end, cuts, i+1, cuts_end,dp));
        }            
        
        return dp[cuts_start][cuts_end] = minimum;
    }
int minCost(int n, vector<int>& cuts) 
{
    sort(cuts.begin(),cuts.end());
    vector<vector<int>> dp(cuts.size()+1 , vector<int> (cuts.size()+1,-1));
    
    return mincost(0,n,cuts,0,cuts.size()-1,dp);       
}

int main()
{
    return 0;
}