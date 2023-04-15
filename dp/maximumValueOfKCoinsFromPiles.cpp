/*
Question - Maximum Value Of K Coins From Piles

Link- https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/
*/

#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& piles, vector<vector<int>> &dp,int k,int i)
{
    if(i >= piles.size()) return 0;

    if(dp[i][k] != -1) return dp[i][k];

    int maxi = 0;

    maxi = max(maxi,dfs(piles,dp,k,i+1));

    for(int j = 0 ; j < piles[i].size(); j++)
    {
        if(j+1 <= k)  maxi = max(maxi , piles[i][j] + dfs(piles,dp,k-(j+1),i+1));
        else break;
    }

    return dp[i][k] = maxi;
}

int maxValueOfCoins(vector<vector<int>>& piles, int k) 
{
    int n = piles.size();
    vector<vector<int>> dp(n+1,vector<int> (k+1,-1));

    for(int i = 0; i < piles.size(); i++)
    {
        for(int j = 1; j < piles[i].size(); j++)
        {
            piles[i][j] += piles[i][j-1];
        }
    }

    return dfs(piles,dp,k,0);        
}
int main()
{
    return 0;
}