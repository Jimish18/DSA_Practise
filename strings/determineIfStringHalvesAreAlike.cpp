/*
Question - Determine if String Halves Are Alike

Link - https://leetcode.com/problems/determine-if-string-halves-are-alike/
*/

#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
    
    return false;
}


bool halvesAreAlike(string s) 
{
    int n = s.length();
    int count = 0;
    
    for(int i = 0 ; i < n/2; i++)
    {
        if(isVowel(s[i]))
        {
            count++;
        }
    }
    
    for(int i = n/2 ; i < n; i++)
    {
        if(isVowel(s[i]))
        {
            count--;       
            
        }
        
        if(count < 0) return false;
    }
    
    return (count == 0) ? true : false;
}

int main()
{
    return 0;
}