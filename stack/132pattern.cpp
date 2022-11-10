/*
Question - 132 Pattern

Link - https://leetcode.com/problems/132-pattern/
*/

#include <bits/stdc++.h>
using namespace std;

bool find132pattern(vector<int>& nums) 
{
    int s3 = INT_MIN;
    stack<int> st;   
    int n = nums.size();

    for(int i = n-1; i >= 0; i--)
    {
        if(nums[i] < s3)
        {
            return true;
        }
        else
        {
            while(!st.empty() && nums[i] > st.top())
            {
                s3 = st.top();
                st.pop();
            }
        }
        st.push(nums[i]);
    }  

    return false;   
}

int main()
{
    return 0;
}