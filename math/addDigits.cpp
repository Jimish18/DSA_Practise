/*
Question - Add Digits

Link - https://leetcode.com/problems/add-digits/description/
*/

#include <bits/stdc++.h>
using namespace std;

// O(n^2)
// int addDigits(int num) 
// {
//     int sum=0;
//     while(num>9)
//     {
//         while(num)
//         {
//             sum+=(num%10);
//             num/=10;
//         }
//         num=sum;
//         sum=0;
//     }
//     return num;
// }

// O(1)
int addDigits(int num) 
{
    if(num == 0) return 0;
    else if(num%9 == 0) return 9;
    
    return num%9;
}

int main()
{
    return 0;
}