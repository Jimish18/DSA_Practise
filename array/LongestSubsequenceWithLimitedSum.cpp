/*
Question - Longest Subsequence With Limited Sum

Link - https://leetcode.com/problems/longest-subsequence-with-limited-sum/
*/

#include <bits/stdc++.h>
using namespace std;

// Time - O(MN + N(logN)) Space - O(m+n)
vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
{
    int n = nums.size();
    int m = queries.size();
    vector<int> result(m);
    vector<long long> preFix(n);

    sort(nums.begin(),nums.end());
    long long sum = 0;

    preFix[0] = nums[0];
    for(int i = 1; i < n; i++)
    {
        preFix[i] = preFix[i-1] + nums[i];
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(preFix[j] == queries[i])
            {
                result[i] = j+1;
                break;
            }
            else if(preFix[j] > queries[i])
            {
                result[i] = j;
                break;
            }
            else if(j == n-1)
            {
                result[i] = j+1;
            }
        }
    }

    return result;
}

int main()
{
    vector<int> nums = {4,5,2,1};
    vector<int> queries = {3,10,21};
    return 0;
}