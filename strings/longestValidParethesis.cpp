/*
Question - Longest Valid Parantheses

Given a string containing just the characters '(' and ')', 
find the length of the longest valid (well-formed) parentheses substring.
 

Example 1:
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:
Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.

*/

#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s) 
{
    if(s.length() == 0 || s.length() == 1)
    {
        return 0;
    }

    stack<char> st;

    int maxLength = 0;
    int tempLength = 0;
    st.push(s[0]);
    tempLength++;

    for(int i = 1 ; i < s.length(); i++)
    {
        if(tempLength >= 2 && s[i] == '(' && s[i+1] == ')' && i < s.length()-1)
        {
            st.push(s[i]);
            tempLength++;
            continue;
        }

        if(st.top() == '(' && s[i] == ')')
        {
            tempLength++;
            st.push(s[i]);
        }
        else
        {
            tempLength=0;
            tempLength++;
            st.push(s[i]);
        }

        if(tempLength >= 2)
        {
            maxLength = max(tempLength,maxLength);
        }
    }    

    

    return maxLength;


}

int main()
{
    string s = "()(()";
    cout<<longestValidParentheses(s)<<endl;
    return 0;
}