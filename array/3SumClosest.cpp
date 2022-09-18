/*
Question - 3Sum Closest

Link - https://leetcode.com/problems/3sum-closest/
*/

#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) 
{
    int n = nums.size();
    int j,k;
    int closest = INT_MAX;
    int ClosestSum;
    sort(nums.begin(),nums.end());

    for(int i = 0 ; i < n-2; i++)
    {
        k = i+1;
        j = n-1;
        while(k < j)
        {
            if(nums[i]+nums[k]+nums[j] == target)
            {
                return target;
            }            
            else if(abs(nums[i]+nums[k]+nums[j] - target) < closest)
            {
                closest = abs(nums[i]+nums[k]+nums[j] - target);
                ClosestSum = nums[i]+nums[k]+nums[j];
            } 

            if(nums[i]+nums[k]+nums[j] > target)
            {
                j--;
            }
            else
            {
                k++;
            }
            
            
        }
    }    

    return ClosestSum;    
}

int main()
{
    vector<int> v = {-1,2,1,-4};
    // {0,0,0}
    // {-1,2,1,-4}
    cout<<threeSumClosest(v,1)<<endl;
    return 0;
}