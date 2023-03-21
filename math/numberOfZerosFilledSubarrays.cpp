/*
Question - Number Of Zeros Filled SubArrays 

Link - https://leetcode.com/problems/number-of-zero-filled-subarrays/
*/

#include <bits/stdc++.h>
using namespace std;

// total subarrays = n(n+1)/2; 
long long zeroFilledSubarray(vector<int>& nums) 
{
    long long result = 0;
    long long count = 0;
    
    for(auto x : nums)
    {
        if(x == 0) count++;
        else count = 0;

        result += count;
    }

    return result;
}               

int main()
{
    return 0;
}