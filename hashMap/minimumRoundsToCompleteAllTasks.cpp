/*
Question - Minimum Rounds To Complete All Tasks

Link - https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/
*/

#include <bits/stdc++.h>
using namespace std;

int minimumRounds(vector<int>& tasks) 
{
    unordered_map<long long,int> umap;
    int n = tasks.size();
    int minRounds = 0;

    for(int i = 0 ; i < n ; i++)
    {
        umap[tasks[i]]++;
    }        

    for(auto x : umap)
    {
        int count = x.second;

        if(count == 1) return -1;

        if(count%3 == 0) minRounds += count/3;
        else minRounds += count/3 +1;
    }

    return minRounds;
}

int main()
{
    return 0;
}