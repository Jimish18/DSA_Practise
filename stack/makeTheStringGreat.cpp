/*
Question - make The String Great

Link - https://leetcode.com/problems/make-the-string-great/

*/

#include <bits/stdc++.h>
using namespace std;

string makeGood(string s) 
{
    stack<char> st;
    st.push(s[0]);
    int i = 1;

    while(i < s.length())
    {
        if(!st.empty() && ((int)st.top() == ((int)s[i]+32) || (int)st.top() == ((int)s[i]-32)))
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
        i++;
    }      

    s.clear();

    while(!st.empty())
    {
        s.insert(s.begin(),st.top());
        st.pop();
    }    

    return s; 
}

int main()
{
    string s = "abBAcC";
    // leEeetcode
    cout<<makeGood(s)<<endl;

    return 0;
}