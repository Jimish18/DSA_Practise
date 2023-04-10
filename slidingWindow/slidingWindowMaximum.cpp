/*
Question - Sliding window maximum

Link - https://leetcode.com/problems/sliding-window-maximum/description/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
    int n = nums.size();
    int i = 0;
    int j = 0; 
    deque<int> q;
    vector<int> result;

    while(j < n)
    {
        while(!q.empty() && nums[j] > q.back()) q.pop_back();

        q.push_back(nums[j]);

        if(j-i+1 < k) j++;
        else if(j+1-1 == k)
        {
            result.push_back(q.front());

            if(nums[i] == q.front()) q.pop_front();

            i++;
            j++;
        }         
    }

    return result;

}

int main()
{
    return 0;
}