/*
Question - Unique Number of Occurrences

Link - https://leetcode.com/problems/unique-number-of-occurrences/
*/

#include <bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) 
{
    unordered_map<int,int> umap;
    unordered_set<int> st;
    int n = arr.size();

    for(int i = 0 ; i < n; i++)
    {
        umap[arr[i]]++;
    }

    for(auto x : umap)
    {
        if(st.find(x.second) != st.end())
        {
            return false;
        }
        st.insert(x.second);
    }

    return true;        
}

int main()
{
    return 0;
}