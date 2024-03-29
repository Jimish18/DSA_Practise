/*
Question - Permutations

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/

#include <bits/stdc++.h>
using namespace std;

void permutations(vector<int> nums,int idx,vector<vector<int>> &ans)
{
    if(idx == nums.size()-1)
    {
        ans.push_back(nums);
        return;
    }

    for(int i = idx;i < nums.size(); i++)
    {
        swap(nums[idx],nums[i]);
        permutations(nums,idx+1,ans);
        swap(nums[idx],nums[i]);
    }

    return;
}

vector<vector<int>> permute(vector<int>& nums) 
{
    vector<vector<int>> result;
    permutations(nums,0,result);

    return result;
}

int main()
{
    vector<int> v = {1,2,3};

    for(int i = 0 ; i < permute(v).size(); i++)
    {
        for(int j = 0 ; j < permute(v)[i].size(); j++ )
        {
            cout<<permute(v)[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}