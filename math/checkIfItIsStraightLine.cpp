/*
Question - Check If It Is a Straight Line

Link - https://leetcode.com/problems/check-if-it-is-a-straight-line/
*/

#include <bits/stdc++.h>
using namespace std;

bool checkStraightLine(vector<vector<int>>& coordinates) 
{
    int n = coordinates.size();

    if(n == 2) return true;

    for(int i = 2 ; i < n; i++)
    {
        double slp1 = (double)(coordinates[1][1]-coordinates[0][1])/(coordinates[1][0]-coordinates[0][0]);
        int temp1 = (coordinates[1][0]-coordinates[0][0]);
        double slp2 = (double)(coordinates[i][1]-coordinates[i-1][1])/(coordinates[i][0]-coordinates[i-1][0]);
        int temp2 = (coordinates[i][0]-coordinates[i-1][0]);
        
        if(temp1 == 0 && temp2 == 0) continue;

        if(slp1 != slp2) return false;
    }     

    return true;   
}

int main()
{
    return 0;
}