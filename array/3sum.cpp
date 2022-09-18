/*
Question - 3Sum

Link - https://leetcode.com/problems/3sum/
*/


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) 
{
    vector<vector<int>> result;
    set<vector<int>> st;

    sort(nums.begin(),nums.end());
    int n = nums.size();
    int i = 0 ;
    int j = n-1;
    int k;

    for(int i = 0 ; i < n-2 ; i++)
    { 
        k = i+1;
        j = n-1;
        while(k < j)
        {
            if(nums[i] + nums[j] + nums[k] == 0)
            {
                vector<int> temp = {nums[i],nums[k],nums[j]};
                st.insert(temp);
                k++;
                j--;              
            }
            else if(nums[i] + nums[k] + nums[j] < 0)
            {               
                k++;               
            }
            else
            {
                j--;
            }
        }
    }

    for(auto i : st)
    {
        result.push_back(i);
    }    

    return result;                                
}


int main()
{
    vector<int> v = {-1,0,1,2,-1,4};
    // {0,0,0,0}
    // {0,1,1}
    // {0,0,0}
    // {-1,0,1,2,-1,4}
    // {-2,0,1,1,2}

    vector<vector<int>> triplets = threeSum(v);

    for(int i = 0 ; i < triplets.size(); i++)
    {
        for(int j = 0 ; j < triplets[i].size(); j++)
        {
            cout<<triplets[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}