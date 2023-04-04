/*
Question - Convert an Array Into a 2D Array With Conditions

Link - https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>& nums , vector<vector<int>> &result , unordered_set<int> &st, vector<int> &temp,vector<bool> &visited,int index)
{
    if(index >= nums.size())
    {
        result.push_back(temp);
        st.clear();
        temp.clear();
    }

    if(!visited[index])
    {
        if(st.find(nums[index]) == st.end())
        {
            temp.push_back(nums[index]);
            visited[index] = true;
            st.insert(nums[index]);
        }

        dfs(nums,result,st,temp,visited,index+1);
    }

}

vector<vector<int>> findMatrix(vector<int>& nums) 
{
    vector<vector<int>> result;
    unordered_set<int> st;    
    vector<int> temp;
    int n = nums.size();
    vector<bool> visited(n,false);

    for(int i = 0 ; i < n ; i++)
    {
       if(!visited[i]) dfs(nums,result,st,temp,visited,i); 
    }    

    return result;

}


int main()
{
    return 0;
}