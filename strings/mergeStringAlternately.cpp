/*
Question - Merge Strings Alternately

Link - https://leetcode.com/problems/merge-strings-alternately/description/
*/

#include <bits/stdc++.h>
using namespace std;

string mergeAlternately(string word1, string word2) 
{
    int n = word1.length();
    int m = word2.length();  
    int i = 0;
    int j = 0;
    bool alter = true;

    string result = "";

    while(i < n && j < m)
    {
        if(alter)
        {
            result.push_back(word1[i]);
            i++;
        }
        else
        {
            result.push_back(word2[j]);
            j++;
        }

        alter = !alter;
    } 

    while(i < n)
    {
        result.push_back(word1[i]);
        i++;  
    } 

    while(j < m)
    {
        result.push_back(word2[j]);
        j++;  
    } 

    return result;
}

int main()
{
    return 0;
}