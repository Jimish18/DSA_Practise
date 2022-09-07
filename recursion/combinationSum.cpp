/*
Question - Combination Sum

Link - https://leetcode.com/problems/combination-sum/
*/

#include <bits/stdc++.h>
using namespace std;

void findCombinationSum(int index ,int target,vector<vector<int>> &vv,vector<int> &v,vector<int> &array)
{
    if(index == array.size())
    {
        if(target == 0)
        {
            vv.push_back(v);
        }
        return;
    }

    // Pick Condition 
    if(array[index] <= target)
    {
        v.push_back(array[index]);
        findCombinationSum(index,(target-array[index]),vv,v,array);
        v.pop_back();
    }

    // not pick condition
    findCombinationSum(index+1,target,vv,v,array);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
{
    vector<vector<int>> ans ;
    vector<int> ds;
    findCombinationSum(0,target,ans,ds,candidates);

    return ans;
}

int main()
{
    vector<int> v = {2,3,6,7};
    for(int i = 0 ; i < combinationSum(v,7).size(); i++)
    {
        for(int j = 0; j < combinationSum(v,7)[i].size(); j++)
        {
            cout<<combinationSum(v,7)[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}