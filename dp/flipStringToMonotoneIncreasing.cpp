/*
Question - Flip String To Monotone Incresig

Link - https://leetcode.com/problems/flip-string-to-monotone-increasing/
*/

#include <bits/stdc++.h>
using namespace std;

int minFlipsMonoIncr(string s) 
{
    int flipCount = 0;
    int oneCount = 0;

    for(char x : s)
    {
        if(x == '1')
        {
            oneCount++;
        }
        else 
        {
            flipCount++;
            flipCount = min(flipCount,oneCount);
        }
    }        

    return flipCount;
}

int main()
{
    return 0;
}