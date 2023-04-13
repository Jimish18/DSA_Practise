/*
Question - Maximum Sum Of Two Non-Overlapping Subarrays

Link - https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
*/

#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> nums,int firstLen, int secondLen)
{
    int n = nums.size();
    vector<int> dp1(n);
    vector<int> dp2(n);
    int tempSum = 0;
    

    for(int j = 0; j < n; j++)
    {
        if(j < firstLen)
        {
            tempSum += nums[j];
            dp1[j] = tempSum;
        }
        else
        {
            tempSum += nums[j] - nums[j-firstLen];
            dp1[j] = max(tempSum,dp1[j-1]);
        }
    }        

    for(auto x : dp1) cout<<x<<" ";
    cout<<endl;

    tempSum = 0;

    for(int j = n-1; j >= 0 ; j--)
    {
        if(j+secondLen >= n)
        {
            tempSum += nums[j];
            dp2[j] = tempSum;
        }
        else
        {
            tempSum += nums[j] - nums[j+secondLen];
            dp2[j] = max(tempSum,dp2[j+1]);
        }    
        
    }

    for(auto x : dp2) cout<<x<<" ";
    cout<<endl;

    int ans = 0;
    for(int j = firstLen-1 ; j < n-secondLen; j++)
    {
        ans = max(dp1[j]+dp2[j+1] , ans);
    }


    return ans;
}


int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) 
{
    
    return max(subarraySum(nums,firstLen,secondLen),subarraySum(nums,secondLen,firstLen));
}


int main()
{
    vector<int> temp = {3,8,1,3,2,1,8,9,0};

    maxSumTwoNoOverlap(temp,2,3);
    return 0;
}