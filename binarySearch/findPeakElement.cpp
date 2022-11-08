/*
Question - Find Peak Element

Link - https://leetcode.com/problems/find-peak-element/
*/

#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) 
{
    int n = nums.size();
    int start = 0;
    int end = n-1;
    int mid = start + (end - start)/2;
        
    while(start <= end)
    {
        mid = start + (end - start)/2;
        if(mid == 0 && nums[mid] >= nums[(mid+1)%n])
        {
            return mid;
        }
        else if(mid == 0 && nums[mid] < nums[(mid+1)%n])
        {
            start = mid+1;
            continue;
        }
        
        if(mid == n-1 && nums[mid] >= nums[(mid+n-1)%n])
        {
            return mid;
        }
        else if(mid == n-1 && nums[mid] < nums[(mid+n-1)%n])
        {
            end = mid-1;
            continue;
        }
        if((nums[mid] > nums[mid-1]) && (nums[mid] > nums[mid+1]))
        {
            return mid;
        }
        else if(nums[mid] < nums[mid+1])
        {
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }

        
    }

    return -1;

}


int main()
{
    return 0;
}