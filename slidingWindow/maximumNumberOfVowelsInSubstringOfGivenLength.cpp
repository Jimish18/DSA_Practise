/*
Question - Maximum Number of Vowels in a Substring of Given Length

Link - https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
*/

#include <bits/stdc++.h>
using namespace std;

bool isVowels(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;

    return false;
}

int maxVowels(string s, int k) 
{
    int n = s.length();
    int i = 0;
    int result = INT_MIN;  
    int tempCount = 0;   

    for(int j = 0; j < n; j++)
    {
        if(isVowels(s[j])) tempCount++;

        if(j-i+1 == k)
        {
            result = max(result,tempCount);

            if(isVowels(s[i])) tempCount--;
            i++;
        }
    }

    return result;
}

int main()
{
    return 0;
}

