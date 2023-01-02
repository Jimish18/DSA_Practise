/*
Question - Detect Capital

Link - https://leetcode.com/problems/detect-capital/
*/

#include <bits/stdc++.h>
using namespace std;

bool detectCapitalUse(string word) 
{
    int n = word.length();
    bool flag;

    if((int)word[n-1] >= 65 && (int)word[n-1] <= 90)
    {
        flag = true;
    }   
    else if((int)word[n-1] >= 97 && (int)word[n-1] <= 122)
    {
        flag = false;
    }  

    for(int i = n-2 ; i >= 0; i--)
    {
        if(flag)
        {
            if((int)word[i] >= 97 && (int)word[i] <= 122) return false;
        }
        else
        {
            if(i == 0) continue;

            if((int)word[i] >= 65 && (int)word[i] <= 90) return false;
        }
    }  

    return true ;
}

int main()
{
    return 0;
}