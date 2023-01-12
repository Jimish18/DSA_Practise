/*
Question - Combination Sum III

Link - https://leetcode.com/problems/combination-sum-iii/
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int k,int n , vector<vector<int>> &result, vector<int> &ds , int start)
{    
    if(k == 0 && n == 0)
    {
        result.push_back(ds);
        return;
    }

    for(int i = start; i < 10; i++)
    {
        ds.push_back(i);
        dfs(k-1,n-i,result,ds,i+1);
        ds.pop_back();
    }

}

vector<vector<int>> combinationSum3(int k, int n) 
{
    vector<vector<int>> result;
    vector<int> ds;    

    dfs(k,n,result,ds,1);

    return result;        
}

int main()
{
    return 0;
}