/*
Question - reducing dishes

Link - https://leetcode.com/problems/reducing-dishes/
*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &satisfaction, int index,int count,vector<vector<int>> &dp)
{
    if(index >= satisfaction.size()) return 0;

    if(dp[index][count] != -1) return dp[index][count];

    int take = satisfaction[index]*(count) + solve(satisfaction,index+1,count+1,dp);

    int notTake = solve(satisfaction,index+1,count,dp);    

    return dp[index][count] = max(take,notTake);
}

int maxSatisfaction(vector<int>& satisfaction) 
{   
    int n = satisfaction.size();
    vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
    sort(satisfaction.begin(),satisfaction.end());
    return solve(satisfaction,0,1,dp);
}

int main()
{
    return 0;
}