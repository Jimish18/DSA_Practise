/*
Problem Statement :->
A string is a valid parentheses string (denoted VPS) if it meets one of the following:

It is an empty string "", or a single character not equal to "(" or ")",
It can be written as AB (A concatenated with B), where A and B are VPS's, or
It can be written as (A), where A is a VPS.
We can similarly define the nesting depth depth(S) of any VPS S as follows:

depth("") = 0
depth(C) = 0, where C is a string with a single character not equal to "(" or ")".
depth(A + B) = max(depth(A), depth(B)), where A and B are VPS's.
depth("(" + A + ")") = 1 + depth(A), where A is a VPS.
For example, "", "()()", and "()(()())" are VPS's (with nesting depths 0, 1, and 2), and ")(" and "(()" are not VPS's.

Given a VPS represented as string s, return the nesting depth of s.

Example1:
Input: s = "(1+(2*3)+((8)/4))+1"
Output: 3
Explanation: Digit 8 is inside of 3 nested parentheses in the string.

Example 2:
Input: s = "(1)+((2))+(((3)))"
Output: 3
*/

#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    
    int maxDepth(string s) 
    {
        // vector<int> v;
        stack<char> st;
        int count = 0;
        int maximum = INT_MIN;

        for(int i = 0 ; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                st.push(s[i]);
                count++;
            }
            else if( !st.empty() && s[i] == ')')
            {
                // v.push._back(count);
                if(count > maximum)
                {
                    maximum = count;
                }
                count--;
                st.pop();
            }
            else
            {
                continue;
            }
        }

        

        // for(int i = 0 ; i < v.size() ; i++)
        // {
        //     maximum = max(maximum,v[i]);
        // }
        // if(v.size() < 1)
        // {
        //     return count;
        // }
        if(maximum < 1)
        {
            return 0;
        }

        return maximum;
        
    }
};

int main()
{
    string s = "1";
    // (1) + ((2)) + (((3)))
    // (1 + (2*3) + ((8) / 4)) + 1s
    Solution sol;
    cout<<sol.maxDepth(s)<<endl;

    return 0;
}