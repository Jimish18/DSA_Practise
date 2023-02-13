/*
Question - Count Odd Numbers in an Interval Range

Link - https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/
*/

#include <bits/stdc++.h>
using namespace std;

int countOdds(int low, int high) 
{
    if((low%2 != 0) || (high%2 != 0))
    {
        return ((high-low)/2)+1;
    }

    return (high-low)/2;
}

int main()
{
    return 0;
}