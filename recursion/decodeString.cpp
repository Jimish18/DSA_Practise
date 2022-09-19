/*
Question - Decode String

Link - https://leetcode.com/problems/decode-string/
*/

#include <bits/stdc++.h>
using namespace std;

string decodeString(string &s,int &index)
{
    string res;

    while(index < s.length() && s[index] != ']')
    {
        if(!isdigit(s[index]))
        {
            res += s[index++];
        }
        else
        {
            int n = 0;

            while(index < s.length() && isdigit(s[index]))
            {
                n = n*10 + s[index++]-'0';
            }

            index++; // '['
            string t = decodeString(s,index);
            index++; // ']'

            while(n-- > 0)
            {
                res += t;
            }
        }
    }

    return res;
}



string decodeString(string s) 
{
    int i = 0;
    return decodeString(s,i);
}

int main()
{
    string s = "3[a]2[bc]";
    // "3[a]2[bc]"
    // "3[a2[c]]"
    cout<<decodeString(s)<<endl;
    return 0;
}