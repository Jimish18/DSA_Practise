/*
Question - Reverse Integer

Link - https://leetcode.com/problems/reverse-integer/
*/

#include <bits/stdc++.h>
using namespace std;

int reverse(int x) 
{
    int temp = x;
    long long result = 0;
    int i = 0;

    while(temp != 0)
    {
        temp /= 10;
        i++;
    }

    while(x != 0)
    {
        result += (x%10)*pow(10,--i);        
        x /= 10;
    }

    if(result < INT_MIN || result > INT_MAX)
    {
        result = 0;
    }

    return (x<0) ? (0-result):result;
}

int main()
{
    cout<<reverse(120)<<endl;
    
    return 0;
}