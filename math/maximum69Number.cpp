/*
Question - maximum 68 Number

Link - https://leetcode.com/problems/maximum-69-number/
*/

#include <bits/stdc++.h>
using namespace std;

int maximum69Number (int num) 
{
    string number = to_string(num);
    int n = number.length();

    for(int i = 0; i < n ; i++)
    {
        if(number[i] == '6')
        {
            number[i] = '9';
            break;
        }
    }        

    return stoi(number);
}

int main()
{

}