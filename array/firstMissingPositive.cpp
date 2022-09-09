/*
Question - First Missing Positive

Link - https://leetcode.com/problems/first-missing-positive/
*/

#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int>& nums) 
{
    set<int> st;
    for(int i = 0 ; i < nums.size(); i++)
    {
        st.insert(nums[i]);
    }

    for(int i = 1; i <= nums.size()+1; i++ )
    {
        if(st.find(i) == st.end())
        {
            return i;
        }
    }

    return 1;
}

int main()
{
    return 0;
}