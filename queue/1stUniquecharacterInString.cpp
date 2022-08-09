/*
Question -  First Unique Character in a String

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1
 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.
*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s) 
{
    unordered_map<char,int> uSet;
    for(int i = 0 ; i < s.size() ; i++)
    {
        uSet[s[i]]++;
    }

    for(int i = 0 ; i < s.size(); i++)
    {
        if(uSet[s[i]] == 1)
        {
            return i;
        }
    }

    return -1;
    
}

int main()
{
    string s = "loveleetcode";
    cout<<firstUniqChar(s)<<endl;
    return 0;
}