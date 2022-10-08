/*
Question - Find the Index of the First Occurrence in a String

Link - https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
*/

#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle) 
{
    int index = -1;
    int n = needle.length();
    int m = haystack.length();

    for(int i = 0 ; i < haystack.length(); i++)
    {
        if((m-i) < n)
        {
            break;
        }

        string temp = haystack.substr(i,n);
        if(temp == needle)
        {
            return i;
        }
    }


    return index;        
}

int main()
{
    string  s = "leetcode";
    string n = "leeto";

    cout<<strStr(s,n)<<endl;
    return 0;
}