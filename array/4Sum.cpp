/*
Question - 4Sum

Link - https://leetcode.com/problems/4sum/
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) 
{
    vector<vector<int>> result;
    set<vector<int>> st;
    int n = nums.size();
    int  k , l ;

    sort(nums.begin(),nums.end());
    for(int i = 0 ; i < n-3; i++)
    {
        for(int j = i+1 ; j < n-2 ; j++)
        {
            k = j+1;
            l = n - 1;
            
            while(k < l)
            {
                if(nums[i]+nums[j]+nums[k]+nums[l] == target)
                {
                    vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                    st.insert(temp);
                    k++;
                    l--;
                }
                else if(nums[i]+nums[j]+nums[k]+nums[l] < target)
                {
                    k++;
                }
                else
                {
                    l--;
                }
            }
        }
    }    

    for(auto i : st)
    {
        result.push_back(i);
    } 

    st.clear();

    return result;   
}

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
