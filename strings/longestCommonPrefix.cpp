/*
Question - Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) 
{
    int minSize = INT_MAX;
    char tempResult;
    string result = "";

    for(int i = 0; i < strs.size(); i++)
    {
        if(strs[i].length() < minSize)
        {
            minSize = strs[i].length();
        }
    }

    if(minSize == 0)
    {
        return "";
    } 

    for(int i = 0; i < minSize; i++)
    {
        tempResult = strs[0][i];
        for(int j = 0 ; j < strs.size(); j++)
        {
            if(strs[j][i] != tempResult)
            {
                return result;
            }
        }

        result += tempResult;

    }

    return result;

}


int main()
{
    vector<string> strs = {"dog","racecar","car"};
    cout<<longestCommonPrefix(strs)<<endl;
    return 0;
}