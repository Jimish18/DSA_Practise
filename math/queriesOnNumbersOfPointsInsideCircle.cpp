/*
Question - 

Link - https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/
*/

#include <bits/stdc++.h>
using namespace std;


vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) 
{
    vector<int> result;

    int n = queries.size();
    int m = points.size();

    for(int i = 0 ; i < n; i++)
    {
        int count = 0;

        for(int j = 0 ; j < m ; j++)
        {
            if((pow((points[j][0] - queries[i][0]),2) + pow((points[j][1] - queries[i][1]),2)) <= pow(queries[i][2],2))
            {
                count++;
            }
        }

        result.push_back(count);
    }       

    return result; 
}

int main()
{
    vector<vector<int>> points = {{1,3},{3,3},{5,3},{2,2}};
    vector<vector<int>> quries = {{2,3,1},{4,3,1},{1,1,2}};

    vector<int> result = countPoints(points,quries);

    for(int i = 0 ; i < result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}