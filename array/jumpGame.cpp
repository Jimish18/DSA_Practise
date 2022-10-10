/*
Question - jump Game

Link - https://leetcode.com/problems/jump-game/
*/

#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) 
{
    int n = nums.size();
    int mov = 0;
    
    for(int i = 0; i <= mov ; i++)
    {
        mov = max(mov,i + nums[i]);

        if(mov >= n-1)
        {
            return true;
        }
    }

    return false;    
}

int main()
{
    vector<int> nums = {3,2,1,0,4};
    cout<<canJump(nums)<<endl;
    return 0;
}