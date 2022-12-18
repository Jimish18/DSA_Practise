/*
Question - Product Of Array Except Self

Link - https://leetcode.com/problems/product-of-array-except-self/
*/

#include <bits/stdc++.h>
using namespace std;

// O(n) time and O(n) space
vector<int> productExceptSelf(vector<int>& nums) 
{
    int n = nums.size();
    vector<int> result;
    vector<int> preFix(n+1,1);
    vector<int> suFix(n+1,1);

    for(int i = 0 ; i < n ; i++)
    {
        preFix[i+1] = preFix[i]*nums[i];
        suFix[(n+1)-i-2] = suFix[(n+1)-i-1]*nums[n-i-1];
    }


    for(int i = 0; i < n; i++)
    {
        result.push_back(preFix[i]*suFix[i+1]);
    }

    return result;
}

// O(n) time and O(1) space
vector<int> productExceptSelf(vector<int>& nums) 
{
    int n = nums.size();
    vector<int> result(n,1);
    int fromBegin = 1;
    int fromLast = 1;

    for(int i = 0 ; i < n ; i++)
    {
        result[i] *= fromBegin;
        fromBegin *= nums[i];

        result[n-i-1] *= fromLast;
        fromLast *= nums[n-i-1];
    }

    return result;
}



int main()
{
    vector<int> nums = {-1,1,0,-3,3};
    productExceptSelf(nums);
    return 0;
}