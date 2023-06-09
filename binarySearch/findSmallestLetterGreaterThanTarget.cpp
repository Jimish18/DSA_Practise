/*
Question - Find Smallest Letter Greater Than Target

Link - https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/
*/

#include <bits/stdc++.h>
using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) 
{
    int s = 0;
    int e = letters.size()-1;
    int m;

    while(s <= e)
    {
        m = s + (e-s)/2;

        if(letters[m] > target) e = m-1;
        else s = m+1;
    }   

    if(s >= 0 && s < letters.size()) return letters[s];

    return letters[0];
}