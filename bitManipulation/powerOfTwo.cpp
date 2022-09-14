/*
Question - Power Of Two

Link - https://leetcode.com/problems/power-of-two/
*/

#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) 
{
    return ((n > 0) && !(n & n-1));    
}

int main()
{
    return 0;
}