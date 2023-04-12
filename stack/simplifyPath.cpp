/*
Question - Simplify Path

Link - https://leetcode.com/problems/simplify-path/
*/

#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string path) 
{
    int n = path.length();
    stack<string> st;
    string result = "";

    for(int i = 0; i < n ; i++)
    {
        if(path[i] == '/') continue;
        
        string temp = "";

        while(i < n && path[i] != '/')
        {
            temp += path[i];
            i++;
        }

        if(temp == ".") continue;
        else if(temp == "..")
        {
            if(!st.empty()) st.pop();
        }
        else st.push(temp);
    }

    while(!st.empty())
    {
        result = "/" + st.top() + result;
        st.pop();
    }

    if(result.length() == 0) return "/";

    return result;
}

int main()
{
    return 0;
}