/*
Question - Number of Strings That Appear as Substrings in Word

Given an array of strings patterns and a string word, return the number of strings in patterns that 
exist as a substring in word.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: patterns = ["a","abc","bc","d"], word = "abc"
Output: 3
Explanation:
- "a" appears as a substring in "abc".
- "abc" appears as a substring in "abc".
- "bc" appears as a substring in "abc".
- "d" does not appear as a substring in "abc".
3 of the strings in patterns appear as a substring in word.
Example 2:

Input: patterns = ["a","b","c"], word = "aaaaabbbbb"
Output: 2
Explanation:
- "a" appears as a substring in "aaaaabbbbb".
- "b" appears as a substring in "aaaaabbbbb".
- "c" does not appear as a substring in "aaaaabbbbb".
2 of the strings in patterns appear as a substring in word.
Example 3:

Input: patterns = ["a","a","a"], word = "ab"
Output: 3
Explanation: Each of the patterns appears as a substring in word "ab".
 

Constraints:

1 <= patterns.length <= 100
1 <= patterns[i].length <= 100
1 <= word.length <= 100
patterns[i] and word consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

/*----------------> Slow Code [Time Complexity - O(n^2)] <-------------------------*/
// int numOfStrings(vector<string>& patterns, string word)  
// {
//     int count = 0;

//     for(int i = 0 ; i < patterns.size(); i++)
//     {
//         for(int j = 0 ; j < word.length(); j++)
//         {
//             if(((word.length()-j) >= patterns[i].length()) && (patterns[i] == word.substr(j,patterns[i].length())))
//             {
//                 count++;
//                 break;
//             }
//         }
//     }

//     return count;
// }

/*----------------> Fast Code [Time Complexity - O(n)] <-------------------------*/
int numOfStrings(vector<string>& patterns, string word) 
{

    int ans = 0;
    for(auto i : patterns){
        if(word.find(i) != string::npos){ // string::npos ---> end of the string.
            ans++;
        }
    }

    return ans;
}

int main()
{
    // string s1 = "JIMISH";
    // string s2 = "JIMISL";

    // cout<<(s1==s2)<<endl;

    vector<string> patterns = {"a","a","a"};
    string word = "ab";
    cout<<numOfStrings(patterns,word)<<endl;

    return 0;
}