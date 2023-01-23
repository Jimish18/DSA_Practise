/*
Question - Find The Town Judge

Link - https://leetcode.com/problems/find-the-town-judge/
*/

#include <bits/stdc++.h>
using namespace std;

// int findJudge(int n, vector<vector<int>>& trust) 
// {
//     vector<int> mp(n+1);
//     unordered_map<int,vector<int>> umap;
//     int judge = -1;

//     for(auto x : trust)
//     {
//         mp[x[0]]++;
//         umap[x[1]].push_back(x[0]);
//     }

//     for(int i = 1; i < n+1; i++)
//     {
//         if(mp[i] == 0) judge = i;
//         mp[i] = 0;
//     }

//     for(auto x : umap[judge])
//     {
//         mp[x]++;
//     }

//     for(int i = 0; i < n+1; i++)
//     {
//         if(mp[i] == 0) judge = -1;
//     }

//     return judge;
// }

int findJudge(int n, vector<vector<int>>& trust) 
{

    if(trust.size() == 0 && n == 1) return 1;
    vector<int> count(n+1);

    for(auto x : trust)
    {
        count[x[0]]--;
        count[x[1]]++;
    }

    for(int i = 0; i < n+1; i++)
    {
        if(count[i] == n-1) return i;
    }   
    

    return -1;
}

int main()
{
    return 0;
}