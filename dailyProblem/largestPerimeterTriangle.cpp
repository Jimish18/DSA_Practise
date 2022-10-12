/*
Question - Largest Perimeter Triangle

Link - https://leetcode.com/problems/largest-perimeter-triangle/
*/

#include <bits/stdc++.h>
using namespace std;

int largestPerimeter(vector<int>& nums) 
{
    // Brute Force Approach
    // sort(nums.begin(),nums.end());

    // int n = nums.size();
    // int i = n-3;

    // while(i >= 0)
    // {
    //     int a = nums[i+2];
    //     int b = nums[i+1];
    //     int c = nums[i];   

    //     double s = (a+b+c)/(double)(2);
    //     if(c >= s)
    //     {
    //         i--;
    //         continue;
    //     }

    //     double area = sqrt(s*(s-a)*(s-b)*(s-c)); 

    //     if(area > 0) return a+b+c;
    //     i--;
    // }

    // Conceptual Approach
    // a < b + c it will form a proper non-zero triangle

    sort(nums.begin(),nums.end());
    for(int i = nums.size()-1 ; i >= 2; i++)
    {
        if(nums[i] < nums[i-1] + nums[i-2])
        {
            return nums[i] + nums[i-1] + nums[i-2];
        }
    } 

    return 0;    
}

int main()
{
    vector<int> nums = {1,2,1};
    // {2,1,2}
    cout<<largestPerimeter(nums)<<endl;

    return 0;
}