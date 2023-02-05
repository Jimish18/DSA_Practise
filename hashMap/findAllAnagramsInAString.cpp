/*
Question - Find All Anagrams in a String

Link - https://leetcode.com/problems/find-all-anagrams-in-a-string/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p) 
{
    int n = s.length();
    int m = p.length();
    map<char,int> umap1;

    for(int i = 0 ; i < m; i++)
    {
        umap1[p[i]]++;    
    }        
    vector<int> result;

    int i = 0, j = 0;
    map<char,int> temp;

    while(j < n)
    {
        if(umap1.find(s[j]) != umap1.end())
        {
            temp[s[j]]++;            
            
        } 

        if(j-i+1 == m)
        {
            if(umap1 == temp) result.push_back(i);
            if(temp.find(s[i]) != temp.end()) temp[s[i]]--;
            i++;
        }
        j++;

    }
        

    return result;
}

int main()
{
    unordered_map<char,int> umap1;
    umap1['a'] = 2;
    umap1['b'] = 3;


    unordered_map<char,int> umap2;
    umap2['a'] = 2;
    umap2['b'] = 3;

    cout<<(umap1 == umap2)<<endl;

    return 0;
}