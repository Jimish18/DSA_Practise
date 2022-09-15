/*
Question - Max Points On Line

Link - https://leetcode.com/problems/max-points-on-a-line/
*/

#include <bits/stdc++.h>
using namespace std;

void maxPoints(vector<vector<int>>& points) 
{
    unordered_map<double,int> umap;

    for(int i = 0 ; i < points.size(); i++)
    {
        for(int j = 0 ; j < points.size(); j++)
        {
            if(i == j)
            {
                continue;
            }
            else
            {
                int y = points[j][1] - points[i][1];
                int x = points[j][0] - points[i][0];

                double slop = (double)(y)/x;
                cout<<slop<<endl;
            }
        }
    }    

    
}



int main()
{
    vector<vector<int>> points =  {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    // {{1,1},{2,2},{3,3}}
    maxPoints(points);
    return 0;
}
