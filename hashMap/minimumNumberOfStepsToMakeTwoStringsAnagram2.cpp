/*
Question - Minimum Number Of Steps To Make Two Strings Anagram II

Link - https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/
*/

#include <bits/stdc++.h>
using namespace std;

int minSteps(string s, string t) 
{
    unordered_map<char,int> temp1;
    unordered_map<char,int> temp2;

    for(auto x : s) temp1[x]++;

    for(auto x : t) temp2[x]++;

    int count = 0;

    for(auto x : temp1)
    {
        if(temp2.find(x.first) != temp2.end()) 
        {
            count += abs(temp2[x.first] - x.second);
            x.second = 0;
            temp2[x.first] = 0;
        }
        else
        {
            count += x.second;
            x.second = 0;
        }
    }

    for(auto x : temp2)
    {
        count += x.second;
    }

    return count;
}

int main()
{
    return 0;
}