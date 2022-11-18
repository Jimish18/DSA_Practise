/*
Question - Combination Sum II

Link - https://leetcode.com/problems/combination-sum-ii/
*/

#include <bits/stdc++.h>
using namespace std;


// Brute Force Recursion (Using Extra Space)
// void addCombinations(vector<int> &candidates,vector<int> &ds,set<vector<int>> &st,int target,int index)
// {
//     if(index == candidates.size())
//     {
//         if(target == 0)
//         {
//             vector<int> temp = ds;
//             sort(temp.begin(),temp.end());
//             st.insert(temp);
//         }
//         return;
//     }

//     if(candidates[index] <= target)
//     {
//         ds.push_back(candidates[index]);
//         addCombinations(candidates,ds,st,(target-candidates[index]),index+1);
//         ds.pop_back();
//     }

//     addCombinations(candidates,ds,st,target,index+1);
// }

// vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
// {
//     vector<vector<int>> result;
//     vector<int> ds;
//     set<vector<int>> st;

//     addCombinations(candidates,ds,st,target,0);    

//     for(auto x : st)
//     {
//         result.push_back(x);
//     }

//     return result;
// }

// Optimized Approach
void addCombinations(int index,int target,vector<vector<int>> &result,vector<int> &ds,vector<int> candidates)
{
    if(target == 0)
    {
        result.push_back(ds);
        return ;
    }

    for(int i = index; i < candidates.size(); i++)
    {
        if(i != index && candidates[i] == candidates[i-1]) continue;
        if(candidates[i] > target) break;
        ds.push_back(candidates[i]);
        addCombinations(i+1,(target-candidates[i]),result,ds,candidates);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
{
    sort(candidates.begin(),candidates.end());

    vector<vector<int>> result;
    vector<int> ds;

    addCombinations(0,target,result,ds,candidates);

    return result;
}

int main()
{
    vector<int> v = {2,5,2,1,2};
    // 2,5,2,1,2      5
    // 10,1,2,7,6,1,5      8
    int target = 5;
    vector<vector<int>> result = combinationSum2(v,target);

    for(int i = 0 ; i < result.size(); i++)
    {
        for(int j = 0 ; j < result[i].size(); j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}