/*
Question - Reverse Pairs

Link - https://leetcode.com/problems/reverse-pairs/
*/

#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &nums,int start,int mid,int end)
{
    int total = 0;
    int j = mid + 1;

    for(int i = start; i <= mid; i++)
    {
        while(j <= end && nums[i] > 2 * (long long)nums[j])
        {
            j++;
        }
        total += (j- (mid+1));
    }

    vector<int> t;
    int left = start, right = mid+1;

    while(left <= mid && right <= end)
    {
        if(nums[left] <= nums[right])
        {
            t.push_back(nums[left++]);
        }
        else
        {
            t.push_back(nums[right++]);
        }
    }

    while(left <= mid)
    {
        t.push_back(nums[left++]);
    }

    while(right <= end)
    {
        t.push_back(nums[right++]);
    }

    for(int i = start; i <= end; i++)
    {
        nums[i] = t[i-start];
    }

    return total;
}

int mergeSort(vector<int> &nums,int start,int end)
{
    if(start >= end) return 0;

    int mid = start + (end-start)/2;
    int inv = mergeSort(nums,start,mid);
    inv += mergeSort(nums,mid+1,end);
    inv += merge(nums,start,mid,end);

    return inv;
}

int reversePairs(vector<int>& nums) 
{
    return mergeSort(nums,0,nums.size()-1);    
}

int main()
{
    return 0;
}