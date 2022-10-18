/*
Question - Merge Intervals

Link - https://leetcode.com/problems/merge-intervals/
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
    if(intervals.size() == 1)
    {
        return intervals;
    }

    sort(intervals.begin(),intervals.end());
    int n = intervals.size();
    int lower = intervals[0][0];
    int upper = intervals[0][1];
    vector<vector<int>> result;

    for(int i = 1 ; i < n; i++)
    {
        if(intervals[i][0] > upper)
        {
            result.push_back({lower,upper});
            lower = intervals[i][0];
            upper = intervals[i][1];
        }
        else
        {
            lower = min(lower,intervals[i][0]);
            upper = max(upper,intervals[i][1]);
        }

        if(i == n-1)
        {
            result.push_back({lower,upper});
        }
    }   

    return result;   

}

int main()
{   vector<vector<int>> v = {{1,4},{4,5}};
    // {2,6},{1,3},{8,10},{15,18}

    vector<vector<int>> result = merge(v);

    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0 ; j < result[i].size(); j++ )
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}