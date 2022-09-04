/*
Question - Partition Labels

link - https://leetcode.com/problems/partition-labels/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string s) 
{
    unordered_map<char,pair<int,int>> umap;
    vector<int> result;
    int count = 0;

    for(int i = 0 ; i < s.length(); i++)
    {
        if(umap.find(s[i]) == umap.end())
        {
            umap[s[i]].first = i;
            umap[s[i]].second = i;
        }
        else
        {
            umap[s[i]].second = i;
        }
    }    

    int l = 0;
    int r = umap[s[0]].second;
    int i = 0;

    while(i < s.length())
    {
        i++;
        if(l == r)
        {
            result.push_back(i-count);
            count = i;
            l++;
            r = umap[s[l]].second;
        }
        else
        {
            int tr = umap[s[l]].second;
            r = max(r,tr);
            l++;
        }
    }

    return result;


}

int main()
{
    string s = "eccbbbbdec";
    for(int i = 0 ; i < partitionLabels(s).size(); i++)
    {
        cout<<partitionLabels(s)[i]<<" ";
    }
    return 0;
}