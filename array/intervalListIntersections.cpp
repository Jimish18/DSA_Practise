/*
Question - Interval List Intersections

Link - https://leetcode.com/problems/interval-list-intersections/
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) 
{
    int n = firstList.size();
    int m = secondList.size();
    vector<vector<int>> result;
    int i = 0, j = 0;

    while(i < n && j < m)
    {
        int lower = max(firstList[i][0],secondList[j][0]);
        int upper = min(firstList[i][1],secondList[j][1]);

        if(lower <= upper) result.push_back({lower,upper});
        if(firstList[i][1] < secondList[j][1]) i++;
        else j++;
    }

    return result;
}

int main()
{
    return 0;
}