/*
Question - Rotate Image

Link - https://leetcode.com/problems/rotate-image/
*/

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) 
{
    int n = matrix.size()-1;

    for(int i = 0 ; i <= n; i++)
    {
        int j = n-i;
        while(j >= 0)
        {
            // cout<<matrix[i][j]<<"->"<<matrix[j][n-i]<<endl;
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n-j][i];
            matrix[n-j][i] = temp;
            j--;
        }
    }    
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    // {{1,2,3},{4,5,6},{7,8,9}}
    // {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}}
    for(int i = 0 ; i < matrix.size(); i++)
    {
        for(int j = 0 ; j < matrix[i].size(); j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"After Rotation : "<<endl;

    rotate(matrix);

    for(int i = 0 ; i < matrix.size(); i++)
    {
        for(int j = 0 ; j < matrix[i].size(); j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}