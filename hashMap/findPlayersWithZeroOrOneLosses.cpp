/*
Question - Find Players With Zero or One Losses

Link - https://leetcode.com/problems/find-players-with-zero-or-one-losses/
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findWinners(vector<vector<int>>& matches) 
{
    vector<int> win;
    vector<int> loss;
    vector<vector<int>> result;
    unordered_map<int,pair<int,int>> umap;
    int n = matches.size();

    for(int i = 0; i < n; i++)
    {
        umap[matches[i][0]].first++;
        umap[matches[i][1]].second++;
    }  

    for(auto x : umap)
    {
        if(x.second.second == 0)
        {
            win.push_back(x.first);
        }

        if(x.second.second == 1)
        {
            loss.push_back(x.first);
        }
    }   

    sort(win.begin(),win.end());
    sort(loss.begin(),loss.end());

    result.push_back(win);
    result.push_back(loss);

    return result;   
}

int main()
{
    vector<vector<int>> matches = {{2,3},{1,3},{5,4},{6,4}};
    // {1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}
    vector<vector<int>> res = findWinners(matches);

    for(int i = 0 ; i < res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}