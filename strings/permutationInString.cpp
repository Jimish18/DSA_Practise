/*
Question - Permutation In String

Link - https://leetcode.com/problems/permutation-in-string/
*/

#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) 
{
    int n = s1.length();
    int m = s2.length();

    if(m < n) return false;

    unordered_map<char,int> umap1;

    for(int i = 0; i < n; i++)
    {
        umap1[s1[i]]++;
    }        

    int count = umap1.size();    
    int i = 0;
    int j = 0;

    while(j < m)
    {
        if(umap1.find(s2[j]) != umap1.end())
        {
            umap1[s2[j]]--;
            if(umap1[s2[j]] == 0)  count--;
        }

        if(j-i+1 < n) j++;
        else if(j-i+1 == n)
        {
            if(count == 0) return true;

            if(umap1.find(s2[i]) != umap1.end())
            {
                umap1[s2[i]]++;
                if(umap1[s2[i]] == 1)
                {
                    count++;
                }
            }

            i++;
            j++;
        }

        
    }

    return false;
}

int main()
{
    return 0;
}