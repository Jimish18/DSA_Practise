/*
Question - Solving Questions With Brainpower

Link - https://leetcode.com/problems/solving-questions-with-brainpower/
*/

#include <bits/stdc++.h>
using namespace std;

long long dfs(vector<vector<int>>& questions,vector<long long> &dp,int index)
{
    if(index >= questions.size()) return 0;

    if(dp[index] != -1) return dp[index];

    long long notTake = dfs(questions,dp,index+1);

    long long take = questions[index][0] + dfs(questions,dp,index+1+questions[index][1]);

    return dp[index] = max(notTake,take);
}

long long mostPoints(vector<vector<int>>& questions) 
{
    vector<long long> dp(questions.size()+1,-1);
    return dfs(questions,dp,0);
}

int main()
{
    return 0;
}