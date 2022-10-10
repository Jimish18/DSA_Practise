/*
Question - minimum size subarray sum

Link - https://leetcode.com/problems/minimum-size-subarray-sum/
*/

#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) 
{
    int i = 0; 
    int j = 0 ; 
    int l = INT_MAX;
    int sum = 0;

    while(i < nums.size())
    {
        sum += nums[i];

        while(sum >= target)
        {
            l = min(l,i-j+1);
            sum -= nums[j];            
            j++;                        
        }

        i++;
    }         

    return (l == INT_MAX) ? 0 : l;
}

int main()
{
    vector<int> s = {1,4,4};
    // 2,3,1,2,4,3 - 7
    // 1,4,4 - 4
    // {1,1,1,1,1,1,1,1} - 11
    int target = 4;

    cout<<minSubArrayLen(target,s)<<endl;
    return 0;
}