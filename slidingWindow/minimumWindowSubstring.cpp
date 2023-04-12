/*
Question - Minimum Window Substring


Link - https://leetcode.com/problems/minimum-window-substring/
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(unordered_map<char,int> &umap , unordered_map<char,int> &umap2 )
{
    bool check = true;

    for(auto x : umap)
    {
        if(umap2[x.first] < x.second) return false;
    }

    return check;
}

string minWindow(string s, string t) 
{
    int n = s.length();
    int m = t.length();

    if(n < m) return "";

    unordered_map<char,int> umap;

    for(auto x : t)
    {
        umap[x]++;
    }        

    unordered_map<char,int> umap2;
    pair<int,pair<int,int>> temp = {INT_MAX,{0,0}};
    int i = 0;
    bool check = true;

    for(int j = 0; j < n ; j++)
    {
        umap2[s[j]]++;  

        while(isValid(umap,umap2))
        {
            if(j-i+1 < temp.first)
            {
                temp.first = j-i+1;
                temp.second.first = i;
                temp.second.second = j;
            }

            umap2[s[i]]--;
            i++;
        }
    }

    return (temp.first == INT_MAX) ? "" : s.substr(temp.second.first,temp.first);
}


int main()
{
    return 0;
}