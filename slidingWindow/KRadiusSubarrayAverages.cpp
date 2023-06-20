/*
Question - K Radius Subarray Averages

Link - https://leetcode.com/problems/k-radius-subarray-averages/
*/



#include <bits/stdc++.h>
using namespace std;

vector<int> getAverages(vector<int>& nums, int k) 
{
    int n = nums.size();
    int preSum = 0;
    int i = 0; 
    int j = 0;
    vector<int> ans(n,-1);

    while(j < n)
    {
        preSum += nums[j];
        
        if(j-i+1 < 2*k)
        {
            j++;
        }
        else if(j-i+1 == 2*k)
        {
            ans[j-k] = preSum/(2*k + 1);
            preSum -= nums[i];
            i++;
            j++;
        }
    }

    return ans;
}

int main()
{
    return 0;
}