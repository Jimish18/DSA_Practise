/*
Question - Orderly Queue

Link - https://leetcode.com/problems/orderly-queue/
*/

#include <bits/stdc++.h>
using namespace std;

string orderlyQueue(string s, int k) 
{
    if(k > 1)
    {
        sort(s.begin(),s.end());
        return s;
    }        

    set<string> st;

    while(true)
    {
        s += s[0];
        s.erase(s.begin());
        if(st.find(s) != st.end())
        {
            break;
        }
        else
        {
            st.insert(s);
        }
    }

    for(auto x : st)
    {
        return x;
    }

    return "";
}

int main()
{
    // string s = "jimish";
    // s.erase(s.begin());
    // cout<<s<<endl;

    cout<<orderlyQueue("baaca",3)<<endl;

    return 0;
}

