/*
Question - Maximum Bags With Full Capacity of Rocks

Link - https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/
*/

#include <bits/stdc++.h>
using namespace std;

int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) 
{
    int n = capacity.size();
    int result = 0;
    vector<int> diff;

    for(int i = 0; i < n; i++)
    {
        diff.push_back(capacity[i]-rocks[i]);
    }

    sort(diff.begin(),diff.end());

    for(int i = 0; i < n; i++)
    {
        if(diff[i] <=  additionalRocks)
        {
            result++;
            additionalRocks -= diff[i];
        }
    }
    return result;
}

int main()
{
    return 0;
}