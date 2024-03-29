/*
Question - reverse words in a string III

Link - https://leetcode.com/problems/reverse-words-in-a-string-iii/
*/

#include <bits/stdc++.h>
using namespace std;

string reverseWords(string& s) 
{
    int i = 0;

    for (int j = 0; j < s.size(); ++j) 
    {
        if (s[j] == ' ') 
        {
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
    }
    
    reverse(s.begin() + i, s.end());
    return s;
}

int main()
{
    string s = "God Ding";
    // "Let's take LeetCode contest"
    cout<<reverseWords(s)<<endl;
    return 0;
}