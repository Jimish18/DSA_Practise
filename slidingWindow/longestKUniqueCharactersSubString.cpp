/*
Question - Longest K Unique Characters SubString

Link - https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
*/

#include <bits/stdc++.h>
using namespace std;

int longestKSubstr(string s, int k) 
{
    int n = s.length();
    unordered_map<char,int> umap;
    int result = 0 ;
    int i = 0;
    int j = 0;

    while(j < n)
    {
        umap[s[j]]++;

        if(umap.size() < k) j++;
        if(umap.size() == k)
        {
            result = max(result,j-i+1);
            j++;
        }
        else if(umap.size() > k)
        {
            while(umap.size() > k)
            {
                umap[s[i]]--;

                if(umap[s[i]] == 0) umap.erase(s[i]);

                i++;                
            }

            if(umap.size() == k) result = max(result,j-i+1);

            j++;
        }
    }

    return (result == 0) ? -1 : result;
}

int main()
{
    return 0;
}