/*
Question - Removing Stars From a String

Link - https://leetcode.com/problems/removing-stars-from-a-string/
*/

#include <bits/stdc++.h>
using namespace std;

string removeStars(string s) 
{
    stack<char> st;

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '*')
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }

    string ans = "";

    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(),ans.end());

    return ans;
}

int main()
{
    return 0;
}