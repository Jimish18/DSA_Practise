/*
Question - Count Negative Number In Sorted Matrix

Link - https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
*/

#include <bits/stdc++.h>
using namespace std;

int countNegatives(vector<vector<int>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;

    for(int i = 0 ; i < n ; i++)
    {
        int s = 0;
        int e = m-1;
        int m ;

        while(s <= e)
        {
            m = s + (e-s)/2;

            if(grid[i][m] < 0) e = m-1;
            else if ( grid[i][m] > 0) s = m+1;
        }

        count += (m-e-1);
    }     

    return count;   
}

int main()
{
    return 0;
}