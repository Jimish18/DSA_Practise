/*
Question - Integer Replacement

Link - https://leetcode.com/problems/integer-replacement/
*/

#include <bits/stdc++.h>
using namespace std;



int solve(long long n , long long even , long long odd1 , long long odd2)
{
    if(n <= 1) return 0;

    if(n%2 == 0)
    {
        even = 1 + solve(n/2,even,odd1,odd2);
    }
    else
    {
        odd1 = 1 + solve(n+1,even,odd1,odd2);
        odd2 = 1 + solve(n-1,even,odd1,odd2);
    }

    long long odd = min(odd1,odd2);
    return even+odd;
}

int integerReplacement(int n) 
{
    long long even = 0;
    long long odd1 = 0;
    long long odd2 = 0;

    return solve(n,even,odd1,odd2);
}

int main()
{
    return 0;
}