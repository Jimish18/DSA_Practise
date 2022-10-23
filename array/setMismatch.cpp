/*
Question - Set MisMatch

Link - https://leetcode.com/problems/set-mismatch/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) 
{        
    vector<int> result;

    for(int x : nums)
    {
        if(nums[abs(x) - 1] > 0) result.push_back(abs(x));
        else nums[abs(x)-1] *= -1;
    }

    for(int i = 0 ; i < nums.size(); i++)
    {
        if(nums[i] > 0)
        {
            result.push_back(i+1);
        }
    }

    return result;
}

int main()
{
    return 0;
}