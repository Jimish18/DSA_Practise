/*
Question - Optimal Partition of String

Link - https://leetcode.com/problems/optimal-partition-of-string/
*/

#include <bits/stdc++.h>
using namespace std;

int partitionString(string s) 
{
    unordered_set<char> st;
    int count = 0;

    for(int i = 0 ; i < s.length(); i++)
    {
        if(st.find(s[i]) == st.end())
        {
            st.insert(s[i]);
        }
        else
        {
            count++;
            st.clear();
            st.insert(s[i]);
        }
    }  

    return ++count;     
}

int main()
{
    string s = "ssssss";
    // ssssss
    // abacaba
    cout<<partitionString(s)<<endl;
    return 0;
}
