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

// Brute Force Approach O(N^2)
// int lengthOfLongestSubstring(string s) 
// {
//     int maxLength = 0;
//     int length = 0;
//     unordered_map<char,int> uMap;

//     for(int i = 0 ; i < s.length(); i++)
//     {        
//         if(uMap[s[i]] >= 1)
//         {
//             i = i - (length);
//             length = 0;
//             uMap.clear();
//         }
//         else
//         {
//             uMap[s[i]]++;
//             length++;
//             maxLength = max(length,maxLength);
//         }
//     }
//     return maxLength;
// }


// Two Pointer (Better Approach)
// int lengthOfLongestSubstring(string s) 
// {
//     int maxLength = 0;
//     unordered_set<char> uSet;
//     int n = s.length();

//     int l = 0;

//     for(int r = 0; r < n; r++)
//     {
//         if(uSet.find(s[r]) != uSet.end())
//         {
//             while((l < r) && uSet.find(s[r]) != uSet.end())
//             {
//                 uSet.erase(s[l]);
//                 l++;
//             }
//         }

//         uSet.insert(s[r]);
//         maxLength = max(maxLength,r-l+1);
//     }

//     return maxLength;
// }

// Optimized Approach O(N) 
int lengthOfLongestSubstring(string s) 
{
    int maxLength = 0;
    vector<int> pos(256,-1);
    int n = s.length();

    int left = 0;
    int right = 0;

    while(right < n)
    {
        if(pos[s[right]] != -1)
        {
            left = max(pos[s[right]]+1,left);
        }

        pos[s[right]] = right;

        maxLength = max(maxLength,right - left +1);
        right++;
    }    

    return maxLength;
}

int main()
{

    string s = "pwwkew";
    cout<<lengthOfLongestSubstring(s)<<endl;
    return 0;
}