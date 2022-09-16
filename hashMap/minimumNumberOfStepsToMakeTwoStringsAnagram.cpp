/*
Question - Minimum Number of Steps to Make Two Strings Anagram

Link - https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
*/

#include <bits/stdc++.h>
using namespace std;

int minSteps(string s, string t) 
{
    unordered_map<char,int> umap1;
    int n = s.size();
    int steps = 0;
    
    for(int i = 0 ; i < n ; i++)
    {
        umap1[s[i]]++;
    } 

    for(int i = 0 ; i < n ; i++)
    {
        umap1[t[i]]--;
    }        

    for(auto x : umap1)
    {
        if(x.second < 0)
        {
            steps += x.second;
        }
    }

    return abs(steps);
}

int main()
{
    string s = "gctcxyuluxjuxnsvmomavutrrfb";
    string t = "qijrjrhqqjxjtprybrzpyfyqtzf";

    // "bab" "aba"
    // "leetcode" "practice"
    // "anagram" "mangaar"
    // "gctcxyuluxjuxnsvmomavutrrfb" "qijrjrhqqjxjtprybrzpyfyqtzf"
    cout<<minSteps(s,t)<<endl;
    return 0;
}