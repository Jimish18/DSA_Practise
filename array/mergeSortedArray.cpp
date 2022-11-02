/*
Question - merge Sorted Array

Link - https://leetcode.com/problems/merge-sorted-array/
*/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    int i = m-1;
    int j = n-1;
    int k = m+n-1;

    while(i >= 0 && j >= 0)
    {
        if(nums1[i] >= nums2[j])
        {
            nums1[k] = nums1[i];
            k--;
            i--;
        }
        else
        {
            nums[k] = nums2[j];
            k--;
            j--;
        }
    }        
}

int main()
{
    return 0;
}