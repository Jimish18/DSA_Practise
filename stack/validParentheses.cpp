/*
Question - Valid Parentheses

Link - https://leetcode.com/problems/valid-parentheses/description/
*/

#include <bits/stdc++.h>
using namespace std;

bool validate(char open,char end)
{
    if((open == '(' && end == ')') || (open == '{' && end == '}') || (open == '[' && end == ']')) return true;

    return false;
}

bool isValid(string s) 
{
    int n = s.length();
    stack<char> st;

    for(int i = 0; i < n;i++)
    {
        if(s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if(!st.empty() && validate(st.top(),s[i])) st.pop();
            else return false;
        }
        else st.push(s[i]);
    }   

    return st.empty();
}

int main()
{
    return 0;
}