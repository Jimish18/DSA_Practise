/*
Question - Increasing Triplet Subsequence 

Link - https://leetcode.com/problems/increasing-triplet-subsequence/
*/

#include <bits/stdc++.h>
using namespace std;

// triplet From Front
bool increasingTriplet(vector<int>& nums) 
{
    int first = INT_MAX;
    int second = INT_MAX;
    int third = INT_MAX;

    for(int i = 0 ; i < nums.size(); i++)
    {
        int curr  = nums[i];
        if(curr < first)
        {
            first = curr;
        }
        else if(curr < second && curr > first)
        {
            second = curr;
        }
        else if(curr > second)
        {
            third = curr;
            return true;
        }
    }        

    return false;
}

// triplet from end
bool increasingTriplet(vector<int>& nums) 
{
    int first = INT_MIN;
    int second = INT_MIN;
    int third = INT_MIN;

    for(int i = 0 ; i < nums.size(); i++)
    {
        int curr  = nums[i];
        if(curr > first)
        {
            first = curr;
        }
        else if(curr > second && curr < first)
        {
            second = curr;
        }
        else if(curr < second)
        {
            third = curr;
            return true;
        }
    }        

    return false;
}

int main()
{
    vector<int> v = {2,1,5,0,4,6};
    cout<<increasingTriplet(v)<<endl;
    return 0;
}