/*
Question - Stone Game II

Link - https://leetcode.com/problems/stone-game-ii/
*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& piles , int m , int i,bool turn,int n,vector<vector<vector<int>>> &dp)
{
    
    if(i >= n) return 0;

    if(dp[turn][i][m] != -1) return dp[turn][i][m];

    int res = (turn) ? -1 : INT_MAX;

    int score = 0;
    for(int j = 1 ; j <= min(2*m , n-i); j++)
    {
        score += piles[j+i-1];

        if(turn) res = max(res , score + solve(piles,max(m,j),i+j,false,n,dp));
        else res = min(res,solve(piles,max(m,j),i+j,true,n,dp));
    }

    return dp[turn][i][m] = res;
}

int stoneGameII(vector<int>& piles) 
{
    int n = piles.size();
    vector<vector<vector<int>>> dp(2,vector<vector<int>> (n+1 , vector<int> (n+1 , -1)));
    return solve(piles,1,0,true,n,dp);
}

int main()
{
    return 0;
}