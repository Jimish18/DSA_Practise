/*
Question - Number of Ways to Form a Target String Given a Dictionary

Link - https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/
*/

#include<bits/stdc++.h>
using namespace std;

int MOD = 1e9+7;

int dfs(vector<string>& words, string target, vector<vector<int>> &dp,int wordIndex , int targetIndex,vector<vector<int>> &freq)
{
    if(targetIndex == target.size()) return 1;

    if(wordIndex == freq[0].size()) return 0;

    if(dp[wordIndex][targetIndex] != -1) return dp[wordIndex][targetIndex];

    
    int targetCharacter = target[targetIndex]-'a';
    int notPick = dfs(words,target,dp,wordIndex+1,targetIndex,freq);

    int pick = 0 ;
    
    if(freq[targetCharacter][wordIndex] != 0)
    {
        int currWays = freq[targetCharacter][wordIndex]%MOD;
        int nextWays = dfs(words,target,dp,wordIndex+1,targetIndex+1,freq)%MOD;

        pick = (currWays%MOD * nextWays%MOD)%MOD;
    }

    return dp[wordIndex][targetIndex] = (pick%MOD + notPick%MOD) %MOD;
}

int numWays(vector<string>& words, string target) 
{
    int n = words[0].size();
    int m = words.size();
    vector<vector<int>> dp(n,vector<int>(target.length(),-1));
    vector<vector<int>> freq(26, vector<int> (n,0));

    for(int i = 0; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            freq[words[i][j] - 'a'][j]++;  
        }
    }

    int ans = dfs(words,target,dp,0,0,freq);
    return ans;
}

int main()
{
    return 0;
}