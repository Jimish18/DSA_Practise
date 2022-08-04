/*
Question -  Minimum Number of Swaps to Make the String Balanced

You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.

A string is called balanced if and only if:

It is the empty string, or
It can be written as AB, where both A and B are balanced strings, or
It can be written as [C], where C is a balanced string.
You may swap the brackets at any two indices any number of times.

Return the minimum number of swaps to make s balanced.

 

Example 1:

Input: s = "][]["
Output: 1
Explanation: You can make the string balanced by swapping index 0 with index 3.
The resulting string is "[[]]".
Example 2:

Input: s = "]]][[["
Output: 2
Explanation: You can do the following to make the string balanced:
- Swap index 0 with index 4. s = "[]][][".
- Swap index 1 with index 5. s = "[[][]]".
The resulting string is "[[][]]".
Example 3:

Input: s = "[]"
Output: 0
Explanation: The string is already balanced.
*/

#include <bits/stdc++.h>
using namespace std;

int minSwaps(string s) 
{
    stack<char> st;

    st.push(s[0]);

    for(int i = 1; i < s.length(); i++)
    {
        if(!st.empty() && st.top() == '[' && s[i] == ']')
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }

    if(st.size() == 2)
    {
        return 1;
    }    
    else if(st.empty())
    {
        return 0;
    }
    else
    {
        if(st.size()%4 == 0)
        {
            return st.size()/4;
        }
        else
        {
            return st.size()/4 + 1;
        }
    }

}

int main()
{
    string s = "]]]]][[[[";
    cout<<minSwaps(s)<<endl;
    return 0;
}