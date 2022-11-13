/*
Question - Reverse Words in a String 

Link - https://leetcode.com/problems/reverse-words-in-a-string/
*/

#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) 
{
    string temp  = "";
    stack<string> st;
    int n = s.length();

    for(int i = 0; i < n; i++)
    {
        if(s[i] == ' ' && temp.length() > 0)
        {
            st.push(temp);
            temp.clear();
        }

        if(s[i] != ' ')
        {
            temp += s[i];
        }
    }

    if(temp.length() > 0)
    {
        st.push(temp);
        temp.clear();
    }

    s.clear();

    while(!st.empty())
    {
        if(st.size() > 1)
        {
            s += st.top();
            s += ' ';
        }
        else
        {
            s += st.top();
        }

        st.pop();
    }

    return s;
}

int main()
{
    string s = "a good   example";
    // "  hello world  "
    // "the sky is blue"
    string temp = reverseWords(s);

    cout<<temp;

    cout<<"."<<endl;
    return 0;
}