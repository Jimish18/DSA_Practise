/*
Question - Jump Game II

Link - https://leetcode.com/problems/jump-game-ii/
*/

#include <bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) 
{
    int n = nums.size();
    int jumps = 0;
    int curReach = 0;
    int curMax = 0;

    for(int i = 0; i < n-1; i++)
    {
        if(i + nums[i] > curMax)
        {
            curMax = i+nums[i];
        }

        if(i == curReach)
        {
            jumps++;
            curReach = curMax;
        }
    }

    return jumps;
}

int main()
{
    return 0;
}