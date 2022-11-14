/*
Question - Sort Characters By Frequency

Link - https://leetcode.com/problems/sort-characters-by-frequency/
*/

#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s) 
{
    unordered_map<char,int> umap;
    priority_queue<pair<int,char>> maxH;
    int n = s.length();

    for(int i = 0 ; i < n; i++)
    {
        umap[s[i]]++;
    }

    for(auto x : umap)
    {
        maxH.push({x.second,x.first});
    }

    string result = "";
    while(!maxH.empty())
    {
        int count = maxH.top().first;

        while(count)
        {
            result += maxH.top().second;
            count--;
        }

        maxH.pop();
    }

    return result;

}


int main()
{
    string s = "tree";
    // Aabb
    // cccaaa
    cout<<frequencySort(s)<<endl;
    return 0;
}