/*
Question - sum of even numbers after queries

Link - https://leetcode.com/problems/sum-of-even-numbers-after-queries/
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) 
{
    vector<int> result;
    int evenSum = 0;

    for(int i = 0 ; i < nums.size(); i++)
    {
        if(nums[i]%2 == 0)
        {
            evenSum += nums[i];
        }
    }

    for(int i = 0; i < queries.size(); i++)
    {
        int prevVal = nums[queries[i][1]];
        int newVal = nums[queries[i][1]] + queries[i][0];
        nums[queries[i][1]] = newVal;
        if(newVal%2 == 0 && prevVal%2 == 0)
        {            
            evenSum -= prevVal;
            evenSum += newVal;
            result.push_back(evenSum);
        }
        else if(newVal%2 == 0 && prevVal%2 != 0)
        {
            evenSum += newVal;
            result.push_back(evenSum);
        }
        else if(newVal%2 != 0 && prevVal%2 == 0)
        {
            evenSum -= prevVal;
            result.push_back(evenSum);
        }
        else
        {
            result.push_back(evenSum);
        }        
        
    }

    return result;
}

int main()
{
    vector<vector<int>> queries = {{4,0}};
    vector<int> nums = {1};
    vector<int> evenSumResult = sumEvenAfterQueries(nums,queries);

    // {{1,0},{-3,1},{-4,0},{2,3}} {1,2,3,4}

    for(int i = 0 ; i < evenSumResult.size(); i++)
    {
        cout<<evenSumResult[i]<<" ";
    }
    cout<<endl;
    return 0;
}