/*
Question - Jump Game

Link - https://leetcode.com/problems/jump-game/
*/

#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) 
{
    int n = nums.size();
    int moves = 0;
    int curMax = 0; 

    for(int i = 0 ; i < n ; i++)
    {
        if(i <= curMax)
        {
            curMax = max(i + nums[i],curMax);
        }   

        if(curMax >= n-1) return true;
    }

    return false;
}

// Method - 1 (Brute Force)
// bool canJump(vector<int>& nums) 
// {
//     int n = nums.size();
//     int mov = 0;

//     for(int i = 0; i <= mov ; i++)
//     {
//         mov = max(mov,i + nums[i]);

//         if(mov >= n-1)
//         {
//             return true;
//         }
//     }

//     return false;    
// }

bool dfs(int index , vector<int> &nums,int curMax)
{
    if(curMax >= nums.size()-1) return true;

    if(index <= curMax)
    {
        curMax = max(index+nums[index],curMax);
        return dfs(index+1,nums,curMax);
    }

    return false;
}

bool canJump(vector<int>& nums) 
{
    int n = nums.size();
    
    return dfs(0,nums,0);
}


int main()
{
    return 0;
}