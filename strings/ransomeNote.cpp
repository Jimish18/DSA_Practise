/*
Question - Ransome Note

Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters 
from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
*/

#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine) 
{
    bool flag = false;

    unordered_map<char,int> uMap;

    for(int i = 0 ; i < magazine.length(); i++)
    {
        uMap[magazine[i]]++;
    }

    for(int i = 0 ; i < ransomNote.length(); i++)
    {
        if(uMap[ransomNote[i]] > 0)
        {
            flag = true;
            uMap[ransomNote[i]]--;
        }
        else
        {
            flag = false;
            break;
        }
    }

    return flag;
}

int main()
{
    string ransomNote = "baa";
    string magazine = "aab";
    cout<<canConstruct(ransomNote,magazine)<<endl;
    return 0;
}