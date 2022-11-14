/*
Question - K Closest Points to Origin

Link - https://leetcode.com/problems/k-closest-points-to-origin/
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
{
    priority_queue<pair<double,int>> maxH;        
    vector<vector<int>> result;
    int n = points.size();
    
    for(int i = 0; i < n ; i++)
    {
        double d = sqrt(pow(points[i][0],2) + pow(points[i][1],2));

        maxH.push({d,i});

        if(maxH.size() > k)
        {
            maxH.pop();
        }
    }

    while(!maxH.empty())
    {
        result.push_back(points[maxH.top().second]);
        maxH.pop();
    }

    return result;
}

int main()
{   

    return 0;
}