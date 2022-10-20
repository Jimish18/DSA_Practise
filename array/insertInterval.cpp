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
    vector<vector<int>> temp;

    for(auto in : intervals)
    {
        if(in[1] < newInterval[0])
        {
            temp.push_back(in);
        }
        else if(newInterval[1] < in[0])
        {
            temp.push_back(newInterval);
            newInterval = in;
        }
        else
        {
            newInterval[0] = min(in[0],newInterval[0]);
            newInterval[1] = max(in[1],newInterval[1]);
        }
    }

    temp.push_back(newInterval);
    intervals.clear();

    for(auto x : temp)
    {
        intervals.push_back(x);
    }

    temp.clear();
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