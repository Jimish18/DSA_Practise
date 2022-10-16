/*
Question - Rotate Array

Link - https://leetcode.com/problems/rotate-array/
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach (TLE)
// void rotate(vector<int>& nums, int k) 
// {
//     long long n = nums.size();
//     int count = k%n;

//     if(count <= n/2)
//     {
//         for(int i = 0; i < count; i++)
//         {
//             nums.insert(nums.begin(),nums[n-1]);
//             nums.pop_back();
//         }  
//     }
//     else
//     {
//         for(int i = 0; i < (n-count); i++)
//         {
//             nums.insert(nums.end(),nums[0]);
//             nums.erase(nums.begin());
//         }
//     }
         
// }

void rotate(vector<int>& nums, int k) 
{
    int n = nums.size();
    k = k%n;

    // reverse first n-k numbers
    reverse(nums.begin(),nums.begin()+n-k);

    // reverse last k numbers
    reverse(nums.begin()+n-k,nums.end());

    // now reverse all the numbers
    reverse(nums.begin(),nums.end());
         
}

int main()
{
    vector<int> v = {-1,-100,3,99};

    for(int i = 0 ; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    rotate(v,2);
    for(int i = 0 ; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}