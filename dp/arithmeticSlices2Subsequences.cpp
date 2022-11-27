/*
Question - Arithmetic Slices II - Subsequence

Link - https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
*/

#include <bits/stdc++.h>
using namespace std;

int numberOfArithmeticSlices(vector<int>& nums) 
{
    int count = 0;
    int n = nums.size();
    vector<unordered_map<long long,long long>> vmap(n);

    for(int i = 1; i < n; i++)
    {        
        for(int j = 0; j < i; j++)
        {
            long long cd = (long long)nums[j]-nums[i];
            if(vmap[j].find(cd) != vmap[j].end())
            {
                count += vmap[j][cd];
                vmap[i][cd] += vmap[j][cd]+1;
            }
            else
            {
                vmap[i][cd]++;
            }
        }
    }

    return count;        
}


int main()
{
    return 0;
}