/*
Question - Insert Interval

Link - https://leetcode.com/problems/insert-interval/
*/

#include <bits/stdc++.h>
using namespace std;

// TLE 
// vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
// {
//     intervals.insert(intervals.begin(),newInterval);

//     sort(intervals.begin(),intervals.end());
//     int pointer = 0;
//     int i = 1;

//     while(i < intervals.size())
//     {
//         if(intervals[pointer][1] < intervals[i][0])
//         {
//             pointer++;
//         }
//         else
//         {
//             intervals[pointer][1] = max(intervals[pointer][1],intervals[i][1]);
//             intervals.erase(intervals.begin()+i);
//             continue;
//         }
//         i++;
//     }

//     return intervals;
// }

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
{
    int n = intervals.size();

    if(n == 0)
    {
        intervals.insert(intervals.begin(),newInterval);
        return intervals;
    }
    int i;
    for(i = 1 ; i < n; i++)
    {
        if(newInterval[0] < intervals[i][0])
        {
            intervals.insert(intervals.begin()+i,newInterval);
            break;
        }
        if(i == n-1)
        {
            intervals.insert(intervals.end(),newInterval);
            return intervals;
        }
    }
    --i;
    int pointer = i;
    while(i < intervals.size())
    {
        if(intervals[pointer][1] < intervals[i][0])
        {
            pointer++;
        }
        else
        {
            intervals[pointer][1] = max(intervals[pointer][1],intervals[i][1]);
            if(pointer != i)
            {
                intervals.erase(intervals.begin()+i);
                continue;
            }
        }
        i++;
    }

    return intervals;
}

int main()
{
    vector<vector<int>> v =  {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> target = {4,8};
    // {{1,3},{6,9}} -> {2,5}
    vector<vector<int>> result = insert(v,target);

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