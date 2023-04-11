/*
Question - Longest Substring Without Repeating Characteres 

Link - https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) 
{
    int n = s.length();
    int i = 0;
    unordered_set<char> st;
    int length = 0;

    for(int j = 0; j < n; j++)
    {
        if(st.find(s[j]) != st.end())
        {
            while(st.find(s[j]) != st.end())
            {
                st.erase(s[i]);
                i++;
            }

            length = max(length,j-i+1);
        }
        else 
        {
            st.insert(s[j]);

            length = max(length,j-i+1);
        }
    }

    return length;
}

int main()
{
    return 0;
}