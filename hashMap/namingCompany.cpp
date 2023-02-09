/*
Question - Naming a Company

Link - https://leetcode.com/problems/naming-a-company/
*/

#include <bits/stdc++.h>
using namespace std;

long long distinctNames(vector<string>& ideas) 
{
    long long result = 0;
    int n = ideas.size();
    unordered_map<char,vector<string>> umap;
    unordered_set<string> st;

    for(int i = 0 ; i < n ;i++)        
    {
        st.insert(ideas[i]);
        umap[ideas[i][0]].push_back(ideas[i].substr(1));
    }

    for(auto x : umap)
    {
        for(auto y : umap)
        {
            if(x.first == y.first) continue;

            long long cnt1 = 0;
            long long cnt2 = 0;

            for(auto j : y.second)
            {
                string temp = x.first + j;

                if(st.find(temp) == st.end()) cnt1++;
            }

            for(auto j : x.second)
            {
                string temp = y.first + j;

                if(st.find(temp) == st.end()) cnt2++;
            }

            result += cnt1*cnt2; 
        }
    }

    return result;
}

int main()
{
    vector<string> temp = {"coffee","donuts","time","toffee"};
    distinctNames(temp);
    return 0;
}