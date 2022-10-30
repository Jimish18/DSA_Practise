/*
Question - Sort Colors

Link - https://leetcode.com/problems/sort-colors/
*/

#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) 
{
    int zeros = 0;
    int ones = 0;
    int twos = 0;

    for(int i = 0 ; i < nums.size(); i++)
    {
        if(nums[i] == 0) zeros++;
        else if(nums[i] == 1) ones++;
        else twos++;        
    }        

    nums.clear();

    int n = zeros + ones + twos;

    for(int i = 0 ; i < n; i++)
    {
        if(zeros > 0)
        {
            nums.push_back(0);
            zeros--;
        } 
        else if(ones > 0)
        {
            nums.push_back(1);
            ones--;
        } 
        else
        {
            nums.push_back(2);
            twos--;
        } 
    }
}

int main()
{
    vector<int> v = {2,0,1};
    for(int i = 0 ; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }

    sortColors(v);
    cout<<endl;

    for(int i = 0 ; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}