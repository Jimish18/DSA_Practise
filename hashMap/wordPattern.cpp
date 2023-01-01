/*
Question - Word Pattern

Link - https://leetcode.com/problems/word-pattern/
*/


#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s) 
{
    unordered_map<char,string> umap;
    unordered_map<string,char> umap2;
    string temp = "";
    int n = s.length();
    int m = pattern.length();
    vector<string> ss;

    for(int i = 0;i < n; i++)
    {
        if(s[i] == ' ' || i == n-1)
        {
            if(i == n-1) temp += s[i];
            ss.push_back(temp);
            temp.clear();
            continue;
        }
        temp+=s[i];
    }    

    if(ss.size() != m) return false;

    for(int i = 0 ; i < m; i++)
    {
        if(umap.find(pattern[i]) != umap.end())
        {
            if(umap[pattern[i]] != ss[i]) return false;
            if(umap2[ss[i]] != pattern[i]) return false;
        }
        else
        {
            umap[pattern[i]] = ss[i];
            umap2[ss[i]] = pattern[i];
        }
    }  

    return true;
}

int main()
{
    return 0;
}