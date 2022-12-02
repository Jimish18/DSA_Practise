/*
Question - Determine if Two Strings Are Close

Link - https://leetcode.com/problems/determine-if-two-strings-are-close/
*/

#include <bits/stdc++.h>
using namespace std;\

bool closeStrings(string word1, string word2) 
{
    int n = word1.size();
    int m = word2.size();

    if(n != m) return false;

    unordered_map<char,int> umap1;
    unordered_map<int,int> count1;
    unordered_map<char,int> umap2;
    unordered_map<int,int> count2;

    for(int i = 0 ; i < n ; i++)
    {
        umap1[word1[i]]++;
        umap2[word2[i]]++;
    }

    if(umap1.size() != umap2.size()) return false;

    for(auto x : umap1)
    {
        if(umap2.find(x.first) == umap2.end())
        {
            return false;
        }
        count1[x.second]++;
    }

    for(auto x : umap2)
    {
        count2[x.second]++;
    }

    if(count1.size() != count2.size()) return false;

    for(auto x : count1)
    {
        if(count2.find(x.first) != count2.end())
        {
            if(count2[x.first] != x.second)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
    return 0;
}