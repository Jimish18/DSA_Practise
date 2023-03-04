/*
Question - Count Subarrays With Fixed Bounds

Link - https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
*/

#include <bits/stdc++.h>
using namespace std;

long long countSubarrays(vector<int>& nums, int minK, int maxK) 
{
    long long n=nums.size(),mni=-1,mxi=-1,li=-1,ans=0;

    for(int i=0;i<n;++i)
    {
        if(nums[i]<minK || nums[i]>maxK) li=i,mni=-1,mxi=-1;
        else
        {
            if(nums[i]==minK) mni=i;
            if(nums[i]==maxK) mxi=i;
            if(mni!=-1 && mxi!=-1) ans+=min(mni,mxi)-li;
        }
    }
    return ans;
}

int main()
{
    return 0;
}