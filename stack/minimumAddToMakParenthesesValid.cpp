/*
Question - Minimum Add To Make Parentheses Valid

Link - https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
*/

#include <bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s) 
{
    stack<char> st;
    int opening = 0;
    int closing = 0;

    for(int i = 0 ; i < s.length() ; i++)
    {
        if(s[i] == '(')
        {
            st.push(s[i]);
        }
        else if(!st.empty() && s[i] == ')' &&st.top() == '(')
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }     

    while(!st.empty())
    {
        if(st.top() == '(')
        {
            opening++;
        }
        else
        {
            closing++;
        }
        st.pop();
    }   

    return (opening+closing);
}

int main()
{
    string s = "())(";
    // "())"
    cout<<minAddToMakeValid(s)<<endl;
    return 0;
}