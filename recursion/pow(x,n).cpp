/*
Question - pow(x,n)

Link - https://leetcode.com/problems/powx-n/
*/

#include <bits/stdc++.h>
using namespace std;


double myPow(double x, int n) 
{
    if(n == 0)
    {
        return 1;
    }
    
    if(n < 0)
    {
        return 1/x*pow(1/x,-(n+1));
    }
    
    return (n%2 == 0) ? pow(x*x,n/2) : x*pow(x*x,n/2);
}

int main()
{
    return 0;
}