/*
Question - Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

 

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]
 

Constraints:
1 <= strs.length <= 10^4
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
    vector<string> strs2 = strs;
    vector<vector<string>> res;
    map<string,pair<int,vector<int>>> omap;

    for(int i = 0 ; i < strs.size(); i++)
    {
        sort(strs2[i].begin(),strs2[i].end());
    } 

    for(int i = 0 ; i < strs.size(); i++)
    {
        omap[strs2[i]].first++;
        omap[strs2[i]].second.push_back(i);
    }

    for(auto i : omap)
    {
        vector<string> s1;
        int count = 0;
        for(int j = 0 ; j < i.second.first; j++)
        {
            s1.push_back(strs[i.second.second[count]]);
            count++;
        }

        res.push_back(s1);
    }

    return res;
}

int main()
{
    vector<string> v = {"a"};
    
    for(int i = 0 ; i < groupAnagrams(v).size(); i++)
    {
        for(int j = 0 ; j < groupAnagrams(v)[i].size(); j++)
        {
            cout<<groupAnagrams(v)[i][j]<<endl;
        }
    }

    return 0;
}

