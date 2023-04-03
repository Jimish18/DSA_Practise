/*
Question - Minimum Cost Tree From Leaf Values

Link - https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , map<pair<int,int>,int> &umap, vector<vector<int>> &dp , int left , int right)
{
    if(left == right) return 0;

    if(dp[left][right] != -1) return dp[left][right];

    int ans = INT_MAX;

    for(int i = left ; i < right ; i++)
    {
        ans = min(ans , umap[{left,i}]*umap[{i+1,right}] + solve(arr,umap,dp,left,i) + solve(arr,umap,dp,i+1,right));
    }

    return dp[left][right] = ans;
}

int mctFromLeafValues(vector<int>& arr) 
{
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int> (n,-1));
    map<pair<int,int>,int> umap;

    for(int i = 0 ; i < n ; i++)
    {
        umap[{i,i}] = arr[i];
        for(int j = i+1; j < n ; j++)
        {
            umap[{i,j}] = max(arr[j],umap[{i,j-1}]);
        }
    }        

    return solve(arr,umap,dp,0,n-1);
}
int main()
{
    return 0;
}