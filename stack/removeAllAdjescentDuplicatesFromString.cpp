/*
Question - Remove All Adjescent Duplicates From String

You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

 

Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
Example 2:

Input: s = "azxxzy"
Output: "ay"

*/

#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string s) 
{
    stack<char> st;

    for(int i = 0 ; i < s.length(); i++)
    {
        if(!st.empty())
        {
            if(st.top() == s[i])
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        else
        {
            st.push(s[i]);
        }
    }

    string reverseString = "";

    while(!st.empty())
    {
        reverseString += st.top();
        st.pop();
    }

    string result  = "";
    for(int i = reverseString.length()-1 ; i >= 0 ; i--)
    {
        result += reverseString[i];
    }

    return result;

}

int main()
{
    string s = "azxxzy";
    cout<<removeDuplicates(s); 

    return 0;
}