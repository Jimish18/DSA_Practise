/*
Question - 4Sum

Link - https://leetcode.com/problems/4sum/
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<int>> fourSum(vector<int>& nums, int target) 
{
    vector<vector<int>> result;
    int n = nums.size();

    if(n == 0)
    {
        return result;
    }     

    sort(nums.begin(),nums.end());   

    for(int i = 0; i < n; i++)
    {
        ll target3 = target - nums[i];

        for(int j = i+1; j < n; j++)
        {
            ll target2 = target3 - nums[j];

            int front = j+1;
            int back = n-1;

            while(front < back)
            {
                ll twoSum = nums[front] + nums[back];

                if(twoSum < target2) front++;
                else if(twoSum > target2) back--;
                else
                {
                    vector<int> quad(4,0);
                    quad[0] = nums[i];
                    quad[1] = nums[j];
                    quad[2] = nums[front];
                    quad[3] = nums[back];

                    result.push_back(quad);

                    while((front < back) && quad[2] == nums[front]) ++front;

                    while((front < back) && quad[3] == nums[back]) --back;
                }
            }

            while((j+1 < n) && nums[j+1] == nums[j]) ++j; 
        }

        while((i+1 < n) && nums[i+1] == nums[i]) ++i;
    }

    return result;
}

// Two Pointer (Brute Force Approach) - TLE
// vector<vector<int>> fourSum(vector<int>& nums, int target) 
// {
//     vector<vector<int>> result;
//     set<vector<int>> st;
//     int n = nums.size();
//     int  k , l ;

//     sort(nums.begin(),nums.end());
//     for(int i = 0 ; i < n-3; i++)
//     {
//         for(int j = i+1 ; j < n-2 ; j++)
//         {
//             k = j+1;
//             l = n - 1;
            
//             while(k < l)
//             {
//                 ll tempSum = nums[i]+nums[j]+nums[k]+nums[l];
//                 if( tempSum == target)
//                 {
//                     vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
//                     st.insert(temp);
//                     k++;
//                     l--;
//                 }
//                 else if(tempSum < target)
//                 {
//                     k++;
//                 }
//                 else
//                 {
//                     l--;
//                 }
//             }
//         }
//     }    

//     for(auto i : st)
//     {
//         result.push_back(i);
//     } 

//     st.clear();

//     return result;   
// }

int main()
{
    vector<int> v = {2,2,2,2,2};
    // {1,0,-1,0,-2,2} 0
    // {2,2,2,2,2} 8
    int target = 8;

    vector<vector<int>> pair = fourSum(v,target);

    for(int i = 0 ; i < pair.size(); i++)
    {
        for(int j = 0 ; j < pair[i].size(); j++)
        {
            cout<<pair[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
