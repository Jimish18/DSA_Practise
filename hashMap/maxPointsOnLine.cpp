/*
Question - Max Points On Line

Link - https://leetcode.com/problems/max-points-on-a-line/
*/

#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<vector<int>>& points) 
{
    int n = points.size();
    if(n <= 2)
    {
        return n;
    }

    int maxPointsOnLine = 2;

    for(int i = 0 ; i < n; i++)
    {
        for(int j = i+1 ; j < n; j++)
        {             
            int total = 2;
            for(int k = 0 ; k < n ; k++)
            {
                if(k != i && k != j)
                {
                    if((points[i][1]-points[j][1])*(points[i][0]-points[k][0]) == (points[i][1] - points[k][1])*(points[i][0]-points[j][0]))
                    {
                        total++;
                    }
                }
            }

            maxPointsOnLine = max(maxPointsOnLine,total);
           
        }
    }  

    return maxPointsOnLine;
    
}



int main()
{
    vector<vector<int>> points =  {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    // {{1,1},{2,2},{3,3}}
    // {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}}
    cout<<maxPoints(points)<<endl;
    return 0;
}
