/*
Question - Maximum Score From Removing Stones

Link - https://leetcode.com/problems/maximum-score-from-removing-stones/
*/

#include <bits/stdc++.h>
using namespace std;

int maximumScore(int a, int b, int c) 
{
    int m = max(a,max(b,c));
    
    if(2*m > (a+b+c)) return ((a+b+c)-m);

    return (a+b+c)/2;
}

int main()
{
    return 0;
}