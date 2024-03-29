/*
Question - Lexicographically Smallest Equivalent String

Link - https://leetcode.com/problems/lexicographically-smallest-equivalent-string/
*/

#include <bits/stdc++.h>
using namespace std;

string smallestEquivalentString(string s1, string s2, string baseStr) 
{
    vector<char> ch(26);

    for(int i = 0;i < 26;i++)
    {
        ch[i] = 'a' + i;
    }    

    for(int i = 0; i < s1.size(); i++)
    {
        char toReplace = max(ch[s1[i]-'a'],ch[s2[i]-'a']);
        char replaceWith = min(ch[s1[i]-'a'],ch[s2[i]-'a']);

        for(int i = 0; i < 26; i++)
        {
            if(ch[i] == toReplace) ch[i] = replaceWith;
        }        
    }   

    for(int i = 0; i < baseStr.size(); i++)
    {
        baseStr[i] = ch[baseStr[i] - 'a'];
    }

    return baseStr;
}

int main()
{
    return 0;
}