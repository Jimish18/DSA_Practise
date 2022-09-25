/*
Question - Minimum Remove to make valid parentheses

link - https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
*/

#include <bits/stdc++.h>
using namespace std;

string minRemoveToMakeValid(string s) 
{
    stack<char> st;
    vector<int> opening;
    vector<int> closing;

    for(int i = 0 ; i < s.length(); i++)
    {
        if(s[i] == '(')
        {
            st.push(s[i]);
            opening.push_back(i);
        }
        else if(!st.empty() && s[i] == ')' && st.top() == '(')
        {
            st.pop();
            opening.pop_back();
        }
        else if(s[i] == ')')
        {
            st.push(s[i]);
            closing.push_back(i);
        }
    }          

    for(int i = 0 ; i < opening.size(); i++)
    {
        s[opening[i]] = '.';
    }

    for(int i = 0 ; i < closing.size(); i++)
    {
        s[closing[i]] = '.';
    } 

    s.erase(remove(s.begin(),s.end(),'.'),s.end());



    return s;
}

int main()
{
    string s = "))((";
    // "a)b(c)d"
    // "lee(t(c)o)de)"
    string validString = minRemoveToMakeValid(s);
    cout<<validString<<endl;

    return 0;
}