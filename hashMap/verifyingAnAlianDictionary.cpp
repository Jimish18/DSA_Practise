/*
Question - Verifying an Alien Dictionary

Link - https://leetcode.com/problems/verifying-an-alien-dictionary/
*/

#include <bits/stdc++.h>
using namespace std;

bool isAlienSorted(vector<string>& words, string order) 
{
    unordered_map<char,char> umap;
    
    for(int i = 0; i < order.size(); i++)
    {
        umap[order[i]] = (char)(i+97);
    }    

    for(int i = 0; i < words.size(); i++)
    {
        for(int j = 0; j < words[i].length(); j++)
        {
            words[i][j] = umap[words[i][j]];
        }
    }

    vector<string> temp = words;

    sort(words.begin(),words.end());

    return (temp == words);
}

int main()
{
    return 0;
}