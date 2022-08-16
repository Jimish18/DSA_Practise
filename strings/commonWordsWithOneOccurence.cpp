/*
Question - Count Common Words With One Occurrence

Given two string arrays words1 and words2, return the number of strings that appear exactly once in each of the two 
arrays.

 

Example 1:

Input: words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
Output: 2
Explanation:
- "leetcode" appears exactly once in each of the two arrays. We count this string.
- "amazing" appears exactly once in each of the two arrays. We count this string.
- "is" appears in each of the two arrays, but there are 2 occurrences of it in words1. We do not count this string.
- "as" appears once in words1, but does not appear in words2. We do not count this string.
Thus, there are 2 strings that appear exactly once in each of the two arrays.
Example 2:

Input: words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
Output: 0
Explanation: There are no strings that appear in each of the two arrays.
Example 3:

Input: words1 = ["a","ab"], words2 = ["a","a","a","ab"]
Output: 1
Explanation: The only string that appears exactly once in each of the two arrays is "ab".
 

Constraints:

1 <= words1.length, words2.length <= 1000
1 <= words1[i].length, words2[j].length <= 30
words1[i] and words2[j] consists only of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

int countWords(vector<string>& words1, vector<string>& words2) 
{
    unordered_map<string,int> uMap1;
    unordered_map<string,int> uMap2;
    int count = 0;

    for(auto i : words1)
    {
        uMap1[i]++;
    }

    for(auto i : words2)
    {
        uMap2[i]++;
    }

    if(uMap1.size() < uMap2.size())
    {
        for(auto i : uMap1)
        {
            if(i.second == 1 && uMap2[i.first] == 1)
            {
                count++;
            }
        }
    }
    else
    {
        for(auto i : uMap2)
        {
            if(i.second == 1 && uMap1[i.first] == 1)
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    vector<string> v1 = {"a","ab"};
    vector<string> v2 = {"a","a","a","ab"};
    cout<<countWords(v1,v2)<<endl;
    return 0;
}