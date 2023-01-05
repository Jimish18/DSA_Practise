/*
Question - Minimum Number Of Arrows To Burst Balloons

Link - https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
*/

#include <bits/stdc++.h>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points) 
{
    int n = points.size();
    if(n == 1) return n;
    
    sort(points.begin(),points.end());
    vector<vector<int>> result;
    result.push_back(points[0]);

    for(int i = 1; i < n; i++)
    {
        if(result.back()[1] >= points[i][0])
        {
            result.back()[0] = max(result.back()[0],points[i][0]);
            result.back()[1] = min(result.back()[1],points[i][1]);
        }
        else
        {
            result.push_back(points[i]);
        }
    }   

    return result.size();     
}

int main()
{
    return 0;
}