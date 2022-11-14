/*
Question - Find Kth Largest XOR Coordinate Value

Link - https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/
*/

#include <bits/stdc++.h>
using namespace std;

int kthLargestValue(vector<vector<int>>& matrix, int k) 
{
    int i,j;
    priority_queue<int,vector<int>,greater<int>> minH;
    int n = matrix.size();
    int m = matrix[0].size();

    for(i = 0; i < n;i++)
    {
        for(j = 1 ; j < m; j++)
        {
            matrix[i][j] = matrix[i][j-1]^matrix[i][j];
        }
    }   

    for(i = 0; i < m; i++)
    {
        for(j = 1 ; j < n; j++)
        {
            matrix[j][i] = matrix[j-1][i]^matrix[j][i];
        }
    }   

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(minH.size() < k)
            {
                minH.push(matrix[i][j]);
            }
            else
            {
                if(matrix[i][j] > minH.top())
                {
                    minH.pop();
                    minH.push(matrix[i][j]);
                }
            }
        }
    }  

    return minH.top();
}


int main()
{
    return 0;
}