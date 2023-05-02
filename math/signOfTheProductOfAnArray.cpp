/*
Question - Sign Of the Prosuct Of An Array

Link - https://leetcode.com/problems/sign-of-the-product-of-an-array/description/
*/

#include <bits/stdc++.h>
using namespace std;

int arraySign(vector<int>& nums) 
{
    int negCount = 0;
    bool zero = false;

    for(auto x : nums)
    {
        if(x == 0) zero = true;
        if(x < 0) negCount++;
    }    

    if(zero) return 0;
    if(negCount%2 == 0) return 1;

    return -1;
}

int main()
{
    return 0;
}