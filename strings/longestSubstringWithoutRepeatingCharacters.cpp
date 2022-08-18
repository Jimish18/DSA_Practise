/*
Question - Longest Substring without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) 
{
    int maxLength = 0;
    int length = 0;
    unordered_map<char,int> uMap;

    // for(int i = 0 ; i < s.length(); i++)
    // {
    //     for(int j = i ; j < s.length(); j++)
    //     {
    //         if(uMap[s[j]] >= 1)
    //         {
    //             length = 0;
    //             uMap.clear();
    //             break;
    //             // uMap[s[i]]++;
    //             // length++;
    //             // maxLength = max(length,maxLength);
    //         }
    //         else
    //         {
    //             uMap[s[j]]++;
    //             length++;
    //             maxLength = max(length,maxLength);
    //         }
    //     }
    // }

    for(int i = 0 ; i < s.length(); i++)
    {        
        if(uMap[s[i]] >= 1)
        {
            i = i - (length);
            length = 0;
            uMap.clear();
            // break;
            // uMap[s[i]]++;
            // length++;
            // maxLength = max(length,maxLength);
        }
        else
        {
            uMap[s[i]]++;
            length++;
            maxLength = max(length,maxLength);
        }
    }

    return maxLength;

}

int main()
{

    string s = "pwwkew";
    cout<<lengthOfLongestSubstring(s)<<endl;
    return 0;
}