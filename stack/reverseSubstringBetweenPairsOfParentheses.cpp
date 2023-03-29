/*
Question - Reverse Substrings Between Each Pair of Parentheses

Link - https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
*/

#include <bits/stdc++.h>
using namespace std;

string reverseParentheses(string s) 
{
    stack<string> st;
    
    for(int i = 0 ; i < s.length(); i++)
    {
        if(s[i] == ')')
        {
            string temp = "";
            while(st.top() != "(")
            {
                temp.insert(0,st.top());
                st.pop();
            }
            st.pop();
            reverse(temp.begin(),temp.end());
            st.push(temp);
        }
        else
        {
            string temp = "";
            st.push(temp+s[i]);
        }

    }

    string ans = "";

    while(!st.empty())
    {
        ans.insert(0,st.top());
        st.pop();
    }

    return ans;

}

int main()
{
    return 0;
}